/**
 * Created on: 17/04/2022
 * Author: Nelida Hernández
 * @file    SPI.c
 * @brief   Configure SPI to communicate with Nokia_LCD peripheral.
 */

#include "SPI.h"

void SPI_Init(void)
{
	dspi_master_config_t masterConfig;
	uint32_t srcClock_Hz;

	CLOCK_SetSimSafeDivs();

	CLOCK_EnableClock(kCLOCK_PortD);
	PORT_SetPinMux(PORTD,PIN0_IDX,kPORT_MuxAlt2);
	PORT_SetPinMux(PORTD,PIN1_IDX,kPORT_MuxAlt2);
	PORT_SetPinMux(PORTD,PIN2_IDX,kPORT_MuxAlt2);
	PORT_SetPinMux(PORTD,PIN3_IDX,kPORT_MuxAlt2);

	srcClock_Hz = DSPI0_CLK_SRC;
	DSPI_MasterInit(SPI0, &masterConfig, srcClock_Hz);

	return;
}
