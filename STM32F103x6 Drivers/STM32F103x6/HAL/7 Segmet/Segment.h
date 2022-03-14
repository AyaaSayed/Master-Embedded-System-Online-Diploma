/*
 * 7_Segment.h
 *
 *  Created on: Mar 9, 2022
 *      Author: diesel
 */

#ifndef SEGMENT_H_
#define SEGMENT_H_

#include "SegmentConfig.h"

/*******************************************************************************
                            Preprocessor Macros
 ******************************************************************************/
#define ZERO               0x01
#define ONE                0x79
#define TWO                0x24
#define THREE              0x30
#define FOUR               0x4C
#define FIVE               0x12
#define SIX                0x02
#define SEVEN              0x19
#define EIGHT              0x00
#define NINE               0x10


/*******************************************************************************
                  APIs Supported by "HAL 7 SEGMENT DRIVER"
*******************************************************************************/
void HAL_7_Segment_INIT();

#endif /* SEGMENT_H_ */

