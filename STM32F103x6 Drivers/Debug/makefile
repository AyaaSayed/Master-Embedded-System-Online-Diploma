################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include STM32F103x6/Src/subdir.mk
-include STM32F103x6/HAL/LCD/subdir.mk
-include STM32F103x6/HAL/Keypad/subdir.mk
-include STM32F103x6/HAL/7\ Segmet/subdir.mk
-include Inc/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Drivers.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Drivers.list \

OBJCOPY_BIN += \
Drivers.bin \


# All Target
all: Drivers.elf secondary-outputs

# Tool invocations
Drivers.elf: $(OBJS) $(USER_OBJS) D:\my\ work\master\ embedded\ systems\ diploma\Unit\ 7\ (MCU\ Essential\ Peripherals\ )\Lesson\ 3\Assignment\Drivers\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -gdwarf-2 -o "Drivers.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\my work\master embedded systems diploma\Unit 7 (MCU Essential Peripherals )\Lesson 3\Assignment\Drivers\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Drivers.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Drivers.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Drivers.list"
	@echo 'Finished building: $@'
	@echo ' '

Drivers.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Drivers.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
