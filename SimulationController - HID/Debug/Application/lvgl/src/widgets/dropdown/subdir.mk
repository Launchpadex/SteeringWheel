################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/lvgl/src/widgets/dropdown/lv_dropdown.c 

OBJS += \
./Application/lvgl/src/widgets/dropdown/lv_dropdown.o 

C_DEPS += \
./Application/lvgl/src/widgets/dropdown/lv_dropdown.d 


# Each subdirectory must supply rules for building sources it contributes
Application/lvgl/src/widgets/dropdown/%.o Application/lvgl/src/widgets/dropdown/%.su Application/lvgl/src/widgets/dropdown/%.cyclo: ../Application/lvgl/src/widgets/dropdown/%.c Application/lvgl/src/widgets/dropdown/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../USB_Device/App -I../USB_Device/Target -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/System/Inc" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/lvgl" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/ui" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/Display" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-lvgl-2f-src-2f-widgets-2f-dropdown

clean-Application-2f-lvgl-2f-src-2f-widgets-2f-dropdown:
	-$(RM) ./Application/lvgl/src/widgets/dropdown/lv_dropdown.cyclo ./Application/lvgl/src/widgets/dropdown/lv_dropdown.d ./Application/lvgl/src/widgets/dropdown/lv_dropdown.o ./Application/lvgl/src/widgets/dropdown/lv_dropdown.su

.PHONY: clean-Application-2f-lvgl-2f-src-2f-widgets-2f-dropdown

