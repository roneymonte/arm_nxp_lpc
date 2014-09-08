################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/LCD_Lib.c \
../src/SysTick_Lib.c \
../src/UART0_Lib.c 

OBJS += \
./src/LCD_Lib.o \
./src/SysTick_Lib.o \
./src/UART0_Lib.o 

C_DEPS += \
./src/LCD_Lib.d \
./src/SysTick_Lib.d \
./src/UART0_Lib.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -D__USE_CMSIS=CMSISv2p00_LPC17xx -I"C:\Users\roney\Documents\LPCXpresso_7.3.0_186\workspace_CMSIS_teste3\CMSISv2p00_LPC17xx\inc" -I"C:\Users\roney\Documents\LPCXpresso_7.3.0_186\workspace_CMSIS_teste3\LIB_LPC1700_USUARIO_v2Roney\inc" -Og -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


