/******************************************************************************
 *
 * Module: Common - Platform Types Abstraction
 *
 * File Name: std_types.h
 *
 * Description: types for AVR
 *
 *  Author: Aya Sayed
 *
 *******************************************************************************/ 

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

// Boolean Values
#ifndef FALSE
#define FALSE       (0u)
#endif

#ifndef TRUE
#define TRUE        (1u)
#endif

#define HIGH        (1u)
#define LOW         (0u)

typedef unsigned char         uint8;          /*           0 .. 255             */
typedef char                  int8;           /*        -128 .. +127            */
typedef unsigned short        uint16;         /*           0 .. 65535           */
typedef short                 int16;          /*      -32768 .. +32767          */
typedef unsigned long         uint32;         /*           0 .. 4294967295      */
typedef long                  int32;          /* -2147483648 .. +2147483647     */
typedef unsigned long long    uint64;         /*       0..18446744073709551615  */
typedef long long             int64;
typedef float                 float32;
typedef double                float64;

#endif /* STD_TYPES_H_ */