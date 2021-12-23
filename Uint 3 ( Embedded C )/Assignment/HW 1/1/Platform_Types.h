/*
 ============================================================================
 Name        : Platform_Types.h
 Author      : Aya Sayed
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#ifndef _PLATFORM_TYPES_H
#define _PLATFORM_TYPES_H
#endif


#ifndef FALSE
#define FALSE
#endif

#ifndef TRUE
#define TRUE
#endif



#ifndef _STDINT_H
#define _STDINT_H

typedef signed char		    int8_t;
typedef unsigned char		uint8_t;
typedef short		    	int16_t;
typedef unsigned short		uint16_t;
typedef int			        int32_t;
typedef unsigned	     	uint32_t;
typedef long long	    	int64_t;
typedef unsigned long long	uint64_t;

#endif


typedef _Bool               boolean;
typedef int8_t              sint8;
typedef uint8_t             uint8;
typedef int16_t             sint16;
typedef uint16_t            uint16;
typedef int32_t             sint32;
typedef uint32_t            uint32;
typedef int64_t             sint64;
typedef uint64_t            uint64;


typedef volatile int8_t     vint8_t;
typedef volatile uint8_t    vuint8_t;

typedef volatile int16_t    vint16_t;
typedef volatile uint16_t   vuint16_t;

typedef volatile int32_t    vint32_t;
typedef volatile uint32_t   vuint32_t;

typedef volatile int64_t    vint64_t;
typedef volatile uint64_t   vuint64_t;
