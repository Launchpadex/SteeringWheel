################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/lvgl/examples/layouts/flex/lv_example_flex_1.c \
../Application/lvgl/examples/layouts/flex/lv_example_flex_2.c \
../Application/lvgl/examples/layouts/flex/lv_example_flex_3.c \
../Application/lvgl/examples/layouts/flex/lv_example_flex_4.c \
../Application/lvgl/examples/layouts/flex/lv_example_flex_5.c \
../Application/lvgl/examples/layouts/flex/lv_example_flex_6.c 

OBJS += \
./Application/lvgl/examples/layouts/flex/lv_example_flex_1.o \
./Application/lvgl/examples/layouts/flex/lv_example_flex_2.o \
./Application/lvgl/examples/layouts/flex/lv_example_flex_3.o \
./Application/lvgl/examples/layouts/flex/lv_example_flex_4.o \
./Application/lvgl/examples/layouts/flex/lv_example_flex_5.o \
./Application/lvgl/examples/layouts/flex/lv_example_flex_6.o 

C_DEPS += \
./Application/lvgl/examples/layouts/flex/lv_example_flex_1.d \
./Application/lvgl/examples/layouts/flex/lv_example_flex_2.d \
./Application/lvgl/examples/layouts/flex/lv_example_flex_3.d \
./Application/lvgl/examples/layouts/flex/lv_example_flex_4.d \
./Application/lvgl/examples/layouts/flex/lv_example_flex_5.d \
./Application/lvgl/examples/layouts/flex/lv_example_flex_6.d 


# Each subdirectory must supply rules for building sources it contributes
Application/lvgl/examples/layouts/flex/%.o Application/lvgl/examples/layouts/flex/%.su Application/lvgl/examples/layouts/flex/%.cyclo: ../Application/lvgl/examples/layouts/flex/%.c Application/lvgl/examples/layouts/flex/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../USB_Device/App -I../USB_Device/Target -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/System/Inc" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/lvgl" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/ui" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/Display" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-lvgl-2f-examples-2f-layouts-2f-flex

clean-Application-2f-lvgl-2f-examples-2f-layouts-2f-flex:
	-$(RM) ./Application/lvgl/examples/layouts/flex/lv_example_flex_1.cyclo ./Application/lvgl/examples/layouts/flex/lv_example_flex_1.d ./Application/lvgl/examples/layouts/flex/lv_example_flex_1.o ./Application/lvgl/examples/layouts/flex/lv_example_flex_1.su ./Application/lvgl/examples/layouts/flex/lv_example_flex_2.cyclo ./Application/lvgl/examples/layouts/flex/lv_example_flex_2.d ./Application/lvgl/examples/layouts/flex/lv_example_flex_2.o ./Application/lvgl/examples/layouts/flex/lv_example_flex_2.su ./Application/lvgl/examples/layouts/flex/lv_example_flex_3.cyclo ./Application/lvgl/examples/layouts/flex/lv_example_flex_3.d ./Application/lvgl/examples/layouts/flex/lv_example_flex_3.o ./Application/lvgl/examples/layouts/flex/lv_example_flex_3.su ./Application/lvgl/examples/layouts/flex/lv_example_flex_4.cyclo ./Application/lvgl/examples/layouts/flex/lv_example_flex_4.d ./Application/lvgl/examples/layouts/flex/lv_example_flex_4.o ./Application/lvgl/examples/layouts/flex/lv_example_flex_4.su ./Application/lvgl/examples/layouts/flex/lv_example_flex_5.cyclo ./Application/lvgl/examples/layouts/flex/lv_example_flex_5.d ./Application/lvgl/examples/layouts/flex/lv_example_flex_5.o ./Application/lvgl/examples/layouts/flex/lv_example_flex_5.su ./Application/lvgl/examples/layouts/flex/lv_example_flex_6.cyclo ./Application/lvgl/examples/layouts/flex/lv_example_flex_6.d ./Application/lvgl/examples/layouts/flex/lv_example_flex_6.o ./Application/lvgl/examples/layouts/flex/lv_example_flex_6.su

.PHONY: clean-Application-2f-lvgl-2f-examples-2f-layouts-2f-flex

