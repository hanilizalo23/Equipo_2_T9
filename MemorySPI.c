/**
 * Created on: 17/04/2022
 * Author: Mauricio Peralta
 * @file    MemorySPI.c
 * @brief   Control Memory SPI communication from FRDM-K64F.
 */

#include "MemorySPI.h"


void SPI_Memory_Init(void)
{
	dspi_master_config_t masterConfig;
	uint32_t srcClock_Hz;

	CLOCK_EnableClock(kCLOCK_PortC);
	PORT_SetPinMux(PORTC, PIN3_IDX, kPORT_MuxAlt2);

	masterConfig.whichCtar                                = kDSPI_Ctar1;
	masterConfig.ctarConfig.baudRate                      = TRANSFER_BAUDRATE_MEM;
	masterConfig.ctarConfig.bitsPerFrame                  = BITS_FRAME;
	masterConfig.ctarConfig.cpol                          = kDSPI_ClockPolarityActiveLow;
	masterConfig.ctarConfig.cpha                          = kDSPI_ClockPhaseSecondEdge;
	masterConfig.ctarConfig.direction                     = kDSPI_MsbFirst;
	masterConfig.ctarConfig.pcsToSckDelayInNanoSec        = TRANSFER_DELAY_MEM / TRANSFER_BAUDRATE_MEM;
	masterConfig.ctarConfig.lastSckToPcsDelayInNanoSec    = TRANSFER_DELAY_MEM / TRANSFER_BAUDRATE_MEM;
	masterConfig.ctarConfig.betweenTransferDelayInNanoSec = TRANSFER_DELAY_MEM / TRANSFER_BAUDRATE_MEM;

	masterConfig.whichPcs           = kDSPI_Pcs1;
	masterConfig.pcsActiveHighOrLow = kDSPI_PcsActiveLow;

	masterConfig.enableContinuousSCK        = false;
	masterConfig.enableRxFifoOverWrite      = false;
	masterConfig.enableModifiedTimingFormat = false;
	masterConfig.samplePoint                = kDSPI_SckToSin0Clock;

	srcClock_Hz = DSPI0_CLK_SRC;
	DSPI_MasterInit(SPI0, &masterConfig, srcClock_Hz);

	return;
}
