ENTRY(reset)

MEMORY
{
	RAM( rwx ) : ORIGIN = 0x00000000,   LENGTH = 64M
}

SECTIONS
{
    . = 0x10000;
	.startup :
	{
	  startup.o(.text)
	}> RAM
	.text :
	{
	  *(.text) *(.rodata)
	}> RAM
	.data :
	{
      *(.data)
	}> RAM
	.bss :
	{
	  *(.bss)  *(COMMON)
	}> RAM
	. = . + 0x1000 ;          /*10k of stack memory*/
	stack_top = . ;
}