ENTRY(reset)

MEMORY
{
	RAM ( RWX ) : ORIGIN = 0x00000000,   LENGTH = 64M
}

SECTIONS
{
    . = 0x00010000;
	.startup . :
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
	. = . + 0x00001000;          /*10k of stack memory*/
	stack_top = . ;
}