################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Src/EXTI.c \
../MCAL/Src/GPIO.c \
../MCAL/Src/I2C.c \
../MCAL/Src/RCC.c \
../MCAL/Src/SPI.c \
../MCAL/Src/USART.c 

OBJS += \
./MCAL/Src/EXTI.o \
./MCAL/Src/GPIO.o \
./MCAL/Src/I2C.o \
./MCAL/Src/RCC.o \
./MCAL/Src/SPI.o \
./MCAL/Src/USART.o 

C_DEPS += \
./MCAL/Src/EXTI.d \
./MCAL/Src/GPIO.d \
./MCAL/Src/I2C.d \
./MCAL/Src/RCC.d \
./MCAL/Src/SPI.d \
./MCAL/Src/USART.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Src/EXTI.o: ../MCAL/Src/EXTI.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/Inc" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/HAL/EEPROM" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/APP/Inc" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/APP" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/HAL/7 Segment" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/HAL/Keypad" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/HAL/LCD" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/MCAL/Inc" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/MCAL/Src" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/MCAL" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/HAL" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/Src/EXTI.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL/Src/GPIO.o: ../MCAL/Src/GPIO.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/Inc" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/HAL/EEPROM" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/APP/Inc" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/APP" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/HAL/7 Segment" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/HAL/Keypad" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/HAL/LCD" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/MCAL/Inc" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/MCAL/Src" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/MCAL" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/HAL" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/Src/GPIO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL/Src/I2C.o: ../MCAL/Src/I2C.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/Inc" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/HAL/EEPROM" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/APP/Inc" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/APP" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/HAL/7 Segment" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/HAL/Keypad" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/HAL/LCD" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/MCAL/Inc" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/MCAL/Src" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/MCAL" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/HAL" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/Src/I2C.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL/Src/RCC.o: ../MCAL/Src/RCC.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/Inc" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/HAL/EEPROM" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/APP/Inc" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/APP" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/HAL/7 Segment" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/HAL/Keypad" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/HAL/LCD" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/MCAL/Inc" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/MCAL/Src" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/MCAL" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/HAL" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/Src/RCC.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL/Src/SPI.o: ../MCAL/Src/SPI.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/Inc" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/HAL/EEPROM" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/APP/Inc" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/APP" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/HAL/7 Segment" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/HAL/Keypad" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/HAL/LCD" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/MCAL/Inc" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/MCAL/Src" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/MCAL" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/HAL" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/Src/SPI.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL/Src/USART.o: ../MCAL/Src/USART.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/Inc" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/HAL/EEPROM" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/APP/Inc" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/APP" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/HAL/7 Segment" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/HAL/Keypad" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/HAL/LCD" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/MCAL/Inc" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/MCAL/Src" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/MCAL" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/HAL" -I"D:/my work/master embedded systems diploma/Drivers/STM32F103C6 Drivers/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/Src/USART.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

