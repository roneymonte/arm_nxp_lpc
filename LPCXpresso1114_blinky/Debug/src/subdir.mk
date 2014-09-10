################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/blinky_main.c \
../src/clkconfig.c \
../src/cr_startup_lpc11.c \
../src/gpio.c \
../src/timer16.c \
../src/timer16_int.c 

OBJS += \
./src/blinky_main.o \
./src/clkconfig.o \
./src/cr_startup_lpc11.o \
./src/gpio.o \
./src/timer16.o \
./src/timer16_int.o 

C_DEPS += \
./src/blinky_main.d \
./src/clkconfig.d \
./src/cr_startup_lpc11.d \
./src/gpio.d \
./src/timer16.d \
./src/timer16_int.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__USE_CMSIS=CMSISv1p30_LPC11xx -DDEBUG -D__CODE_RED -D__REDLIB__ -I"/Users/roney/git_lpcxpresso711a/arm_nxp_lpc/CMSISv1p30_LPC11xx/inc" -Og -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


