################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/002_LEDbutton.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/002_LEDbutton.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/002_LEDbutton.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DB_G473E_ZEST1S -DSTM32G473QETx -DSTM32G4 -c -I"C:/Users/thena/Documents/MCU-Udemy/MCU1/stm324xx_drivers/drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/002_LEDbutton.cyclo ./Src/002_LEDbutton.d ./Src/002_LEDbutton.o ./Src/002_LEDbutton.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

