#Author: Aya Sayed 
#Master Embedded System Diploma <Learn in depth>

CC = arm-none-eabi-
INCS = -I .
LIBS =
CFLAGS = -mcpu=cortex-m4 -gdwarf-2 -g
C = $(wildcard *.c)
COBJ = $(C:.c=.o)
AS = $(wildcard *.s)
ASOBJ = $(AS:.s=.o)
Project_Name = LAB3_CORTEX-M4


all: $(Project_Name).bin
	@echo "------------------Build is done------------------"

%.o: %.s
	$(CC)as.exe  $(CFLAGS) $< -o $@ 

%.o: %.c
	$(CC)gcc.exe  -c $(CFLAGS) $(INCS) $< -o $@

$(Project_Name).elf: $(ASOBJ) $(COBJ)
	$(CC)ld.exe   -T  Linker_Script.ld $(LIBS) -Map=Map.map $(COBJ) $(ASOBJ) -o  $(Project_Name).elf	
	cp $(Project_Name).elf $(Project_Name).axf

$(Project_Name).bin: $(Project_Name).elf
	$(CC)objcopy.exe  -O binary $< $@

clean_all:
	rm *.o *.elf *.bin
	@echo "Everything clean"

clean:
	rm *.bin *.elf

