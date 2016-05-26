/*******************************************************************************
 * FFT.h
 * Spectrum Analyzer EE590 Final Project
 *
 * Version: v1.0
 *
 * Description: Header file for FFT process in the Raspberry Pi Spectrum
 *      Analyzer project. 
 *
 * Created by Daniel Sweet on 5/16/16.
 * Copyright © 2016 Daniel Sweet. All rights reserved.
 *
 ******************************************************************************/

#ifndef FFT_h
#define FFT_h

#include <stdio.h>
#include "main.h"

// DEFINES

// VARIABLES

// FUNCTION PROTOTYPES
fftw_plan FFT_Init(void);
void FFT_Process(fftw_plan p);
void FFT_Print(void);


#endif /* FFT_h */
