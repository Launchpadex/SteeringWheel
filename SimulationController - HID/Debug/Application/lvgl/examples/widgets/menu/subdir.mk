################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/lvgl/examples/widgets/menu/lv_example_menu_1.c \
../Application/lvgl/examples/widgets/menu/lv_example_menu_2.c \
../Application/lvgl/examples/widgets/menu/lv_example_menu_3.c \
../Application/lvgl/examples/widgets/menu/lv_example_menu_4.c \
../Application/lvgl/examples/widgets/menu/lv_example_menu_5.c 

OBJS += \
./Application/lvgl/examples/widgets/menu/lv_example_menu_1.o \
./Application/lvgl/examples/widgets/menu/lv_example_menu_2.o \
./Application/lvgl/examples/widgets/menu/lv_example_menu_3.o \
./Application/lvgl/examples/widgets/menu/lv_example_menu_4.o \
./Application/lvgl/examples/widgets/menu/lv_example_menu_5.o 

C_DEPS += \
./Application/lvgl/examples/widgets/menu/lv_example_menu_1.d \
./Application/lvgl/examples/widgets/menu/lv_example_menu_2.d \
./Application/lvgl/examples/widgets/menu/lv_example_menu_3.d \
./Application/lvgl/examples/widgets/menu/lv_example_menu_4.d \
./Application/lvgl/examples/widgets/menu/lv_example_menu_5.d 


# Each subdirectory must supply rules for building sources it contributes
Application/lvgl/examples/widgets/menu/%.o Application/lvgl/examples/widgets/menu/%.su Application/lvgl/examples/widgets/menu/%.cyclo: ../Application/lvgl/examples/widgets/menu/%.c Application/lvgl/examples/widgets/menu/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../USB_Device/App -I../USB_Device/Target -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/System/Inc" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/lvgl" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/ui" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/Display" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-lvgl-2f-examples-2f-widgets-2f-menu

clean-Application-2f-lvgl-2f-examples-2f-widgets-2f-menu:
	-$(RM) ./Application/lvgl/examples/widgets/menu/lv_example_menu_1.cyclo ./Application/lvgl/examples/widgets/menu/lv_example_menu_1.d ./Application/lvgl/examples/widgets/menu/lv_example_menu_1.o ./Application/lvgl/examples/widgets/menu/lv_example_menu_1.su ./Application/lvgl/examples/widgets/menu/lv_example_menu_2.cyclo ./Application/lvgl/examples/widgets/menu/lv_example_menu_2.d ./Application/lvgl/examples/widgets/menu/lv_example_menu_2.o ./Application/lvgl/examples/widgets/menu/lv_example_menu_2.su ./Application/lvgl/examples/widgets/menu/lv_example_menu_3.cyclo ./Application/lvgl/examples/widgets/menu/lv_example_menu_3.d ./Application/lvgl/examples/widgets/menu/lv_example_menu_3.o ./Application/lvgl/examples/widgets/menu/lv_example_menu_3.su ./Application/lvgl/examples/widgets/menu/lv_example_menu_4.cyclo ./Application/lvgl/examples/widgets/menu/lv_example_menu_4.d ./Application/lvgl/examples/widgets/menu/lv_example_menu_4.o ./Application/lvgl/examples/widgets/menu/lv_example_menu_4.su ./Application/lvgl/examples/widgets/menu/lv_example_menu_5.cyclo ./Application/lvgl/examples/widgets/menu/lv_example_menu_5.d ./Application/lvgl/examples/widgets/menu/lv_example_menu_5.o ./Application/lvgl/examples/widgets/menu/lv_example_menu_5.su

.PHONY: clean-Application-2f-lvgl-2f-examples-2f-widgets-2f-menu

