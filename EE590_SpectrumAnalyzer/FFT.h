//
//  FFT.h
//  EE590_SpectrumAnalyzer
//
//  Created by Daniel Sweet on 5/21/16.
//  Copyright © 2016 Daniel Sweet. All rights reserved.
//

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
