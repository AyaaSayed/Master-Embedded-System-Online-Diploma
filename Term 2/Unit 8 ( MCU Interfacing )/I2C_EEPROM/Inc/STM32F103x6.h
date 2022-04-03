/*****************************************************************************
 *
 * Module: STM32F103x6
 *
 * File Name: STM32F103C6.h
 *
 * Description: File include all Microcontroller Addresses, Registers and Bits
 *
 * Author: Aya Sayed
 *
 ******************************************************************************/

#ifndef STM32F103X6_H_
#define STM32F103X6_H_

/*******************************************************************************
                                     Includes
*******************************************************************************/
#include <stdio.h>
#include <stdint.h>

/*******************************************************************************
                           Base addresses for Memories
*******************************************************************************/
#define SYSTEM_MEMORY_BASE                                        0x1FFFF000UL
#define Flash_MEMORY_BASE                                         0x08000000UL
#define SRAM_MEMORY_BASE                                          0x20000000UL
#define PERIPHERALS_BASE                                          0x40000000UL
#define CORTEX_M3_INTERNAL_PERIPHERALS_BASE                       0xE0000000UL

/*******************************************************************************
               Base addresses for Peripherals related with CORE
*******************************************************************************/
/*****************Nested vectored interrupt controller (NVIC)******************/
#define NVIC_BASE                                                 0xE000E100UL

/*******************************************************************************
                      Base addresses for AHB BUS Peripherals
*******************************************************************************/
/*************************Reset and Control Clock (RCC)************************/
#define RCC_BASE                             ( PERIPHERALS_BASE + 0x00021000UL )


/*******************************************************************************
                     Base addresses for APB1 BUS Peripherals
*******************************************************************************/
/*******Universal Synchronous Asynchronous Receiver Transmitter (USART)********/
#define USART2_BASE                          ( PERIPHERALS_BASE + 0x00004400UL )
#define USART3_BASE                          ( PERIPHERALS_BASE + 0x00004800UL )

/**********************Serial peripheral interface (SPI)***********************/
#define SPI2_BASE                            ( PERIPHERALS_BASE + 0x00003800UL )

/***********************Inter-integrated circuit (I2C)*************************/
#define I2C1_BASE                            ( PERIPHERALS_BASE + 0x00005400UL )
#define I2C2_BASE                            ( PERIPHERALS_BASE + 0x00005800UL )


/*******************************************************************************
                     Base addresses for APB2 BUS Peripherals
*******************************************************************************/
/****************General Purpose Input Output Peripheral (GPIO)****************/
// GPIOA , GPIOB fully included in LFP48 Packages
#define GPIOA_BASE                           ( PERIPHERALS_BASE + 0x00010800UL )
#define GPIOB_BASE                           ( PERIPHERALS_BASE + 0x00010C00UL )

// GPIOC , GPIOD partial included in LFP48 Packages
#define GPIOC_BASE                           ( PERIPHERALS_BASE + 0x00011000UL )
#define GPIOD_BASE                           ( PERIPHERALS_BASE + 0x00011400UL )

// GPIOE not included in LFP48 Packages
#define GPIOE_BASE                           ( PERIPHERALS_BASE + 0x00011800UL )

/*******************Alternative Functions Input Output (AFIO)******************/
#define AFIO_BASE                            ( PERIPHERALS_BASE + 0x00010000UL )

/***************************External Interrupt (EXTI)**************************/
#define EXTI_BASE                            ( PERIPHERALS_BASE + 0x00010400UL )

/*******Universal Synchronous Asynchronous Receiver Transmitter (USART)********/
#define USART1_BASE                          ( PERIPHERALS_BASE + 0x00013800UL )

/**********************Serial peripheral interface (SPI)***********************/
#define SPI1_BASE                            ( PERIPHERALS_BASE + 0x00013000UL )


/*******************************************************************************
                Memory Mapping for Peripherals related with CORE
*******************************************************************************/
/********************************NVIC Registers********************************/
// Interrupt set-enable registers (NVIC_ISERx)
typedef struct{
	volatile uint32_t NVIC_ISER0;
	volatile uint32_t NVIC_ISER1;
	volatile uint32_t NVIC_ISER2;
}NVIC_ISER_t;
#define NVIC_ISER                ((volatile NVIC_ISER_t *)(NVIC_BASE + 0x00))

// Interrupt clear-enable registers (NVIC_ICERx)
typedef struct{
	volatile uint32_t NVIC_ICER0;
	volatile uint32_t NVIC_ICER1;
	volatile uint32_t NVIC_ICER2;
}NVIC_ICER_t;
#define NVIC_ICER                ((volatile NVIC_ICER_t *)(NVIC_BASE + 0x80))

// Interrupt set-pending registers (NVIC_ISPRx)
typedef struct{
	volatile uint32_t NVIC_ISPR0;
	volatile uint32_t NVIC_ISPR1;
	volatile uint32_t NVIC_ISPR2;
}NVIC_ISPR_t;
#define NVIC_ISPR                ((volatile NVIC_ISPR_t *)(NVIC_BASE + 0x100))

// Interrupt clear-pending registers (NVIC_ICPRx)
typedef struct{
	volatile uint32_t NVIC_ICPR0;
	volatile uint32_t NVIC_ICPR1;
	volatile uint32_t NVIC_ICPR2;
}NVIC_ICPR_t;
#define NVIC_ICPR                ((volatile NVIC_ICPR_t *)(NVIC_BASE + 0x180))

// Interrupt active bit registers (NVIC_IABRx)
typedef struct{
	volatile uint32_t NVIC_IABR0;
	volatile uint32_t NVIC_IABR1;
	volatile uint32_t NVIC_IABR2;
}NVIC_IABR_t;
#define NVIC_IABR                ((volatile NVIC_IABR_t *)(NVIC_BASE + 0x200))

// Interrupt priority registers (NVIC_IPRx)
typedef struct{
	volatile uint32_t NVIC_IPR[21];
}NVIC_IPR_t;
#define NVIC_IPR                 ((volatile NVIC_IPR_t *)(NVIC_BASE + 0x300))

// Software trigger interrupt register (NVIC_STIR)
#define NVIC_STIR                ((volatile uint32_t   *)(NVIC_BASE + 0xE00))


/*******************************************************************************
                      Memory Mapping for AHB BUS Peripherals
*******************************************************************************/
/******************************RCC Registers' Bits*****************************/
// Clock control register (RCC_CR)
typedef union{
	volatile uint32_t CR;
	struct{
		volatile uint32_t HSION:1;
		volatile uint32_t HSIRDY:1;
		volatile uint32_t Reserved:1;
		volatile uint32_t HSITRIM:5;
		volatile uint32_t HSICAL:8;
		volatile uint32_t HSEON:1;
		volatile uint32_t HSERDY:1;
		volatile uint32_t HSEBYP:1;
		volatile uint32_t CSSON:1;
		volatile uint32_t Reserved1:4;
		volatile uint32_t PLLON:1;
		volatile uint32_t PLLRDY:1;
		volatile uint32_t Reserved2:6;
	};
}RCC_CR_t;

// Clock configuration register (RCC_CFGR)
typedef union{
	volatile uint32_t CFGR;
	struct{
		volatile uint32_t SW:2;
		volatile uint32_t SWS:2;
		volatile uint32_t HPRE:4;
		volatile uint32_t PPRE1:3;
		volatile uint32_t PPRE2:3;
		volatile uint32_t ADCPRE:2;
		volatile uint32_t PLLSRC:1;
		volatile uint32_t PLLXTPRE:1;
		volatile uint32_t PLLMUL:4;
		volatile uint32_t USBPRE:1;
		volatile uint32_t Reserved:1;
		volatile uint32_t MCO:3;
		volatile uint32_t Reserved1:5;
	};
}RCC_CFGR_t;


// Clock interrupt register (RCC_CIR)
typedef union{
	volatile uint32_t CIR;
	struct{
		volatile uint32_t LSIRDYF:1;
		volatile uint32_t LSERDYF:1;
		volatile uint32_t HSIRDYF:1;
		volatile uint32_t HSERDYF:1;
		volatile uint32_t PLLRDYF:1;
		volatile uint32_t Reserved:2;
		volatile uint32_t CSSF:1;
		volatile uint32_t LSIRDYIE:1;
		volatile uint32_t LSERDYIE:1;
		volatile uint32_t HSIRDYIE:1;
		volatile uint32_t HSERDYIE:1;
		volatile uint32_t PLLRDYIE:1;
		volatile uint32_t Reserved1:3;
		volatile uint32_t LSIRDYC:1;
		volatile uint32_t LSERDYC:1;
		volatile uint32_t HSIRDYC:1;
		volatile uint32_t HSERDYC:1;
		volatile uint32_t PLLRDYC:1;
		volatile uint32_t Reserved2:2;
		volatile uint32_t CSSC:1;
		volatile uint32_t Reserved3:8;
	};
}RCC_CIR_t;

// APB2 peripheral reset register (RCC_APB2RSTR)
typedef union{
	volatile uint32_t APB2RSTR;
	struct{
		volatile uint32_t AFIORST:1;
		volatile uint32_t Reserved:1;
		volatile uint32_t IOPARST:1;
		volatile uint32_t IOPBRST:1;
		volatile uint32_t IOPCRST:1;
		volatile uint32_t IOPDRST:1;
		volatile uint32_t IOPERST:1;
		volatile uint32_t IOPFRST:1;
		volatile uint32_t IOPGRST:1;
		volatile uint32_t ADC1RST:1;
		volatile uint32_t ADC2RST:1;
		volatile uint32_t TIM1RST:1;
		volatile uint32_t SPI1RST:1;
		volatile uint32_t TIM8RST:1;
		volatile uint32_t USART1RST:1;
		volatile uint32_t ADC3RST:1;
		volatile uint32_t Reserved1:3;
		volatile uint32_t TIM9RST:1;
		volatile uint32_t TIM10RST:1;
		volatile uint32_t TIM11RST:1;
		volatile uint32_t Reserved2:10;
	};
}RCC_APB2RSTR_t;

// APB1 peripheral reset register (RCC_APB1RSTR)
typedef union{
	volatile uint32_t APB1RSTR;
	struct{
		volatile uint32_t TIM2RST:1;
		volatile uint32_t TIM3RST:1;
		volatile uint32_t TIM4RST:1;
		volatile uint32_t TIM5RST:1;
		volatile uint32_t TIM6RST:1;
		volatile uint32_t TIM7RST:1;
		volatile uint32_t TIM12RST:1;
		volatile uint32_t TIM13RST:1;
		volatile uint32_t TIM14RST:1;
		volatile uint32_t Reserved:2;
		volatile uint32_t WWDGRST:1;
		volatile uint32_t Reserved1:2;
		volatile uint32_t SPI2RST:1;
		volatile uint32_t SPI3RST:1;
		volatile uint32_t Reserved2:1;
		volatile uint32_t USART2RST:1;
		volatile uint32_t USART3RST:1;
		volatile uint32_t UART4RST:1;
		volatile uint32_t UART5RST:1;
		volatile uint32_t I2C1RST:1;
		volatile uint32_t I2C2RST:1;
		volatile uint32_t USBRST:1;
		volatile uint32_t Reserved3:1;
		volatile uint32_t CANRST:1;
		volatile uint32_t Reserved4:1;
		volatile uint32_t BKPRST:1;
		volatile uint32_t PWRRST:1;
		volatile uint32_t DACRST:1;
		volatile uint32_t Reserved5:2;
	};
}RCC_APB1RSTR_t;

// AHB peripheral clock enable register (RCC_AHBENR)
typedef union{
	volatile uint32_t AHBENR;
	struct{
		volatile uint32_t DMA1EN:1;
		volatile uint32_t DMA2EN:1;
		volatile uint32_t SRAMEN:1;
		volatile uint32_t Reserved:1;
		volatile uint32_t FLITFEN:1;
		volatile uint32_t Reserved1:1;
		volatile uint32_t CRCEN:1;
		volatile uint32_t Reserved2:1;
		volatile uint32_t FSMCEN:1;
		volatile uint32_t Reserved3:1;
		volatile uint32_t SDIOEN:1;
		volatile uint32_t Reserved4:21;
	};
}RCC_AHBENR_t;

// APB2 peripheral clock enable register (RCC_APB2ENR)
typedef union{
	volatile uint32_t APB2ENR;
	struct{
		volatile uint32_t AFIOEN:1;
		volatile uint32_t Reserved:1;
		volatile uint32_t IOPAEN:1;
		volatile uint32_t IOPBEN:1;
		volatile uint32_t IOPCEN:1;
		volatile uint32_t IOPDEN:1;
		volatile uint32_t IOPEEN:1;
		volatile uint32_t IOPFEN:1;
		volatile uint32_t IOPGEN:1;
		volatile uint32_t ADC1EN:1;
		volatile uint32_t ADC2EN:1;
		volatile uint32_t TIM1EN:1;
		volatile uint32_t SPI1EN:1;
		volatile uint32_t TIM8EN:1;
		volatile uint32_t USART1EN:1;
		volatile uint32_t ADC3EN:1;
		volatile uint32_t Reserved1:3;
		volatile uint32_t TIM9EN:1;
		volatile uint32_t TIM10EN:1;
		volatile uint32_t TIM11EN:1;
		volatile uint32_t Reserved2:10;
	};
}RCC_APB2ENR_t;

// APB1 peripheral clock enable register (RCC_APB1ENR)
typedef union{
	volatile uint32_t APB1ENR;
	struct{
		volatile uint32_t TIM2EN:1;
		volatile uint32_t TIM3EN:1;
		volatile uint32_t TIM4EN:1;
		volatile uint32_t TIM5EN:1;
		volatile uint32_t TIM6EN:1;
		volatile uint32_t TIM7EN:1;
		volatile uint32_t TIM12EN:1;
		volatile uint32_t TIM13EN:1;
		volatile uint32_t TIM14EN:1;
		volatile uint32_t Reserved:2;
		volatile uint32_t WWDGEN:1;
		volatile uint32_t Reserved1:2;
		volatile uint32_t SPI2EN:1;
		volatile uint32_t SPI3EN:1;
		volatile uint32_t Reserved2:1;
		volatile uint32_t USART2EN:1;
		volatile uint32_t USART3EN:1;
		volatile uint32_t UART4REN:1;
		volatile uint32_t UART5EN:1;
		volatile uint32_t I2C1EN:1;
		volatile uint32_t I2C2EN:1;
		volatile uint32_t USBEN:1;
		volatile uint32_t Reserved3:1;
		volatile uint32_t CANEN:1;
		volatile uint32_t Reserved4:1;
		volatile uint32_t BKPEN:1;
		volatile uint32_t PWREN:1;
		volatile uint32_t DACEN:1;
		volatile uint32_t Reserved5:2;
	};
}RCC_APB1ENR_t;

// Backup domain control register (RCC_BDCR)
typedef union{
	volatile uint32_t BDCR;
	struct{
		volatile uint32_t LSEON:1;
		volatile uint32_t LSERDY:1;
		volatile uint32_t LSEBYP:1;
		volatile uint32_t Reserved:5;
		volatile uint32_t RTCSEL:2;
		volatile uint32_t Reserved1:5;
		volatile uint32_t RTCEN:1;
		volatile uint32_t BDRST:1;
		volatile uint32_t Reserved2:15;
	};
}RCC_BDCR_t;

// Control/status register (RCC_CSR)
typedef union{
	volatile uint32_t CSR;
	struct{
		volatile uint32_t LSION:1;
		volatile uint32_t LSIRDY:1;
		volatile uint32_t Reserved:22;
		volatile uint32_t RMVF:1;
		volatile uint32_t Reserved1:1;
		volatile uint32_t PINRSTF:1;
		volatile uint32_t PORRSTF:1;
		volatile uint32_t SETRSTF:1;
		volatile uint32_t IWDGRSTF:1;
		volatile uint32_t WWDGRSTF:1;
		volatile uint32_t LPWRRSTF:1;
	};
}RCC_CSR_t;

/*********************************RCC Registers********************************/
typedef struct{
	volatile RCC_CR_t CR;
	volatile RCC_CFGR_t CFGR;
	volatile RCC_CIR_t CIR;
	volatile RCC_APB2RSTR_t APB2RSTR;
	volatile RCC_APB1RSTR_t APB1RSTR;
	volatile RCC_AHBENR_t AHBENR;
	volatile RCC_APB2ENR_t APB2ENR;
	volatile RCC_APB1ENR_t APB1ENR;
	volatile RCC_BDCR_t BDCR;
	volatile RCC_CSR_t CSR;
}RCC_t;


/*******************************************************************************
                     Memory Mapping for APB1 BUS Peripherals
*******************************************************************************/
/****************************USART Registers' Bits*****************************/
// Status register (USART_SR)
typedef union{
	volatile uint32_t SR;
	struct{
		volatile uint32_t PE:1;
		volatile uint32_t FE:1;
		volatile uint32_t NE:1;
		volatile uint32_t ORE:1;
		volatile uint32_t IDIE:1;
		volatile uint32_t RXNE:1;
		volatile uint32_t TC:1;
		volatile uint32_t TXE:1;
		volatile uint32_t LBD:1;
		volatile uint32_t CTS:1;
		volatile uint32_t Reserved:22;
	};
}USART_SR_t;

// Data register (USART_DR)
typedef union{
	volatile uint32_t _DR;
	struct{
		volatile uint32_t DR:9;
		volatile uint32_t Reserved:23;
	};
}USART_DR_t;

// Baud rate register (USART_BRR)
typedef union{
	volatile uint32_t BRR;
	struct{
		volatile uint32_t DIV_Fraction:4;
		volatile uint32_t DIV_Mantissa:12;
		volatile uint32_t Reserved:16;
	};
}USART_BRR_t;

// Control register 1 (USART_CR1)
typedef union{
	volatile uint32_t CR1;
	struct{
		volatile uint32_t SBK:1;
		volatile uint32_t RWU:1;
		volatile uint32_t RE:1;
		volatile uint32_t TE:1;
		volatile uint32_t IDLEIE:1;
		volatile uint32_t RXNEIE:1;
		volatile uint32_t TCIE:1;
		volatile uint32_t TXEIE:1;
		volatile uint32_t PEIE:1;
		volatile uint32_t PS:1;
		volatile uint32_t PCE:1;
		volatile uint32_t WAKE:1;
		volatile uint32_t M:1;
		volatile uint32_t UE:1;
		volatile uint32_t Reserved:18;
	};
}USART_CR1_t;

// Control register 2 (USART_CR2)
typedef union{
	volatile uint32_t CR2;
	struct{
		volatile uint32_t ADD:4;
		volatile uint32_t Reserved1:1;
		volatile uint32_t LBDL:1;
		volatile uint32_t LBDIE:1;
		volatile uint32_t Reserved2:1;
		volatile uint32_t LBCL:1;
		volatile uint32_t CPHA:1;
		volatile uint32_t CPOL:1;
		volatile uint32_t CLKEN:1;
		volatile uint32_t STOP:2;
		volatile uint32_t LINEN:1;
		volatile uint32_t Reserved3:17;
	};
}USART_CR2_t;

// Control register 3 (USART_CR3)
typedef union{
	volatile uint32_t CR3;
	struct{
		volatile uint32_t EIE:1;
		volatile uint32_t IREN:1;
		volatile uint32_t IRLP:1;
		volatile uint32_t HDSEL:1;
		volatile uint32_t NACK:1;
		volatile uint32_t SCEN:1;
		volatile uint32_t DMAR:1;
		volatile uint32_t DMAT:1;
		volatile uint32_t RTSE:1;
		volatile uint32_t CTSE:1;
		volatile uint32_t CTSIE:1;
		volatile uint32_t Reserved:21;
	};
}USART_CR3_t;

// Guard time and prescaler register (USART_GTPR)
typedef union{
	volatile uint32_t GTPR;
	struct{
		volatile uint32_t PSC:8;
		volatile uint32_t GT:8;
		volatile uint32_t Reserved:16;
	};
}USART_GTPR_t;

/*******************************USART Registers********************************/
typedef struct{
	volatile USART_SR_t SR;
	volatile USART_DR_t DR;
	volatile USART_BRR_t BRR;
	volatile USART_CR1_t CR1;
	volatile USART_CR2_t CR2;
	volatile USART_CR3_t CR3;
	volatile USART_GTPR_t GTPR;
}USART_t;


/******************************SPI Registers' Bits*****************************/
// SPI control register 1 (SPI_CR1)
typedef union{
	volatile uint32_t CR1;
	struct{
		volatile uint32_t CPHA:1;
		volatile uint32_t CPOL:1;
		volatile uint32_t MSTR:1;
		volatile uint32_t BR:3;
		volatile uint32_t SPE:1;
		volatile uint32_t LSBFIRST:1;
		volatile uint32_t SSI:1;
		volatile uint32_t SSM:1;
		volatile uint32_t RXONLY:1;
		volatile uint32_t DFF:1;
		volatile uint32_t CRCNEXT:1;
		volatile uint32_t CRCEN:1;
		volatile uint32_t BIDIOE:1;
		volatile uint32_t BIDIMODE:1;
		volatile uint32_t Reserved:16;
	};
}SPI_CR1_t;

// SPI control register 2 (SPI_CR2)
typedef union{
	volatile uint32_t CR2;
	struct{
		volatile uint32_t RXDMAEN:1;
		volatile uint32_t TXDMAEN:1;
		volatile uint32_t SSOE:1;
		volatile uint32_t Reserved1:2;
		volatile uint32_t ERRIE:1;
		volatile uint32_t RXNEIE:1;
		volatile uint32_t TXEIE:1;
		volatile uint32_t Reserved2:24;
	};
}SPI_CR2_t;

// SPI status register (SPI_SR)
typedef union{
	volatile uint32_t SR;
	struct{
		volatile uint32_t RXNE:1;
		volatile uint32_t TXE:1;
		volatile uint32_t CHSIDE:1;
		volatile uint32_t UDR:1;
		volatile uint32_t CRCERR:1;
		volatile uint32_t MODF:1;
		volatile uint32_t OVR:1;
		volatile uint32_t BSY:1;
		volatile uint32_t Reserved:24;
	};
}SPI_SR_t;

// SPI data register (SPI_DR)
typedef union{
	volatile uint32_t _DR;
	struct{
		volatile uint32_t DR:16;
		volatile uint32_t Reserved:16;
	};
}SPI_DR_t;

/********************************SPI Registers*********************************/
typedef struct{
	volatile SPI_CR1_t CR1;
	volatile SPI_CR2_t CR2;
	volatile SPI_SR_t SR;
	volatile SPI_DR_t DR;
	volatile uint32_t SPI_CRCPR;
	volatile uint32_t SPI_RXCRCR;
	volatile uint32_t SPI_TXCRCR;
	volatile uint32_t SPI_I2SCFGR;
	volatile uint32_t SPI_I2SPR;
}SPI_t;

/******************************I2C Registers' Bits*****************************/
// I2C Control register 1 (I2C_CR1)
typedef union{
	volatile uint32_t CR1;
	struct{
		volatile uint32_t PE:1;
		volatile uint32_t SMBUS:1;
		volatile uint32_t Reserved1:1;
		volatile uint32_t SMBTYPE:1;
		volatile uint32_t ENARP:1;
		volatile uint32_t ENPEC:1;
		volatile uint32_t ENGC:1;
		volatile uint32_t NOSTRETCH:1;
		volatile uint32_t START:1;
		volatile uint32_t STOP:1;
		volatile uint32_t ACK:1;
		volatile uint32_t POS:1;
		volatile uint32_t PEC:1;
		volatile uint32_t ALERT:1;
		volatile uint32_t Reserved2:1;
		volatile uint32_t SWRST:1;
		volatile uint32_t Reserved3:16;
	};
}I2C_CR1_t;

// I2C Control register 2 (I2C_CR2)
typedef union{
	volatile uint32_t CR2;
	struct{
		volatile uint32_t FREQ:6;
		volatile uint32_t Reserved1:2;
		volatile uint32_t ITERREN:1;
		volatile uint32_t ITEVTEN:1;
		volatile uint32_t ITBUFEN:1;
		volatile uint32_t DMAEN:1;
		volatile uint32_t LAST:1;
		volatile uint32_t Reserved2:19;
	};
}I2C_CR2_t;

// I2C Own address register 1 (I2C_OAR1)
typedef union{
	volatile uint32_t OAR1;
	struct{
		volatile uint32_t ADD0:1;
		volatile uint32_t ADD1_7:7;
		volatile uint32_t ADD8_9:2;
		volatile uint32_t Reserved1:5;
		volatile uint32_t ADDMODE:1;
		volatile uint32_t Reserved2:16;
	};
}I2C_OAR1_t;

// I2C Own address register 2 (I2C_OAR2)
typedef union{
	volatile uint32_t OAR2;
	struct{
		volatile uint32_t ENDUAL:1;
		volatile uint32_t ADD2:7;
		volatile uint32_t Reserved2:24;
	};
}I2C_OAR2_t;

// I2C Data register (I2C_DR)
typedef union{
	volatile uint32_t _DR;
	struct{
		volatile uint32_t DR:8;
		volatile uint32_t Reserved:24;
	};
}I2C_DR_t;

// I2C Status register 1 (I2C_SR1)
typedef union{
	volatile uint32_t SR1;
	struct{
		volatile uint32_t SB:1;
		volatile uint32_t ADDR:1;
		volatile uint32_t BTF:1;
		volatile uint32_t ADD10:1;
		volatile uint32_t STOPF:1;
		volatile uint32_t Reserved1:1;
		volatile uint32_t RxNE:1;
		volatile uint32_t TxE:1;
		volatile uint32_t BERR:1;
		volatile uint32_t ARLO:1;
		volatile uint32_t AF:1;
		volatile uint32_t OVR:1;
		volatile uint32_t PECERR:1;
		volatile uint32_t Reserved2:1;
		volatile uint32_t TIMEOUT:1;
		volatile uint32_t SMBALERT:1;
		volatile uint32_t Reserved3:16;
	};
}I2C_SR1_t;

// I2C Status register 2 (I2C_SR2)
typedef union{
	volatile uint32_t SR2;
	struct{
		volatile uint32_t MSL:1;
		volatile uint32_t BUSY:1;
		volatile uint32_t TRA:1;
		volatile uint32_t Reserved1:1;
		volatile uint32_t GENCALL:1;
		volatile uint32_t SMBDEFAULT:1;
		volatile uint32_t SMBHOST:1;
		volatile uint32_t DUALF:1;
		volatile uint32_t PEC:8;
		volatile uint32_t Reserved2:16;
	};
}I2C_SR2_t;

// I2C Clock control register (I2C_CCR)
typedef union{
	volatile uint32_t _CCR;
	struct{
		volatile uint32_t CCR:12;
		volatile uint32_t Reserved1:2;
		volatile uint32_t DUTY:1;
		volatile uint32_t FS:1;
		volatile uint32_t Reserved2:16;
	};
}I2C_CCR_t;

// I2C TRISE register (I2C_TRISE)
typedef union{
	volatile uint32_t _TRISE;
	struct{
		volatile uint32_t TRISE:6;
		volatile uint32_t Reserved:26;
	};
}I2C_TRISE_t;


/********************************I2C Registers*********************************/
typedef struct{
	volatile I2C_CR1_t CR1;
	volatile I2C_CR2_t CR2;
	volatile I2C_OAR1_t OAR1;
	volatile I2C_OAR2_t OAR2;
	volatile I2C_DR_t DR;
	volatile I2C_SR1_t SR1;
	volatile I2C_SR2_t SR2;
	volatile I2C_CCR_t CCR;
	volatile I2C_TRISE_t TRISE;
}I2C_t;


/*******************************************************************************
                     Memory Mapping for APB2 BUS Peripherals
*******************************************************************************/
/*****************************GPIO Registers' Bits*****************************/
// Port configuration register low (GPIOx_CRL) (x=A..G)
typedef union{
	volatile uint32_t CRL;
	struct{
		volatile uint32_t MODE0:2;
		volatile uint32_t  CNF0:2;
		volatile uint32_t MODE1:2;
		volatile uint32_t  CNF1:2;
		volatile uint32_t MODE2:2;
		volatile uint32_t  CNF2:2;
		volatile uint32_t MODE3:2;
		volatile uint32_t  CNF3:2;
		volatile uint32_t MODE4:2;
		volatile uint32_t  CNF4:2;
		volatile uint32_t MODE5:2;
		volatile uint32_t  CNF5:2;
		volatile uint32_t MODE6:2;
		volatile uint32_t  CNF6:2;
		volatile uint32_t MODE7:2;
		volatile uint32_t  CNF7:2;
	};
}GPIOx_CRL_t;

// Port configuration register high (GPIOx_CRH) (x=A..G)
typedef union{
	volatile uint32_t CRH;
	struct{
		volatile uint32_t  MODE8:2;
		volatile uint32_t   CNF8:2;
		volatile uint32_t  MODE9:2;
		volatile uint32_t   CNF9:2;
		volatile uint32_t MODE10:2;
		volatile uint32_t  CNF10:2;
		volatile uint32_t MODE11:2;
		volatile uint32_t  CNF11:2;
		volatile uint32_t MODE12:2;
		volatile uint32_t  CNF12:2;
		volatile uint32_t MODE13:2;
		volatile uint32_t  CNF13:2;
		volatile uint32_t MODE14:2;
		volatile uint32_t  CNF14:2;
		volatile uint32_t MODE15:2;
		volatile uint32_t  CNF15:2;
	};
}GPIOx_CRH_t;

// Port input data register (GPIOx_IDR) (x=A..G)
typedef union{
	volatile uint32_t IDR;
	struct{
		volatile uint32_t _IDR:16;
		volatile uint32_t Reserved:16;
	};
}GPIOx_IDR_t;

// Port output data register (GPIOx_ODR) (x=A..G)
typedef union{
	volatile uint32_t ODR;
	struct{
		volatile uint32_t _ODR:16;
		volatile uint32_t Reserved:16;
	};
}GPIOx_ODR_t;

// Port bit set/reset register (GPIOx_BSRR) (x=A..G)
typedef union{
	volatile uint32_t BSRR;
	struct{
		volatile uint32_t BS:16;
		volatile uint32_t BR:16;
	};
}GPIOx_BSRR_t;

// Port bit reset register (GPIOx_BRR) (x=A..G)
typedef union{
	volatile uint32_t BRR;
	struct{
		volatile uint32_t BR:16;
		volatile uint32_t Reserved:16;
	};
}GPIOx_BRR_t;

// Port configuration lock register (GPIOx_LCKR) (x=A..G)
typedef union{
	volatile uint32_t LCKR;
	struct{
		volatile uint32_t LCK:16;
		volatile uint32_t LCKK:1;
		volatile uint32_t Reserved:15;
	};
}GPIOx_LCKR_t;

/********************************GPIO Registers********************************/
typedef struct{
	GPIOx_CRL_t CRL;
	GPIOx_CRH_t CRH;
	GPIOx_IDR_t IDR;
	GPIOx_ODR_t ODR;
	GPIOx_BSRR_t BSRR;
	GPIOx_BRR_t BRR;
	GPIOx_LCKR_t LCKR;
}GPIO_t;


/*****************************AFIO Registers' Bits*****************************/
// Event control register (AFIO_EVCR)
typedef union{
	volatile uint32_t EVCR;
	struct{
		volatile uint32_t PIN:3;
		volatile uint32_t PORT:3;
		volatile uint32_t EVOE:1;
		volatile uint32_t Reserved:25;
	};
}AFIO_EVCR_t;

// External interrupt configuration register x (AFIO_EXTICRx)
typedef union{
	volatile uint32_t EXTICR;
	struct{
		volatile uint32_t EXTI_0:4;
		volatile uint32_t EXTI_1:4;
		volatile uint32_t EXTI_2:4;
		volatile uint32_t EXTI_3:4;
		volatile uint32_t Reserved:16;
	};
}AFIO_EXTICRx_t;

// AF remap and debug I/O configuration register (AFIO_MAPR)
// Memory map and bit definitions for low-, medium- high- and XL-density devices
typedef union{
	volatile uint32_t MAPR;
	struct{
		volatile uint32_t SPI1_REMAP:1;
		volatile uint32_t I2C1_REMAP:1;
		volatile uint32_t USART1_REMAP:1;
		volatile uint32_t USART2_REMAP:1;
		volatile uint32_t USART3_REMAP:2;
		volatile uint32_t TIM1_REMAP:2;
		volatile uint32_t TIM2_REMAP:2;
		volatile uint32_t TIM3_REMAP:2;
		volatile uint32_t TIM4_REMAP:1;
		volatile uint32_t CAN_REMAP:2;
		volatile uint32_t PD01_REMAP:1;
		volatile uint32_t TIM5CH4_IREMAP:1;
		volatile uint32_t ADC1_ETRGINJ_IREMAP:1;
		volatile uint32_t ADC1_ETRGREG_REMAP:1;
		volatile uint32_t ADC2_ETRGINJ_REMAP:1;
		volatile uint32_t ADC2_ETRGREG_REMAP:1;
		volatile uint32_t Reserved:3;
		volatile uint32_t SWJ_CFG:3;
		volatile uint32_t Reserved1:5;
	};
}AFIO_MAPR_t;

// AF remap and debug I/O configuration register2 (AFIO_MAPR2)
typedef union{
	volatile uint32_t MAPR2;
	struct{
		volatile uint32_t Reserved:5;
		volatile uint32_t TIM9_REMAP:1;
		volatile uint32_t TIM10_REMAP:1;
		volatile uint32_t TIM11_REMAP:1;
		volatile uint32_t TIM13_REMAP:1;
		volatile uint32_t TIM14_REMAP:1;
		volatile uint32_t FSMC_NADV:1;
		volatile uint32_t Reserved1:21;
	};
}AFIO_MAPR2_t;

/********************************AFIO Registers********************************/
typedef struct{
	AFIO_EVCR_t EVCR;
	AFIO_MAPR_t MAPR;
	AFIO_EXTICRx_t AFIO_EXTICR[4];
	volatile uint32_t Reserved;
	AFIO_MAPR2_t MAPR2;
}AFIO_t;


/*****************************EXTI Registers' Bits*****************************/
// Interrupt mask register (EXTI_IMR)
typedef union{
	volatile uint32_t IMR;
	struct{
		volatile uint32_t MR:20;
		volatile uint32_t Reserved:12;
	};
}EXTI_IMR_t;

// Event mask register (EXTI_EMR)
typedef union{
	volatile uint32_t EMR;
	struct{
		volatile uint32_t MR:20;
		volatile uint32_t Reserved:12;
    };
}EXTI_EMR_t;

// Rising trigger selection register (EXTI_RTSR)
typedef union{
	volatile uint32_t RTSR;
	struct{
		volatile uint32_t TR:20;
		volatile uint32_t Reserved:12;
	};
}EXTI_RTSR_t;

// Falling trigger selection register (EXTI_FTSR)
typedef union{
	volatile uint32_t FTSR;
	struct{
		volatile uint32_t TR:20;
		volatile uint32_t Reserved:12;
	};
}EXTI_FTSR_t;

// Software interrupt event register (EXTI_SWIER)
typedef union{
	volatile uint32_t SWIER;
	struct{
		volatile uint32_t _SWIER:20;
		volatile uint32_t Reserved:12;
	};
}EXTI_SWIER_t;

// Pending register (EXTI_PR)
typedef union{
	volatile uint32_t PR;
	struct{
		volatile uint32_t _PR:20;
		volatile uint32_t Reserved:12;
	};
}EXTI_PR_t;

/********************************EXTI Registers********************************/
typedef struct{
	volatile EXTI_IMR_t IMR;
	volatile EXTI_EMR_t EMR;
	volatile EXTI_RTSR_t RTSR;
	volatile EXTI_FTSR_t FTSR;
	volatile EXTI_SWIER_t SWIER;
	volatile EXTI_PR_t PR;
}EXTI_t;


/*******************************************************************************
                               Peripheral Instants
*******************************************************************************/
/****************General Purpose Input Output Peripheral (GPIO)****************/
// GPIOA , GPIOB fully included in LFP48 Packages
#define GPIOA                              ((GPIO_t *)GPIOA_BASE)
#define GPIOB                              ((GPIO_t *)GPIOB_BASE)

// GPIOC , GPIOD partial included in LFP48 Packages
#define GPIOC                              ((GPIO_t *)GPIOC_BASE)
#define GPIOD                              ((GPIO_t *)GPIOD_BASE)

// GPIOE not included in LFP48 Packages
#define GPIOE                              ((GPIO_t *)GPIOE_BASE)

/************************Reset and Control Clock (RCC)*************************/
#define RCC                                ((RCC_t *)RCC_BASE)

/*******************Alternative Functions Input Output (AFIO)******************/
#define AFIO                               ((AFIO_t *)AFIO_BASE)

/***************************External Interrupt (EXTI)**************************/
#define EXTI                               ((EXTI_t *)EXTI_BASE)

/*******Universal Synchronous Asynchronous Receiver Transmitter (USART)********/
#define USART1                             ((USART_t *)USART1_BASE)
#define USART2                             ((USART_t *)USART2_BASE)
#define USART3                             ((USART_t *)USART3_BASE)

/**********************Serial peripheral interface (SPI)***********************/
#define SPI1                               ((SPI_t *)SPI1_BASE)
#define SPI2                               ((SPI_t *)SPI2_BASE)

/***********************Inter-integrated circuit (I2C)*************************/
#define I2C1                               ((I2C_t *)I2C1_BASE)
#define I2C2                               ((I2C_t *)I2C2_BASE)


/*******************************************************************************
              Nested vectored interrupt controller (NVIC) Macros
                           Interrupt Request Macros
*******************************************************************************/
// EXTI Request Position Macros
#define EXTI0_IRQ             6
#define EXTI1_IRQ             7
#define EXTI2_IRQ             8
#define EXTI3_IRQ             9
#define EXTI4_IRQ             10
#define EXTI5_IRQ             23
#define EXTI6_IRQ             23
#define EXTI7_IRQ             23
#define EXTI8_IRQ             23
#define EXTI9_IRQ             23
#define EXTI9_5_IRQ           23
#define EXTI10_IRQ            40
#define EXTI11_IRQ            40
#define EXTI12_IRQ            40
#define EXTI13_IRQ            40
#define EXTI14_IRQ            40
#define EXTI15_IRQ            40
#define EXTI15_10_IRQ         40


// USART Request Position Macros
#define USART1_IRQ	          37
#define USART2_IRQ		      38
#define USART3_IRQ		      39

// SPI Request Position Macros
#define SPI1_IRQ	          35
#define SPI2_IRQ		      36

// I2C Request Position Macros
#define I2C1_EV_IRQ	          31
#define I2C1_ER_IRQ           32
#define I2C2_EV_IRQ	          33
#define I2C2_ER_IRQ		      34

/*******************************************************************************
                     External Interrupt Line Number Macros
*******************************************************************************/
#define EXTI0                 (uint16_t)0
#define EXTI1                 (uint16_t)1
#define EXTI2                 (uint16_t)2
#define EXTI3                 (uint16_t)3
#define EXTI4                 (uint16_t)4
#define EXTI5                 (uint16_t)5
#define EXTI6                 (uint16_t)6
#define EXTI7                 (uint16_t)7
#define EXTI8                 (uint16_t)8
#define EXTI9                 (uint16_t)9
#define EXTI10                (uint16_t)10
#define EXTI11                (uint16_t)11
#define EXTI12                (uint16_t)12
#define EXTI13                (uint16_t)13
#define EXTI14                (uint16_t)14
#define EXTI15                (uint16_t)15


/*******************************************************************************
                                  Generic Macros
*******************************************************************************/
#define TRUE        1
#define FALSE       0


/********************************* GLOBAL_ENUM ********************************/
typedef enum{
	ERROR,
	DONE
}Return_t;

#endif /* STM32F103X6_H_ */
