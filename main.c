/**
	\file 
	\brief 
		This is a starter file to use the Nokia 5110 LCD.
		The LCD is connected as follows:
		RST-PDT5
		CE-PTD0
		DC-PTD4
		DIN-PTD2
		CLK-PTD1
 * Created on: 17/04/2022
 * Author: Nelida Paulina Hernández Moya & Mauricio Peralta
 * @file    main.c
 * @brief   Main function to call LCD functions and read images from high speed memory SPI FRDM-K64F.
 */
 
#include "LCD_nokia.h"
#include "LCD_nokia_images.h"
#include "stdint.h"
#include "SPI.h"
#include "MemorySPI.h"
#include "Delay.h"

#define DELAY_FOR_VISUALIZATION		(1000U)
extern const uint8_t ITESO[504]; //Permitted

int main(void)
{
	//Strings to be printed in the LCD
	uint8_t string_1[]="ITESO";
	uint8_t string_2[]="Queremos";
	uint8_t string_3[]="pasar SEBMI";
	uint8_t string_4[]="Nely y Mau";
	uint8_t string_5[]= "P2022";

	SPI_Init(); //It configures the clocks and initialization pins of both SPIs
	SPI_Memory_Init(); //It configures the clocks and parameters to be send to the SPI to control the memory
	LCD_nokia_init(); //Configuration function for the LCD

	while(1)
	{
		LCD_nokia_clear(); //It clears the information printed in the LCD
		LCD_nokia_bitmap(ITESO, 504); //It prints an array that hold an image, in this case is the initial picture
		delay(DELAY_FOR_VISUALIZATION);

		//Nothing between first image and strings
		LCD_nokia_clear();
		delay(DELAY_FOR_VISUALIZATION);
		LCD_nokia_clear();

		LCD_nokia_goto_xy(20,0); //It establishes the position to print the messages in the LCD
		LCD_nokia_send_string(&string_1[0]); //It print a string stored in an array
		delay(DELAY_FOR_VISUALIZATION); //Little pause

		LCD_nokia_goto_xy(12,1);
		LCD_nokia_send_string(string_2);
		delay(DELAY_FOR_VISUALIZATION);

		LCD_nokia_goto_xy(8,2);
		LCD_nokia_send_string(string_3);
		delay(DELAY_FOR_VISUALIZATION);

		LCD_nokia_goto_xy(10,3);
		LCD_nokia_send_string(string_4);
		delay(DELAY_FOR_VISUALIZATION);

		LCD_nokia_goto_xy(24,4);
		LCD_nokia_send_string(string_5);
		delay(DELAY_FOR_VISUALIZATION);

		LCD_nokia_clear();
		send_to_memory(bitmap_1); //Printing the images in the SPI memory
		delay(DELAY_FOR_VISUALIZATION);

		LCD_nokia_clear();
		send_to_memory(bitmap_2);
		delay(DELAY_FOR_VISUALIZATION);

		LCD_nokia_clear();
		send_to_memory(bitmap_3);
		delay(DELAY_FOR_VISUALIZATION);

		LCD_nokia_clear();
		send_to_memory(bitmap_4);
		delay(DELAY_FOR_VISUALIZATION);

		LCD_nokia_clear();
		send_to_memory(bitmap_5);
		delay(DELAY_FOR_VISUALIZATION);
	}
	return 0;
}
