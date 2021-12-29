#include <stdint.h>

extern int main(void);
extern uint32_t _E_TEXT;
extern uint32_t _S_DATA;
extern uint32_t _E_DATA;
extern uint32_t _S_BSS;
extern uint32_t _E_BSS;
extern uint32_t _stack_top;

void Reset_Handler(void);
void Default_Handler()
{
	Reset_Handler();
}

void NMI_Handler(void)__attribute__((weak, alias("Default_Handler")));
void Hard_Fault_Handler(void)__attribute__((weak, alias("Default_Handler")));
void MM_Fault_Handler(void)__attribute__((weak, alias("Default_Handler")));
void Bus_Fault_Handler(void)__attribute__((weak, alias("Default_Handler")));
void Usage_Fault_Handler(void)__attribute__((weak, alias("Default_Handler")));
void SV_call_Handler(void)__attribute__((weak, alias("Default_Handler")));
void Debug_reserved_Handler(void)__attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void)__attribute__((weak, alias("Default_Handler")));
void Sys_Tick_Handler(void)__attribute__((weak, alias("Default_Handler")));
void IRQ0_Handler(void)__attribute__((weak, alias("Default_Handler")));
void IRQ1_Handler(void)__attribute__((weak, alias("Default_Handler")));
void IRQ2_Handler(void)__attribute__((weak, alias("Default_Handler")));

uint32_t Vector[] __attribute__((section(".vectors"))) = {
(uint32_t) &_stack_top,
(uint32_t) &Reset_Handler,
(uint32_t) &NMI_Handler,
(uint32_t) &Hard_Fault_Handler,
(uint32_t) &MM_Fault_Handler,
(uint32_t) &Bus_Fault_Handler,
(uint32_t) &Usage_Fault_Handler,
(uint32_t) &SV_call_Handler,
(uint32_t) &Debug_reserved_Handler,
(uint32_t) &PendSV_Handler,
(uint32_t) &Sys_Tick_Handler,
(uint32_t) &IRQ0_Handler,
(uint32_t) &IRQ1_Handler,
(uint32_t) &IRQ1_Handler
};

void Reset_Handler(void)
{
	//copy data from FLASH to SRAM
	uint32_t DATA_SIZE = (uint8_t*)&_E_DATA - (uint8_t*)&_S_DATA;
	uint8_t* P_src = (uint8_t*)&_E_TEXT;
	uint8_t* P_dis = (uint8_t*)&_S_DATA;
	for( int i=0 ; i<DATA_SIZE ; i++)
	{
		*((uint8_t*)P_dis++) = *((uint8_t*)P_src++);
	}

	//initialize .bss with 0
	uint32_t BSS_SIZE = (uint8_t*)&_E_BSS - (uint8_t*)&_S_BSS;
	P_dis = (uint8_t*)&_S_BSS;
	for( int i=0 ; i<BSS_SIZE ; i++)
	{
		*((uint8_t*)P_dis++) = (uint8_t)0;
	}

	//jump to the main()
	main();
}

