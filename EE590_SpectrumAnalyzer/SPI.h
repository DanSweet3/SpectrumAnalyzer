/*******************************************************************************
 * SPI.h
 * Spectrum Analyzer EE590 Final Project
 *
 * Version: v1.0
 *
 * Description: Header file for SPI process in the Raspberry Pi Spectrum
 *      Analyzer project.
 *
 * Created by Daniel Sweet on 5/20/16.
 * Copyright © 2016 Daniel Sweet. All rights reserved.
 *
 ******************************************************************************/

#ifndef SPI_h
#define SPI_h

#include "main.h"
#include <stdio.h>

// DEFINES
// SPI Process will end if no SPI Communication is seen in TIMEOUT_US (usec)
#define SPI_TIMEOUT_US          650000

// VARIABLES


// FUNCTION PROTOTYPES
void SPI_Init(void);
void SPI_Process(void);
void SPI_Stop(void);

#endif /* SPI_h */
