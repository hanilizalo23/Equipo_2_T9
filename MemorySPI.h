/**
 * Created on: 17/04/2022
 * Author: Mauricio Peralta
 * @file    MemorySPI.h
 * @brief   Control Memory SPI communication from FRDM-K64F.
 */

#ifndef MEMORYSPI_H_
#define MEMORYSPI_H_

#include "fsl_debug_console.h"
#include "fsl_gpio.h"
#include "fsl_dspi.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"
#include "LCD_nokia.h"
#include "SPI.h"

#define MEM_DATA			(4U)
#define UPPER_BYTE			(0xFF00)


//2 MHz Transmission
#define TRANSFER_BAUDRATE_MEM	(2000000U)
#define TRANSFER_DELAY_MEM	 	(1000000000U)

void SPI_Memory_Init(void);

void send_to_memory(uint32_t address);

void memory_half_duplex_init(const uint8_t data[]);

#endif /* MEMORYSPI_H_ */
