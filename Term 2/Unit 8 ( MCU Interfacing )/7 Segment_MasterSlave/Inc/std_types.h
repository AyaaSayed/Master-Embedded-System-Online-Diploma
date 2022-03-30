/*
 * STD_TYPES.h
 *
 * Created: 3/19/2022 1:28:29 AM
 *  Author: Aya Sayed
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/* Types */
typedef unsigned char          uint8;
typedef signed char            sint8;
typedef unsigned short int     uint16;
typedef signed short int       sint16;
typedef unsigned long          uint32;
typedef signed long            sint32;
typedef unsigned long long     uint64;
typedef signed long long       sint64;
typedef float                  float32;
typedef double                 float64;


/* Boolean */

#define  HIGH (1u)
#define  LOW  (0u)


#ifndef TRUE
#define TRUE (1u)
#endif

#ifndef FALSE
#define FALSE (0u)
#endif



#ifndef NULL
#define NULL (void*)(0)
#endif


#endif /* STD_TYPES_H_ */