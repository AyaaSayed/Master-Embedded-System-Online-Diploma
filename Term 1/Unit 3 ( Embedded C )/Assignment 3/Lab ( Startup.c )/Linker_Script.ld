 /******************************************************************************
 Master Embedded System Diploma <Learn in depth>
 file           : Linker_Script.ld
 Author         : Aya Sayed
 brief          : Linker Script program body
 ******************************************************************************/

 MEMORY
 {
     flash(RX)  : ORIGIN = 0x08000000, LENGTH = 128k
     sram(RWX)  : ORIGIN = 0x20000000, LENGTH = 20k
 }

 SECTIONS
 {
    .text :{
        *(.vectors*)
        *(.text*)
        _E_TEXT = . ; 
    }> flash
    .data :{
        _S_DATA = . ;
        *(.data*)
        . = ALIGN(4);
        _E_DATA = . ;
    }> sram AT> flash
    .bss :{
        _S_BSS = . ;
        *(.bss)
        . = ALIGN(4);
        _E_BSS = . ;
        . = . + 0x1000;
        _stack_top = . ;
    }> sram 
    .rodata :{
        *(.rodata* )
    }> flash
 }