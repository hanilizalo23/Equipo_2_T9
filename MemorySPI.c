/**
 * Created on: 17/04/2022
 * Author: Mauricio Peralta
 * @file    MemorySPI.c
 * @brief   Control Memory SPI communication from FRDM-K64F.
 */

#include "MemorySPI.h"

#define IMAGE_SIZE	(504U)

static uint8_t g_rxData;
static uint8_t g_sendData[504];
static uint8_t g_readDataCmd = 0x03;
static uint8_t g_instrAddr[MEM_DATA];

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

void send_to_memory(uint32_t address)
{
	uint8_t upperAddress;
	uint8_t lowerAddress;
	uint32_t x;

	for(x = 0; x < IMAGE_SIZE; x++)
	{
		upperAddress = address >> RIGHT_SHIFTER_8;
		lowerAddress = (address & LOWER_BYTE);

		g_instrAddr[0] = g_readDataCmd;
		g_instrAddr[1] = 0; //This is the start of the addresses in the memory at 0x0000
		g_instrAddr[2] = upperAddress;
		g_instrAddr[3] = lowerAddress;

		memory_half_duplex_init(g_instrAddr);

		g_sendData[x] = g_rxData;

		address++;
	}

	LCD_nokia_bitmap(g_sendData, IMAGE_SIZE);

	return;
}

void memory_half_duplex_init(const uint8_t data[])
{}
