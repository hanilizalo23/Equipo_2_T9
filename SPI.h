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

void SPI_Init(void);

#endif /* SPI_H_ */
