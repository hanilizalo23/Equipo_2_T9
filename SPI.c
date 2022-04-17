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
	
	masterConfig.whichCtar                                = kDSPI_Ctar0;
	masterConfig.ctarConfig.baudRate                      = TRANSFER_BAUDRATE;
	masterConfig.ctarConfig.bitsPerFrame                  = BITS_FRAME;
	masterConfig.ctarConfig.cpol                          = kDSPI_ClockPolarityActiveHigh;
	masterConfig.ctarConfig.cpha                          = kDSPI_ClockPhaseFirstEdge;
	masterConfig.ctarConfig.direction                     = kDSPI_MsbFirst;
	masterConfig.ctarConfig.pcsToSckDelayInNanoSec        = TRANSFER_DELAY / TRANSFER_BAUDRATE;
	masterConfig.ctarConfig.lastSckToPcsDelayInNanoSec    = TRANSFER_DELAY / TRANSFER_BAUDRATE;
	masterConfig.ctarConfig.betweenTransferDelayInNanoSec = TRANSFER_DELAY / TRANSFER_BAUDRATE;

	masterConfig.whichPcs           = kDSPI_Pcs0;
	masterConfig.pcsActiveHighOrLow = kDSPI_PcsActiveLow;

	masterConfig.enableContinuousSCK        = false;
	masterConfig.enableRxFifoOverWrite      = false;
	masterConfig.enableModifiedTimingFormat = false;
	masterConfig.samplePoint                = kDSPI_SckToSin0Clock;

	srcClock_Hz = DSPI0_CLK_SRC;
	DSPI_MasterInit(SPI0, &masterConfig, srcClock_Hz);

	return;
}
