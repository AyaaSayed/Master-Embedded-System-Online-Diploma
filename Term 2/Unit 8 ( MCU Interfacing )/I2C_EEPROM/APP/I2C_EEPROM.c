/*
 * I2C_EEPROM.c
 *
 *  Created on: Apr 2, 2022
 *      Author: diesel
 *
 *******************************************************************************
                                     Includes
*******************************************************************************/
#include "I2C_EEPROM.h"

void I2C_EEPROM(void)
{
	/* Initialization of EEPROM */
	HAL_EEPROM_Init();

	/************************ Test Case 1 ************************/
	uint8_t Ch1[7] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07};
	uint8_t Ch2[7] = {0};

	HAL_EEPROM_Write_NBytes(0xAF, Ch1, 7);
	HAL_EEPROM_Read_NBytes (0xAF, Ch2, 7);

	/************************ Test Case 2 ************************/
	Ch1[0] = 0xA;
	Ch1[1] = 0xB;
	Ch1[2] = 0xC;
	Ch1[3] = 0xD;

	HAL_EEPROM_Write_NBytes(0xFFF, Ch1, 4);
	HAL_EEPROM_Read_NBytes (0xFFF, Ch2, 4);

	/* Loop For Ever */
	while(1);
}
