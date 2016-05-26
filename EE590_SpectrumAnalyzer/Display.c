//
//  Display.c
//  EE590_SpectrumAnalyzer
//
//  Created by Daniel Sweet on 5/16/16.
//  Copyright © 2016 Daniel Sweet. All rights reserved.
//



/*******************************************************************************
 *  Display.c
 * OpenVG Test
 *
 * Version: v0.1
 *
 * Description: Program to test the capabilities of the OpenVG library. This
 *  program draws a bar graph to emulate what an FFT graph might look like.
 *
 * Simulated FFT data provided in DummyData.c/.h. This is random data generated
 *  in MATLAB.
 *
 * Also computes CPU time, total time, % CPU usage and provides GPIO debug
 *  outputs for profiling.
 *
 * Created by Daniel Sweet on 4/21/16.
 * Copyright © 2016 Daniel Sweet. All rights reserved.
 *
 ******************************************************************************/

#include "Display.h"

// LOCAL PROTOTYPES
double Calc_Power(double re, double im);
void Display_Stats(VGfloat max);
void Display_Graph(int16_t bin_start, int16_t bin_end, fftw_complex *data);

// VARIABLES
int width, height;
uint32_t DisplayCount = 0;

/*******************************************************************************
 * Function: Display_Start
 *
 * Description: Starts the resources needed by the Display Process. 
 *      1. Enables Display Active debug GPIO
 *      2. Enables OpenVG library
 *      3. Prints basic display related statistics
 *
 * Arguments: None
 *
 * Returns: None
 *
 * Notes: Requires use of OpenVG library.
 *
 ******************************************************************************/
void Display_Start(void)
{
    bcm2835_gpio_fsel(DISPLAY_ACTIVE_PIN, BCM2835_GPIO_FSEL_OUTP);
    
    // Initialize OpenVG Library
    init(&width, &height);                  // Graphics Init, gets size of canvas
    Start(width, height);                   // Start the picture
    
    
    printf("\n -- DISPLAY STATS \n");
    printf("Display Spacing: %d \n", DISPLAY_SPACING);
    printf("Display every N: %d \n", (int)DISPLAY_WAIT_CNT);
}

/*******************************************************************************
 * Function: Display_Clear
 *
 * Description: Clears the display and redraws the background axis, grid and labels
 *
 * Arguments: None
 *
 * Returns: None
 *
 * Notes: Needs to be called befor each new display update
 *
 ******************************************************************************/
void Display_Clear(void)
{
    int b = (GRAPH_SIZE_X/DISPLAY_LEN);                 // X spacing, per point
    int g = b*DISPLAY_SPACING-b;                        // Grid spacing
    int i;
    char str[10];
    
    // Clear Display
    Background(0, 0, 0);                                // Black background
     
    //Draw an X and Y Axis Lines
    StrokeWidth(2);
    Stroke(255,255,255,1);
    Line(X_AXIS-2,Y_AXIS-2,X_AXIS-2+GRAPH_SIZE_X,Y_AXIS-2); //Draw X_AXIS Line
    Line(X_AXIS-2,Y_AXIS-2,X_AXIS-2,Y_AXIS-2+GRAPH_SIZE_Y); //Draw Y_AXIS Line
    
    // Label X-Axis Units
    Fill(255, 255, 255, 1);                 // White text
    TextMid(width / 2, height / 50, "frequency (kHz)", SerifTypeface, width / 150);
    // Label Y-Axis Units
    Text(MARGIN_SIZE/10, height / 2+20, "dBV", SerifTypeface, width / 150);
    
    // Draw Grid
    StrokeWidth(1);
    Stroke(128,128,128,1);                              // Grey
    // Vertical Grid and Labels
    for(i = 1; i<=DISPLAY_SPACING; i++)
    {
        // Grids
        Line(X_AXIS+b/2+i*g,
             Y_AXIS-20,
             X_AXIS+b/2+i*g,
             Y_AXIS-2+GRAPH_SIZE_Y); // Draw Vertical
        // Labels
        sprintf(str, "%d", i);
        TextMid(X_AXIS-2+i*g, height/150, str, SerifTypeface, width/150);
    }
    // Horizontal Grid
    g = GRAPH_SIZE_Y/10;
    for(i = 1; i<=10; i++)
    {
        Line(X_AXIS-2,
             Y_AXIS-2+i*g,
             X_AXIS-2+GRAPH_SIZE_X,
             Y_AXIS-2+i*g);          // Draw Horizontal
        sprintf(str, "%d", -5*Y_GRAPH_DB+(i*Y_GRAPH_DB));
        Text(MARGIN_SIZE/6, Y_AXIS-2+i*g, str, SerifTypeface, width/150);
    }
}

/*******************************************************************************
 * Function: Display_Stop
 *
 * Description: Shuts down OpenVG related display tasks
 *
 * Arguments: None
 *
 * Returns: None
 *
 * Notes:
 *
 ******************************************************************************/
void Display_Stop(void)
{
    finish();                               // OpenVG Graphics cleanup
}

/*******************************************************************************
 * Function: Display_Graph
 *
 * Description: Draws new set of data onto the HDMI connected display. Performs
 *      several key tasks:
 *      1. Times how long the process takes (GPIO toggles & time.h)
 *      2. Averages several FFT results between each display cycle. Display update
 *          rate set by DISPLAY_UPDATE_RATE in Display.h
 *      3. When DISPLAY_UPDATE_RATE has elapsed, calls Display_Clear and draws
 *          new set of FFT information to display. Each sample is passed to 
 *          Calc_Power to convert raw FFT data into magnitude (dB).
 *      4. Calls Display_Stats() to print basic statistics overlay
 *
 * Arguments: int16_t bin_start - starting point in data to start graphing from
 *            int16_t bin_end - ending point in data to stop graphing
 *            fftw_complex *data - fft output data. A subset of this output is 
 *              typically drawn, set by bin_start and bin_end.
 *
 * Returns:
 *
 * Notes:
 *
 ******************************************************************************/
void Display_Graph(int16_t bin_start, int16_t bin_end, fftw_complex *data)
{
    // Timing Variables
    clock_t dis_cpu_time_start;
    double dis_total_time_start = 0.0;
    double dis_cpu_time = 0.0;
    double dis_total_time = 0.0;
    double dis_cpu_utilization = 0.0;
    
    int16_t x;
    int16_t w;
    int16_t len = bin_end - bin_start;
    
    // Check input parameters
    assert(data != NULL);
    assert(bin_start >= 0);
    assert(bin_end < FFT_LEN);
    
    // Enable Profiling Debug Pin
    bcm2835_gpio_write(DISPLAY_ACTIVE_PIN, HIGH);
    
    // Get starting times for profiling
    dis_cpu_time_start = clock();
    dis_total_time_start = GetTime();
    
    x = bin_start;
    w = GRAPH_SIZE_X/len;
    
#if(GRAPH_TYPE == 0)        //Bar Graph (DEBUG ONLY, DO NOT USE!)
    Display_Clear();
    StrokeWidth(1);
    Stroke(0,0,0,1);
    Fill(44, 77, 232, 1);   //Blue
    // Draw dummy data similar to an FFT graph
    for(x = bin_start; x < bin_end; x++)
    {
        Rect(X_AXIS+x*w,
             Y_AXIS,
             w,
             Y_OFFSET+10*Calc_Power(data[x][0],data[x][1]));
    }
    End();                                  // End the picture
#else                       // Polyline Graph
    static VGfloat x_pts[DISPLAY_LEN];
    static VGfloat y_pts[DISPLAY_LEN];
    int idx = 0;
    
    VGfloat max_x, max_y = 0.0;
    
    // Update Running average each time
    for(x = bin_start; x < bin_end; x++)
    {
        x_pts[idx] = (X_AXIS+x*w);
        y_pts[idx] =(IIR_OLD_WEIGHT)*y_pts[idx] +
                (IIR_NEW_WEIGHT)*(Y_OFFSET+5*Calc_Power(data[x][0],data[x][1]));
        
        // Look for maximum
        if(y_pts[idx] > max_y)
        {
            max_y = y_pts[idx];
            max_x = idx*(double)SAMPLE_FREQ/(double)FFT_LEN;
        }
        
        idx++;
    }
    // DO NOT UPDATE DISPLAY EVERY TIME
    if(DisplayCount >= DISPLAY_WAIT_CNT)
    {
        DisplayCount = 0;
        // Clear data from last cycle
        Display_Clear();
        
        Stroke(44, 77, 232, 1); //Blue
        StrokeWidth(2);
        // OpenVG appears to have a bug if too many points are passed to Polyline at once
        Polyline(x_pts, y_pts, len/2);
        Polyline(&x_pts[len/2-1], &y_pts[len/2-1], len/2);
        
        Display_Stats(max_x);
        
        // Call OpenVG End(), this displays picture
        End();
        
    }
    else
    {
        DisplayCount++;
    }
    
#endif
    
    //End Profiling Timers
    dis_total_time = GetTime() - dis_total_time_start;
    dis_cpu_time = (double)(clock() - dis_cpu_time_start)/(double)CLOCKS_PER_SEC;
    dis_cpu_utilization = dis_cpu_time / dis_total_time * 100.0;
    
    if(PRINT_DISPLAY_TIMING)
    {
        printf("--DISPLAY TIMING--  ");
        printf("Total Time %7.4f, CPU Time %7.4f, CPU Util %3.0f percent\n",
               dis_total_time, dis_cpu_time, dis_cpu_utilization);
    }
    
    // Disable Profiling Debug Pin
    bcm2835_gpio_write(DISPLAY_ACTIVE_PIN, LOW);
}

/*******************************************************************************
 * Function: Display_Process
 *
 * Description: Handles basic display process functionality, called from main. 
 *      Primary functionality is to wait for new data to arrive from FFT process
 *      and then call Display_Graph()
 *
 * Arguments:   None
 *
 * Returns: None
 *
 * Notes: Waits until data has been received from FFT function, so this function
 *      will automatically be slaved to the output rate of the FFT function.
 *
 ******************************************************************************/
void Display_Process(void)
{
    int32_t read_len = 0;
    
    // WAIT FOR FFT DATA before doing anything else
    //len = read(fd[P1_READ], out, sizeof(out));
    read_len = read(fd[P1_READ], out, sizeof(out));
    if (read_len < 0)
    {
        perror("Display Process: failed to read value from pipe");
        exit(EXIT_FAILURE);
    }
    else if (read_len == 0)
    {
        // not an error, but certainly unexpected
        fprintf(stderr, "Display Process(%d): Read EOF from pipe", pid);
    }
    else
    {
        // Graph Received FFT data
        if(PRINT_IPC_DEBUG)
        {
            printf("--Graph Processs(%d): Graphing FFT \n", pid);
        }
        // Display FFT Results
        Display_Graph(0,DISPLAY_LEN-1,out);
    }
}

/*******************************************************************************
 * Function: Display_Stats
 *
 * Description: Overlays some basic stats onto FFT graph.
 *
 * Arguments: VGfloat max - maximum frequency (collected by FFT_Grap())
 *
 * Returns: None
 *
 * Notes: Draws to HDMI output display
 *
 ******************************************************************************/
void Display_Stats(VGfloat max)
{
    char str[20];
    // Display Maximum Stats
    StrokeWidth(1);
    Fill(255,255,0,1);          // Yellow
    
    //MAX
    sprintf(str, "Max F: %d Hz",(int)max );
    TextMid((width*9)/10, (height*9)/10, str, SerifTypeface, width/100);
    
    //SAMPLE RATE
    sprintf(str, "Sample Rate: %d Hz",SAMPLE_FREQ);
    TextMid((width*1)/10, (height - MARGIN_SIZE/3), str, SerifTypeface, width/125);
    
    //FFT RESOLUTION
    sprintf(str, "FFT Resolution: %d Hz",F_STEP);
    TextMid((width*5)/10, (height - MARGIN_SIZE/3), str, SerifTypeface, width/125);
}

/*******************************************************************************
 * Function: Calc_Power
 *
 * Description: Converts raw real / imaginary pair output from FFT function into
 *      a graphable magnitude in dB.
 *
 * Arguments: double re - real part of sample
 *            double im - imaginary part of sample
 *
 * Returns: double - result in dB
 *
 * Notes: Requires use of <math.h> library
 *
 ******************************************************************************/
double Calc_Power(double re, double im)
{
    return 20*log10(sqrt(re*re+im*im));
}
