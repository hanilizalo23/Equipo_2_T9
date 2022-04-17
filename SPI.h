/**
 * Created on: 17/04/2022
 * Author: Nelida Hernández
 * @file    SPI.h
 * @brief   Configure SPI to communicate with Nokia_LCD peripheral.
 */

#ifndef SPI_H_
#define SPI_H_

#include "SPI.h"
#include "fsl_dspi.h"
#include "fsl_port.h"
#include "fsl_gpio.h"
#include "fsl_clock.h"
#include "clock_config.h"

#define PIN0_IDX  0u
#define PIN1_IDX  1u
#define PIN2_IDX  2u
#define PIN3_IDX  3u
#define PIN16_IDX 16u
#define PIN17_IDX 17u

#define BITS_FRAME 8

//1 MHz Transmission
#define TRANSFER_DELAY	  1000000000U
#define TRANSFER_SIZE     64U
#define TRANSFER_BAUDRATE 1000000U

void SPI_Init(void);

#endif /* SPI_H_ */
