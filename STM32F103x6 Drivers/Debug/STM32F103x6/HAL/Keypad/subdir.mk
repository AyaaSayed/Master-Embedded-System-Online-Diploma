################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F103x6/HAL/Keypad/Keypad.c 

OBJS += \
./STM32F103x6/HAL/Keypad/Keypad.o 

C_DEPS += \
./STM32F103x6/HAL/Keypad/Keypad.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F103x6/HAL/Keypad/Keypad.o: ../STM32F103x6/HAL/Keypad/Keypad.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"D:/my work/master embedded systems diploma/Unit 7 (MCU Essential Peripherals )/Lesson 3/Assignment/Drivers/Inc" -I"D:/my work/master embedded systems diploma/Unit 7 (MCU Essential Peripherals )/Lesson 3/Assignment/Drivers/STM32F103x6/HAL/7 Segmet" -I"D:/my work/master embedded systems diploma/Unit 7 (MCU Essential Peripherals )/Lesson 3/Assignment/Drivers/STM32F103x6/HAL/Keypad" -I"D:/my work/master embedded systems diploma/Unit 7 (MCU Essential Peripherals )/Lesson 3/Assignment/Drivers/STM32F103x6/Inc" -I"D:/my work/master embedded systems diploma/Unit 7 (MCU Essential Peripherals )/Lesson 3/Assignment/Drivers/STM32F103x6/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103x6/HAL/Keypad/Keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

