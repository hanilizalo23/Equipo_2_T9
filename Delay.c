/*
 * Delay.c
 *
 *  Created on: 17/04/2022
 *      Author: Nelida Hernández
 */

#include "Delay.h"

void delay(uint32_t delay)
{
	volatile uint32_t i, j;

	for(i = delay; i > 0; i--)
	{
		for(j = delay; j > 0; j--)
		{
			__asm("nop");

		}
	}
}
