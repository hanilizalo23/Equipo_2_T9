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
#include "SPI.h"

void SPI_Memory_Init(void);


#endif /* MEMORYSPI_H_ */
