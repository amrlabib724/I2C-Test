################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/UART/subdir.mk
-include MCAL/TIMER2/subdir.mk
-include MCAL/TIMER1/subdir.mk
-include MCAL/TIMER0/subdir.mk
-include MCAL/SPI/subdir.mk
-include MCAL/I2C/subdir.mk
-include MCAL/GIE/subdir.mk
-include MCAL/EXT_INT/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/KEYPAD/subdir.mk
-include HAL/EEPROM/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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
LSS += \
I2C_2.lss \

FLASH_IMAGE += \
I2C_2.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: I2C_2.elf secondary-outputs

# Tool invocations
I2C_2.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,I2C_2.map -mmcu=atmega32 -o "I2C_2.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

I2C_2.lss: I2C_2.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S I2C_2.elf  >"I2C_2.lss"
	@echo 'Finished building: $@'
	@echo ' '

I2C_2.hex: I2C_2.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex I2C_2.elf  "I2C_2.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: I2C_2.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 I2C_2.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) I2C_2.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
