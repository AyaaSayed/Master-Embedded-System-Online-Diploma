 /******************************************************************************
 Master Embedded System Diploma <Learn in depth>
 file           : Linker_Script.ld
 Author         : Aya Sayed
 brief          : Linker Script program body
 ******************************************************************************/

 MEMORY
 {
     flash(RX)  : ORIGIN = 0x00000000, LENGTH = 512M
     sram(RWX)  : ORIGIN = 0x20000000, LENGTH = 512M
 }

 SECTIONS
 {
    .text :{
        *(.vectors*)
        *(.text*)
        _E_TEXT = . ; 
    }> flash
    .rodata :{
        *(.rodata* )
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
        _E_BSS = . ;
    }> sram 
 }