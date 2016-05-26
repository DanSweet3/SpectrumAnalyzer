/*******************************************************************************
 *  main.c
 * Spectrum Analyzer EE590 Final Project
 *
 * Version: v0.1
 *
 * Description: Configures the SPI and sends NUM_BYTES of data repeatedly.
 *  This program is intended to be used with the SPI in loopback mode,
 *  where MOSI and MISO are shorted.
 *
 * Also computes CPU time, total time, % CPU usage and average SPI data rate
 *
 * Created by Daniel Sweet on 4/21/16.
 * Copyright © 2016 Daniel Sweet. All rights reserved.
 *
 ******************************************************************************/
#include "main.h"

// FFT Variables
fftw_complex out[FFT_LEN];
fftw_plan p;
int16_t read_data_array[FFT_LEN];

// Process Communication Variables
int enabled = 1;
int fd[2*NUM_PIPES];
pid_t pid;

/*******************************************************************************
 * Function: Sig_Handler
 *
 * Description: Signal handler function. Intended to handle 2 main types of 
 *  signals:
 *     1. SIGUSR1 - Comes from parent process to disable children processes
 *                   gracefully.
 *     2. SIGABRT - Added to allow processes to disable gracefull if an assert
 *                   occurs.
 *
 * Arguments: signo - Signal Number, provided by Linux signal library
 *
 * Returns: None
 *
 * Notes: Requires use of <signal.h>
 *
 ******************************************************************************/
void Sig_Handler(int signo)
{
    if(signo == SIGUSR1)
    {
        printf("Process %d Received SIGUSR1\n", getpid());
        enabled = 0;
    }
    else if(signo == SIGABRT)
    {
        printf("Process %d Received SIGABRT\n", getpid());
        enabled = 0;
    }
    else
    {
        printf("Unknown Signal Received\n");
    }
}

/*******************************************************************************
 * Function: GetTime
 *
 * Description: For profiling, gets the current actual time with ns resolution.
 *
 * Arguments: None
 *
 * Returns: Double representing current time with nanosecond resolution.
 *
 * Notes: Requires use of <time.h>
 *
 ******************************************************************************/
struct timespec ts1;
double GetTime(void)
{
    clock_gettime(CLOCK_REALTIME, &ts1);
    return ts1.tv_sec + ts1.tv_nsec / 1e9;
}

/*******************************************************************************
 * Function: main
 *
 * Description: Main processing function for Spectrum Analyzer project.
 *   This function manages the creation of 3 child processes:
 *      1. SPI Process - Handles SPI Input from external ADC via SPI
 *      2. FFT Process - Performs FFT function on block data collected from ADC
 *      3. Display Process - Plots output of FFT on HDMI using OpenVG
 *
 * Arguments: int argc, const char* argv[] - Both currently unused
 *
 * Returns: (int) Program completion status
 *
 * Notes:
 *
 ******************************************************************************/
int main(int argc, const char * argv[])
{
    int i;
    pid_t FFT_pid, SPI_pid, GRAPH_pid;
    
    // Initialize BCM2835 Library
    if (!bcm2835_init())
    {
        perror("bcm2835_init failed. Are you running as root??\n");
        return 1;
    }
    
    //Set up SIGINT handler
    if (signal(SIGUSR1, Sig_Handler) == SIG_ERR)
    {
        perror("\ncan't catch SIGUSR1\n");
    }
    //Set up SIGABRT handler (for assert)
    if (signal(SIGABRT, Sig_Handler) == SIG_ERR)
    {
        perror("\ncan't catch SIGABRT\n");
    }
    
    // Create all the descriptor pairs we need for IPC
    for (i=0; i<NUM_PIPES; ++i)
    {
        if (pipe(fd+(i*2)) < 0)
        {
            perror("Failed to allocate pipes");
            exit(EXIT_FAILURE);
        }
    }
    
    // Start forking 3 main processes (SPI, FFT, DISPLAY)
    
    //////////////////////////////////
    // CHILD PROCESS - FFT FUNCTION //
    //////////////////////////////////
    
    // fork() returns 0 for child process, child-pid for parent process.
    if ((pid = fork()) < 0)
    {
        perror("Failed to fork process");
        return EXIT_FAILURE;
    }
    
    // if the pid is zero, this is the child process - FFT PROCESS
    if (pid == 0)
    {
        // Start by closing descriptors we don't need in this process
        close(fd[P1_READ]);
        close(fd[P3_WRITE]);
        
        // Used for output
        pid = getpid();
        
        // Do one time setup of FFT structure
        p = FFT_Init();
        
        while(enabled)
        {
            FFT_Process(p);
        }
        // This process has been disabled, shut it down
        printf("FFT Process (%d): Shutting Down\n", pid);
        
        // Clean up FFT Structure
        fftw_destroy_plan(p);
        
        // finished. close remaining descriptors.
        close(fd[P2_READ]);
        close(fd[P2_WRITE]);
        
        return EXIT_SUCCESS;
    }
    
    //This is parent process, save FFT pid for later
    FFT_pid = pid;
    
    //////////////////////////////////
    // CHILD PROCESS - SPI FUNCTION //
    //////////////////////////////////
    //Repeat for SPI Process
    // fork() returns 0 for child process, child-pid for parent process.
    if ((pid = fork()) < 0)
    {
        perror("Failed to fork process");
        return EXIT_FAILURE;
    }

    // If the pid is zero, this is the child process - SPI PROCESS
    if (pid == 0)
    {
        // Close unneeded descriptors
        close(fd[P1_READ]);
        close(fd[P2_READ]);
        close(fd[P2_WRITE]);
        
        // Initialize SPI Process
        SPI_Init();
        
        // used for output
        pid = getpid();
        
        while(enabled)
        {
            SPI_Process();
        }
        // Process has been disabled, shut it down
        printf("SPI Process (%d): Shutting Down\n", pid);
        SPI_Stop();
        close(fd[P3_WRITE]);
        return EXIT_SUCCESS;
    }
    
    //This is parent process, save SPI pid for later and spawn another process
    SPI_pid = pid;

    //////////////////////////////////////
    // CHILD PROCESS - DISPLAY FUNCTION //
    //////////////////////////////////////
    //Repeat for Display Process
    // fork() returns 0 for child process, child-pid for parent process.
    if ((pid = fork()) < 0)
    {
        perror("Failed to fork process");
        return EXIT_FAILURE;
    }
    
    // If the pid is zero, this is the child process - DISPLAY PROCESS
    if(pid == 0)
    {
        // Close unneeded descriptors
        close(fd[P2_READ]);
        close(fd[P2_WRITE]);
        close(fd[P3_WRITE]);
        
        // used for output
        pid = getpid();
        
        // Initialize Display
        Display_Start();
        
        while(enabled)
        {
            // Run Display Process
            Display_Process();
        }
        printf("GRAPH Process (%d): Shutting Down\n", pid);
        Display_Stop();
        // close down remaining descriptors
        close(fd[P1_READ]);
    }
    
    // This is the parent process, Monitor STDIN and wait for RETURN to kill children and
    //  exit program.
    GRAPH_pid = pid;                        // Save pid for Graph process

    /////////////////////////////////////
    // PARENT PROCESS - INPUT FUNCTION //
    /////////////////////////////////////
    
    char s[3];
    fgets(s, 2, stdin);                     // Wait for [RETURN]
    
    // Send signal to 3 children to shut them down
    kill(SPI_pid,SIGUSR1);
    kill(FFT_pid,SIGUSR1);
    kill(GRAPH_pid,SIGUSR1);
    
    // wait for child termination
    wait(NULL);
    
    return EXIT_SUCCESS;
}
