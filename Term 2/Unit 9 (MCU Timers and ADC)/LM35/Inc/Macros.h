/*
 * Macros.h
 *
 * Created: 3/26/2022 5:37:36 AM
 *  Author: Aya Sayed
 */ 


#ifndef MACROS_H_
#define MACROS_H_


#define SET_BIT(REG, BIT_NUM)          (REG |= (1<<BIT_NUM))                             // set bit in reg.
#define CLEAR_BIT(REG, BIT_NUM)        (REG &= (~(1<<BIT_NUM)))                          // clear bit in reg.
#define TOGGLE_BIT(REG, BIT_NUM)       (REG ^= (1<<BIT_NUM))                             // toggle bit in reg.
#define ROR(REG, BIT_NUM)              (REG = (REG >> BIT_NUM) | (REG << (8 - BIT_NUM))) // rotate bits right in reg.
#define ROL(REG, BIT_NUM)              (REG = (REG << BIT_NUM) | (REG >> (8 - BIT_NUM))) // rotate bits left in reg.
#define BIT_IS_SET(REG, BIT_NUM)       (REG & (1<<BIT_NUM))                              // check if bit is set
#define BIT_IS_CLEAR(REG, BIT_NUM)     (!(REG & (1<<BIT_NUM)))                           // check if bit is clear
#define READ_BIT(REG, BIT_NUM)         ((REG & (1<<BIT_NUM)) >>BIT_NUM)


/***************************** @Ref Mechanism_define ***************************/
enum Mechanism{
	Polling_Mechanism_DIS=0,
	Polling_Mechanism_EN
};


/*
   printf("File :%s\n", __FILE__ );	// This contains the current filename as a string literal.
   printf("Date :%s\n", __DATE__ );	// The current date as a character literal in "MMM DD YYYY" format.
   printf("Time :%s\n", __TIME__ );	// The current time as a character literal in "HH:MM:SS" format.
   printf("Line :%d\n", __LINE__ );	// This contains the current line number as a decimal constant.
   printf("ANSI :%d\n", __STDC__ );	// Defined as 1 when the compiler complies with the ANSI standard.
*/


#endif /* MACROS_H_ */