################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: LPCXpresso1114_blinky.axf

# Tool invocations
LPCXpresso1114_blinky.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"/Users/roney/git_lpcxpresso711a/arm_nxp_lpc/CMSISv1p30_LPC11xx/Debug" -Xlinker -Map=LPCXpresso1114_blinky.map -Xlinker --gc-sections -mcpu=cortex-m0 -mthumb -T "lpcxpresso1114_blinky_Debug.ld" -o "LPCXpresso1114_blinky.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) LPCXpresso1114_blinky.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-cat ../abstract.txt; arm-none-eabi-objdump --source LPCXpresso1114_blinky.axf>../disassembly.txt;arm-none-eabi-nm --size-sort LPCXpresso1114_blinky.axf>../symbol_size.txt; arm-none-eabi-size LPCXpresso1114_blinky.axf; arm-none-eabi-objcopy -O binary LPCXpresso1114_blinky.axf LPCXpresso1114_blinky.bin ; checksum -d LPCXpresso1114_blinky.bin;  arm-none-eabi-objcopy -I binary LPCXpresso1114_blinky.bin -O ihex LPCXpresso1114_blinky.hex
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
