//
//  main.h
//  EE590_SpectrumAnalyzer
//
//  Created by Daniel Sweet on 5/16/16.
//  Copyright © 2016 Daniel Sweet. All rights reserved.
//

#ifndef main_h
#define main_h

// STANDARD INCLUDES
#include <stdio.h>
#include <time.h>
#include <assert.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>

// PROJECT LIBRARY INCLUDES
#include <bcm2835.h>
#include <fftw3.h>

// LOCAL PROJECT INCLUDES
#include "SPI.h"
#include "FFT.h"
#include "Display.h"

// DEBUG PRINT DEFINES
# define PRINT_FFT_TIMING           0
# define PRINT_DISPLAY_TIMING       0
# define PRINT_FFT_INPUT            0
# define PRINT_FFT_OUTPUT           0
# define PRINT_SPI_RAW_DATA         0
# define PRINT_IPC_DEBUG            0

// ANALOG FRONT END DEFINES
#define SAMPLE_FREQ         52400         // (Hz) 51200 or 102400 normally
#define ADC_RESOLUTION      15            // 15 bits signed
#define ADC_COUNTS          32768
#define ADC_POS_COUNTS      (ADC_COUNTS/2)

// Convert Received ADC Sample to a Normalized (+/- 1.0) value for FFT
#define NORMALIZE_SAMPLE(x) ((double)x/(double)ADC_POS_COUNTS)

// FFT DEFINES
#define FFT_LEN             2048
#define F_STEP              (SAMPLE_FREQ/FFT_LEN)
#define DISPLAY_LEN         512
#define DISPLAY_F_STEP      (SAMPLE_FREQ/DISPLAY_LEN)
#define DISPLAY_SPACING     ((FFT_LEN/2)/F_STEP)

// PIN DEFINES
#define SPI_READY           RPI_V2_GPIO_P1_15           //GPIO22
#define ADC_ENABLE          RPI_V2_GPIO_P1_13           //GPIO27

#define FFT_ACTIVE_PIN      RPI_V2_GPIO_P1_37           //GPIO26
#define DISPLAY_ACTIVE_PIN  RPI_V2_GPIO_P1_35           //GPIO19

// IPC DEFINES (PIPES)
#define P1_READ     0               // DISPLAY Process (P1) Reads from P1_READ
#define P2_WRITE    1               // FFT Process (P2) Writes on P2_WRITE
#define P2_READ     2               // FFT Process (P2) Reads from P2_READ
#define P3_WRITE    3               // SPI Process (P3) Writes on P3_WRITE

#define NUM_PIPES   2               // Total # of pipe pairs we need

// GLOBAL VARIABLES
extern int16_t read_data_array[FFT_LEN];

// FFT Variables
extern fftw_complex out[FFT_LEN];
extern fftw_plan p;

// IPC Variables
extern int fd[2*NUM_PIPES];
extern pid_t pid;

// FUNCTION PROTOTYPES
double GetTime(void);

#endif /* main_h */
