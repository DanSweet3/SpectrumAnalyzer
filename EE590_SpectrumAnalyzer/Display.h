//
//  Display.h
//  EE590_SpectrumAnalyzer
//
//  Created by Daniel Sweet on 5/16/16.
//  Copyright © 2016 Daniel Sweet. All rights reserved.
//

#ifndef Display_h
#define Display_h

#include "main.h"

// Standard Library Includes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

// OpenVG Includes
#include "VG/openvg.h"
#include "VG/vgu.h"
#include "fontinfo.h"
#include "shapes.h"

// Other Includes

// DEFINES
#define GRAPH_TYPE          1           //0 = BAR, 1 = Polyline - Do not use BAR!

// Constants for drawing image
#define SCREEN_SIZE_X       1920
#define SCREEN_SIZE_Y       1080
#define MARGIN_SIZE         100

#define GRAPH_SIZE_X        (SCREEN_SIZE_X-MARGIN_SIZE)
#define GRAPH_SIZE_Y        (SCREEN_SIZE_Y-MARGIN_SIZE)

#define BAR_ELEMENTS        256
#define BAR_WIDTH           (GRAPH_SIZE_X/BAR_ELEMENTS)
#define Y_OFFSET            250
#define X_AXIS              (MARGIN_SIZE/2)
#define Y_AXIS              (MARGIN_SIZE/2)
#define Y_GRAPH_DB          7

// Display FFT Filter and Update Rate
#define IIR_OLD_WEIGHT      (0.8)
#define IIR_NEW_WEIGHT      (0.2)
#define DISPLAY_UPDATE_RATE (0.25)           //seconds
#define DISPLAY_WAIT_CNT    ((DISPLAY_UPDATE_RATE*SAMPLE_FREQ)/FFT_LEN)


// FUNCTION PROTOTYPES
void Display_Start(void);
void Display_Process(void);
void Display_Clear(void);
void Display_Stop(void);

#endif /* Display_h */
