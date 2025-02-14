################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include Utils/strings/subdir.mk
-include Utils/queue/subdir.mk
-include Drivers_LPC845/timer/subdir.mk
-include Drivers_LPC845/systick/subdir.mk
-include Drivers_LPC845/sensor/subdir.mk
-include Drivers_LPC845/pinInt/subdir.mk
-include Drivers_LPC845/perifericoTemporizado/subdir.mk
-include Drivers_LPC845/gpio/subdir.mk
-include Drivers_LPC845/esp8266/subdir.mk
-include Drivers_LPC845/dr_init/subdir.mk
-include Drivers_LPC845/SerialCom/subdir.mk
-include Drivers_LPC845/I2C/subdir.mk
-include Drivers_LPC845/subdir.mk
-include .metadata/.plugins/org.eclipse.cdt.make.core/subdir.mk
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++M_DEPS)),)
-include $(C++M_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(CCM_DEPS)),)
-include $(CCM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXXM_DEPS)),)
-include $(CXXM_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := SPO2_HR
BUILD_ARTIFACT_EXTENSION := axf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all:
	+@$(MAKE) --no-print-directory main-build && $(MAKE) --no-print-directory post-build

# Main-build Target
main-build: SPO2_HR.axf

# Tool invocations
SPO2_HR.axf: $(OBJS) $(USER_OBJS) makefile $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU C++ Linker'
	arm-none-eabi-c++ -nostdlib -Xlinker -Map="SPO2_HR.map" -Xlinker --cref -Xlinker --gc-sections -Xlinker -print-memory-usage -mcpu=cortex-m0plus -mthumb -T SPO2_HR_Debug.ld -o "SPO2_HR.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) SPO2_HR.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "SPO2_HR.axf"; # arm-none-eabi-objcopy -v -O binary "SPO2_HR.axf" "SPO2_HR.bin" ; # checksum -p LPC845 -d "SPO2_HR.bin";
	-@echo ' '

.PHONY: all clean dependents main-build post-build

-include ../makefile.targets
