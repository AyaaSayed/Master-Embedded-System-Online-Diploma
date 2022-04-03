/*
 * EEPROM.h
 *
 *  Created on: Apr 2, 2022
 *      Author: Aya Sayed
 */

#ifndef EEPROM_EEPROM_H_
#define EEPROM_EEPROM_H_
/*
 * EEPROM is an I2C Slave
 *
 * Idle Mode ================> The device is in high-Impedane state and waits for data.
 * Master Transmitter Mode ==> The device transmits data to a slave receiver.
 * Master Receiver Mode =====> The device receives data form a slave transmitter.
 */

/*******************************************************************************
                                     Includes
*******************************************************************************/
#include "I2C.h"

#define EEPROM_Slave_Address 		0x2A

/*******************************************************************************
                     APIs Supported by "HAL EEPROM DRIVER"
*******************************************************************************/
void HAL_EEPROM_Init(void);

void HAL_EEPROM_Write_NBytes(uint32_t Memory_Address, uint8_t *Byte, uint32_t Data_Length);
void HAL_EEPROM_Read_NBytes (uint32_t Memory_Address, uint8_t *Byte, uint32_t Data_Length);


#endif /* EEPROM_EEPROM_H_ */
