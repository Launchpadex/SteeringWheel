################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/ui/actions.c \
../Application/ui/images.c \
../Application/ui/screens.c \
../Application/ui/styles.c \
../Application/ui/ui.c \
../Application/ui/vars.c 

OBJS += \
./Application/ui/actions.o \
./Application/ui/images.o \
./Application/ui/screens.o \
./Application/ui/styles.o \
./Application/ui/ui.o \
./Application/ui/vars.o 

C_DEPS += \
./Application/ui/actions.d \
./Application/ui/images.d \
./Application/ui/screens.d \
./Application/ui/styles.d \
./Application/ui/ui.d \
./Application/ui/vars.d 


# Each subdirectory must supply rules for building sources it contributes
Application/ui/%.o Application/ui/%.su Application/ui/%.cyclo: ../Application/ui/%.c Application/ui/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../USB_Device/App -I../USB_Device/Target -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/System/Inc" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/lvgl" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/ui" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/Display" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-ui

clean-Application-2f-ui:
	-$(RM) ./Application/ui/actions.cyclo ./Application/ui/actions.d ./Application/ui/actions.o ./Application/ui/actions.su ./Application/ui/images.cyclo ./Application/ui/images.d ./Application/ui/images.o ./Application/ui/images.su ./Application/ui/screens.cyclo ./Application/ui/screens.d ./Application/ui/screens.o ./Application/ui/screens.su ./Application/ui/styles.cyclo ./Application/ui/styles.d ./Application/ui/styles.o ./Application/ui/styles.su ./Application/ui/ui.cyclo ./Application/ui/ui.d ./Application/ui/ui.o ./Application/ui/ui.su ./Application/ui/vars.cyclo ./Application/ui/vars.d ./Application/ui/vars.o ./Application/ui/vars.su

.PHONY: clean-Application-2f-ui

