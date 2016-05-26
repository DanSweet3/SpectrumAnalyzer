/*******************************************************************************
 * SPI.c
 * Spectrum Analyzer EE590 Final Project
 *
 * Version: v1.0
 *
 * Description: This file implements the SPI processing for the Raspberry Pi 
 *      Spectrum Analyzer project. The bcm2835.h SPI library implementation is 
 *      used.
 *
 *      This process collects data via SPI from the external PSoC 5 ADC by 
 *      polling the DATA_READY GPIO. Whenever the DATA_READY line is high, new
 *      ADC samples are in the PSoC 5 buffer and are ready to be collected. 
 *
 *      This process can enable/disable ADC data collection via the ADC_ENABLE
 *      GPIO. 
 *
 *      A total of FFT_LEN bytes (defined in main.h) control how many bytes this 
 *      process collects before sending the block of data to the FFT process.
 *
 * Created by Daniel Sweet on 5/20/16.
 * Copyright © 2016 Daniel Sweet. All rights reserved.
 *
 ******************************************************************************/

#include "SPI.h"

// Variables
uint8_t spi_data_ready;
uint8_t read_data;
int16_t temp_data;
uint8_t send_data = 0x00;
uint16_t i = 0;

uint16_t spi_timeout = 0;
uint16_t len = 0;

// Local Function Prototypes
void SPI_Print_RAW(void);

/*******************************************************************************
 * Function: SPI_Init
 *
 * Description: Initializes the SPI process. Configures flow control pins and 
 *      sets up SPI hardware via the BCM2835 SPI library. Enables the external
 *      ADC and flushes the first 2 (garbage) bytes from SPI slave.
 *
 * Arguments: None
 *
 * Returns: None
 *
 * Notes: Uses <bcm2835.h> library
 *
 ******************************************************************************/
void SPI_Init(void)
{
    // SPI Flow Control Pin Setup
    bcm2835_gpio_fsel(SPI_READY, BCM2835_GPIO_FSEL_INPT);
    bcm2835_gpio_fsel(ADC_ENABLE, BCM2835_GPIO_FSEL_OUTP);
    
    // Initialize SPI Hardware
    bcm2835_spi_begin();
    bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);      // The default
    bcm2835_spi_setDataMode(BCM2835_SPI_MODE0);                   // The default
    bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_64);    // %64 = ~4MHz
    bcm2835_spi_chipSelect(BCM2835_SPI_CS0);                      // The default
    bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, LOW);      // the default
    
    // Enable Sampling System
    bcm2835_gpio_write(ADC_ENABLE, HIGH);
    
    // Flush Initial bytes from slave (theese are not saved)
    read_data = bcm2835_spi_transfer(send_data);
    read_data = bcm2835_spi_transfer(send_data);
}

/*******************************************************************************
 * Function: SPI_Process
 *
 * Description: Main function for handling SPI communication with the external
 *      ADC. Performs the following key functions:
 *      1. Reads 16-bits of data (2 8-bit reads) every time it sees the
 *      data_ready GPIO is high. 
 *      2. Saves FFT_LEN bytes in a buffer
 *      3. Sends collected bytes via pipe to the FFT process.
 *
 * Arguments: None
 *
 * Returns: None
 *
 * Notes: Process will timeout if ADC is unresponsive.
 *
 ******************************************************************************/
void SPI_Process(void)
{
    // If Data Ready Line is High, Read more data
    spi_data_ready = bcm2835_gpio_lev(SPI_READY);
    if(spi_data_ready)
    {
        //Always read 2 bytes, slave is configured to be 16-bit
        read_data = bcm2835_spi_transfer(send_data);
        temp_data = (int16_t)read_data<<8;
        read_data = bcm2835_spi_transfer(send_data);
        temp_data |= (int16_t)read_data;
        read_data_array[i] = temp_data;
        i++;
        
        // Need quick delay otherwise Pi is too fast and may try to read another
        //  byte before ADC can set data_ready line low
        bcm2835_delayMicroseconds(1);
        
        // Reset Timeout
        spi_timeout = 0;
        
        if(i >= FFT_LEN)
        {
            if(PRINT_IPC_DEBUG)
            {
                printf("\n-- SPI Process(%d):Writing %d bytes to FFT Process\n",
                       pid, (int)sizeof(read_data_array));
            }
            // Print raw receieved SPI data to file (if enabled)
            SPI_Print_RAW();
            
            //Send new data to FFT Process
            len = write(fd[P3_WRITE], read_data_array, sizeof(read_data_array));
            if (len < 0)
            {
                perror("SPI Process: Failed to write response value");
                exit(EXIT_FAILURE);
            }
            if(PRINT_IPC_DEBUG)
            {
                printf("!!!Sent %d bytes to FFT Process\n", len);
            }
            i = 0;
        }
    }
    else
    {
        // Check for timeout, timeout after SPI_TIMEOUT_US tries
        spi_timeout++;
        bcm2835_delayMicroseconds(1);
        // Timeout after 65000 tries
        assert(spi_timeout < SPI_TIMEOUT_US);
    }

}

/*******************************************************************************
 * Function: SPI_Stop
 *
 * Description: Shuts down SPI related hardware when SPI process shuts down.
 *      Ensures ADC_ENABLE GPIO is low so the ADC does not continually sample.
 *      Stops SPI hardware via bcm2835 library API
 *
 * Arguments: None
 *
 * Returns: None
 *
 * Notes:
 *
 ******************************************************************************/
void SPI_Stop(void)
{
    //Disable Sampling System
    bcm2835_gpio_write(ADC_ENABLE, LOW);
    
    bcm2835_spi_end();
    bcm2835_close();
}

/*******************************************************************************
 * Function: SPI_Print_RAW
 *
 * Description: Optional print debug function that will print the raw received
 *      data blocks to a text file.
 *
 * Arguments: None
 *
 * Returns: None
 *
 * Notes: Enabled when PRINT_SPI_RAW_DATA is set to '1' in main.h
 *
 ******************************************************************************/
void SPI_Print_RAW(void)
{
#if (PRINT_SPI_RAW_DATA)
    uint16_t idx;
    
    // PRINT RAW SPI DATA TO FILE
    FILE * fp;
    
    fp = fopen ("SPIRaw.txt", "w+");
    for(idx = 0; idx < FFT_LEN; idx++)
    {
        fprintf(fp, "%04X\n", read_data_array[idx]);
    }
    fclose(fp);
#endif
}
