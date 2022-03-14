################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/main.o: ../Src/main.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"D:/my work/master embedded systems diploma/Unit 7 (MCU Essential Peripherals )/Lesson 3/Assignment/Drivers/Inc" -I"D:/my work/master embedded systems diploma/Unit 7 (MCU Essential Peripherals )/Lesson 3/Assignment/Drivers/STM32F103x6/HAL/7 Segmet" -I"D:/my work/master embedded systems diploma/Unit 7 (MCU Essential Peripherals )/Lesson 3/Assignment/Drivers/STM32F103x6/HAL/Keypad" -I"D:/my work/master embedded systems diploma/Unit 7 (MCU Essential Peripherals )/Lesson 3/Assignment/Drivers/STM32F103x6/Inc" -I"D:/my work/master embedded systems diploma/Unit 7 (MCU Essential Peripherals )/Lesson 3/Assignment/Drivers/STM32F103x6/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/main.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/syscalls.o: ../Src/syscalls.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"D:/my work/master embedded systems diploma/Unit 7 (MCU Essential Peripherals )/Lesson 3/Assignment/Drivers/Inc" -I"D:/my work/master embedded systems diploma/Unit 7 (MCU Essential Peripherals )/Lesson 3/Assignment/Drivers/STM32F103x6/HAL/7 Segmet" -I"D:/my work/master embedded systems diploma/Unit 7 (MCU Essential Peripherals )/Lesson 3/Assignment/Drivers/STM32F103x6/HAL/Keypad" -I"D:/my work/master embedded systems diploma/Unit 7 (MCU Essential Peripherals )/Lesson 3/Assignment/Drivers/STM32F103x6/Inc" -I"D:/my work/master embedded systems diploma/Unit 7 (MCU Essential Peripherals )/Lesson 3/Assignment/Drivers/STM32F103x6/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/syscalls.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/sysmem.o: ../Src/sysmem.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"D:/my work/master embedded systems diploma/Unit 7 (MCU Essential Peripherals )/Lesson 3/Assignment/Drivers/Inc" -I"D:/my work/master embedded systems diploma/Unit 7 (MCU Essential Peripherals )/Lesson 3/Assignment/Drivers/STM32F103x6/HAL/7 Segmet" -I"D:/my work/master embedded systems diploma/Unit 7 (MCU Essential Peripherals )/Lesson 3/Assignment/Drivers/STM32F103x6/HAL/Keypad" -I"D:/my work/master embedded systems diploma/Unit 7 (MCU Essential Peripherals )/Lesson 3/Assignment/Drivers/STM32F103x6/Inc" -I"D:/my work/master embedded systems diploma/Unit 7 (MCU Essential Peripherals )/Lesson 3/Assignment/Drivers/STM32F103x6/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/sysmem.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

