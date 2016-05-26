/*******************************************************************************
 * FFT.c
 * Spectrum Analyzer EE590 Final Project
 *
 * Version: v1.0
 *
 * Description: This file implements the FFT processing for the Raspberry Pi
 *      Spectrum analyzer project. The FFT processing is done using v3 of the 
 *      fftw library (fftw3.h).
 *
 *      This process receives a data block from the SPI process defined by
 *      FFT_LEN in main.h. It performs a 1D real FFT operation on this data and 
 *      the raw FFT output is passed to the display process.
 *
 * Created by Daniel Sweet on 5/21/16.
 * Copyright © 2016 Daniel Sweet. All rights reserved.
 *
 ******************************************************************************/

#include "FFT.h"
//#include "fft_data3.h"                    // This is test data, no longer used

//Variables
double in[FFT_LEN];

// Timing Variables
clock_t fft_cpu_time_start;
double fft_total_time_start = 0.0;
double fft_cpu_time = 0.0;
double fft_total_time = 0.0;
double fft_cpu_utilization = 0.0;

/*******************************************************************************
 * Function: FFT_Init
 *
 * Description: Initializes the FFT Process. Does 3 things:
 *      1. Prints some basic statistics the FFT process uses
 *      2. Starts FFT Active GPIO debug
 *      3. Sets up FFT 'plan' that is used in all future FFT calls. Plan is set
 *         up to use a 1-d real FFT of length specified by FFT_LEN.
 *
 * Arguments: None
 *
 * Returns: Configured FFTW plan
 *
 * Notes: A new fftw_plan would need to be set up if the system wants to use a 
 *          differeng FFT length.
 *
 ******************************************************************************/
fftw_plan FFT_Init(void)
{
    /////// FFT TEST /////
    printf("-- FFT Process(%d): Running FFT... \n", pid);
    printf("Sample Frequency: %d Hz\n", SAMPLE_FREQ);
    printf("FFT Length: %d bins\n", FFT_LEN);
    printf("FFT Resolution: %d Hz\n", F_STEP);
    printf("Display Length: %d bins\n", DISPLAY_LEN);
    printf("Display Resolution: %d Hz\n", DISPLAY_F_STEP);
    
    // Init Debug Pin for FFT
    bcm2835_gpio_fsel(FFT_ACTIVE_PIN, BCM2835_GPIO_FSEL_OUTP);
    
    // Lastly, set up FFTW plan for future FFT's
    return fftw_plan_dft_r2c_1d(FFT_LEN, in, out, FFTW_ESTIMATE);
}

/*******************************************************************************
 * Function: FFT_Process
 *
 * Description: Manages FFT Process. Performs 4 primary tasks:
 *      1. Profiles how much time this process requires (GPIO & CPU timing)
 *      2. Waits for new packet of data from SPI process
 *      3. Calls fftw_execute to perform FFT calculations on new block of data
 *      4. Sends FFT results via pipe to Display process
 *
 * Arguments: fftw_plan p - This is the FFT plan returned by FFT_Init, used by
 *      fftw_execute() when running FFT calculations
 *
 * Returns: None
 *
 * Notes: FFT_Process waits for data from SPI process before continuing
 *
 ******************************************************************************/
void FFT_Process(fftw_plan p)
{
    uint16_t idx = 0;
    uint16_t len = 0;
    
    // Enable Profiling Debug Pin
    bcm2835_gpio_write(FFT_ACTIVE_PIN, HIGH);
    
    // Wait for SPI Process to send new data
    len = read(fd[P2_READ], read_data_array, sizeof(read_data_array));
    if (len < 0)
    {
        perror("FFT Process: Failed to read data from pipe");
        exit(EXIT_FAILURE);
    }
    else if (len == 0)
    {
        // not an error, but certainly unexpected
        fprintf(stderr, "FFT Process: Read EOF from pipe");
    }
    else
    {
        // Get starting times for profiling
        fft_cpu_time_start = clock();
        fft_total_time_start = GetTime();
        
        if(PRINT_IPC_DEBUG)
        {
            printf("-- FFT Process(%d): Read %d bytes from SPI\n",pid,len);
        }
        // Process and Print FFT Data
        // Normalize and convert to float to prep for FFT
        for(idx = 0; idx < FFT_LEN; idx++)
        {
            in[idx] = NORMALIZE_SAMPLE(read_data_array[idx]);
        }
        
        // Execute FFT
        fftw_execute(p);
        
        // Print FFT Results (to file)
        FFT_Print();
        
        //End Profiling Timers
        fft_total_time = GetTime() - fft_total_time_start;
        fft_cpu_time = (double)(clock() - fft_cpu_time_start)/(double)CLOCKS_PER_SEC;
        fft_cpu_utilization = fft_cpu_time / fft_total_time * 100.0;
        
        if(PRINT_FFT_TIMING)
        {
            printf("--FFT TIMING--      ");
            printf("Total Time %7.4f, CPU Time %7.4f, CPU Util %3.0f percent\n",
                   fft_total_time, fft_cpu_time, fft_cpu_utilization);
        }
        // Disable Profiling Debug Pin
        bcm2835_gpio_write(FFT_ACTIVE_PIN, LOW);
        
        //SEND FFT to Graphing Process
        if(PRINT_IPC_DEBUG)
        {
            printf("-- FFT Process(%d): Sending %d bytes from FFT To Graph\n", pid, (int)sizeof(out));
        }
        if (write(fd[P2_WRITE], out, sizeof(out)) < 0)
        {
            perror("Child: Failed to write response value");
            exit(EXIT_FAILURE);
        }
    }
}

/*******************************************************************************
 * Function: FFT_Print
 *
 * Description: Optional debug printing function for FFT. Can print FFT input
 *      or output to a text file for viewing later. Only one FFT block of data
 *      is written to the file (the latest will be present).
 *
 * Arguments: None
 *
 * Returns: None
 *
 * Notes: INPUT/OUTPUT printing enabled with PRINT_FFT_OUTPUT and PRINT_FFT_INPUT
 *      in main.h
 *
 ******************************************************************************/
void FFT_Print(void)
{
#if (PRINT_FFT_OUTPUT || PRINT_FFT_INPUT)
    uint16_t i;
#endif
    
#if (PRINT_FFT_OUTPUT)
    // OUTPUT DATA TO FILE
    FILE * fp;

    fp = fopen ("FFToutput.txt", "w+");
    for(i=0; i < FFT_LEN/2+1; i++)
    {
        fprintf(fp, "%f\n", out[i][0]);
    }

    fclose(fp);

    fp = fopen ("FFToutput2.txt", "w+");
    for(i=0; i < FFT_LEN/2+1; i++)
    {
        fprintf(fp, "%f\n", out[i][1]);
    }
    fclose(fp);
#endif
#if (PRINT_FFT_INPUT)
    //INPUT DATA TO FILE
    FILE * fp;

    fp = fopen ("FFTinput.txt", "w+");
    for(i = 0; i < FFT_LEN; i++)
    {
        fprintf(fp, "%04X %f\n", read_data_array[i],in[i]);
    }

    fclose(fp);
#endif
}