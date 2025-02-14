################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Drivers_LPC845/sensor/MAX30102.cpp 

CPP_DEPS += \
./Drivers_LPC845/sensor/MAX30102.d 

OBJS += \
./Drivers_LPC845/sensor/MAX30102.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers_LPC845/sensor/%.o: ../Drivers_LPC845/sensor/%.cpp Drivers_LPC845/sensor/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -DDEBUG -D__CODE_RED -D__NEWLIB__ -I"C:\Users\Facun\Documents\MCUXpressoIDE_11.10.0_3148\workspace\SPO2_HR" -I"C:\Users\Facun\Documents\MCUXpressoIDE_11.10.0_3148\workspace\SPO2_HR\Drivers_LPC845\pinInt" -I"C:\Users\Facun\Documents\MCUXpressoIDE_11.10.0_3148\workspace\SPO2_HR\Drivers_LPC845\systick" -I"C:\Users\Facun\Documents\MCUXpressoIDE_11.10.0_3148\workspace\SPO2_HR\Drivers_LPC845\perifericoTemporizado" -I"C:\Users\Facun\Documents\MCUXpressoIDE_11.10.0_3148\workspace\SPO2_HR\Utils\queue" -I"C:\Users\Facun\Documents\MCUXpressoIDE_11.10.0_3148\workspace\SPO2_HR\Drivers_LPC845\sensor" -I"C:\Users\Facun\Documents\MCUXpressoIDE_11.10.0_3148\workspace\SPO2_HR\Drivers_LPC845" -I"C:\Users\Facun\Documents\MCUXpressoIDE_11.10.0_3148\workspace\SPO2_HR\Drivers_LPC845\gpio" -I"C:\Users\Facun\Documents\MCUXpressoIDE_11.10.0_3148\workspace\SPO2_HR\Drivers_LPC845\I2C" -I"C:\Users\Facun\Documents\MCUXpressoIDE_11.10.0_3148\workspace\SPO2_HR\Drivers_LPC845\SerialCom" -I"C:\Users\Facun\Documents\MCUXpressoIDE_11.10.0_3148\workspace\SPO2_HR\Drivers_LPC845\timer" -I"C:\Users\Facun\Documents\MCUXpressoIDE_11.10.0_3148\workspace\SPO2_HR\src" -I"C:\Users\Facun\Documents\MCUXpressoIDE_11.10.0_3148\workspace\SPO2_HR\Utils" -I"C:\Users\Facun\Documents\MCUXpressoIDE_11.10.0_3148\workspace\SPO2_HR\Utils\strings" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__NEWLIB__ -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Drivers_LPC845-2f-sensor

clean-Drivers_LPC845-2f-sensor:
	-$(RM) ./Drivers_LPC845/sensor/MAX30102.d ./Drivers_LPC845/sensor/MAX30102.o

.PHONY: clean-Drivers_LPC845-2f-sensor

