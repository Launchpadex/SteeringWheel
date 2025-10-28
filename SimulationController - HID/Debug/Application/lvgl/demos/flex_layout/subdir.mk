################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/lvgl/demos/flex_layout/lv_demo_flex_layout_ctrl_pad.c \
../Application/lvgl/demos/flex_layout/lv_demo_flex_layout_flex_loader.c \
../Application/lvgl/demos/flex_layout/lv_demo_flex_layout_main.c \
../Application/lvgl/demos/flex_layout/lv_demo_flex_layout_view.c \
../Application/lvgl/demos/flex_layout/lv_demo_flex_layout_view_child_node.c \
../Application/lvgl/demos/flex_layout/lv_demo_flex_layout_view_ctrl_pad.c 

OBJS += \
./Application/lvgl/demos/flex_layout/lv_demo_flex_layout_ctrl_pad.o \
./Application/lvgl/demos/flex_layout/lv_demo_flex_layout_flex_loader.o \
./Application/lvgl/demos/flex_layout/lv_demo_flex_layout_main.o \
./Application/lvgl/demos/flex_layout/lv_demo_flex_layout_view.o \
./Application/lvgl/demos/flex_layout/lv_demo_flex_layout_view_child_node.o \
./Application/lvgl/demos/flex_layout/lv_demo_flex_layout_view_ctrl_pad.o 

C_DEPS += \
./Application/lvgl/demos/flex_layout/lv_demo_flex_layout_ctrl_pad.d \
./Application/lvgl/demos/flex_layout/lv_demo_flex_layout_flex_loader.d \
./Application/lvgl/demos/flex_layout/lv_demo_flex_layout_main.d \
./Application/lvgl/demos/flex_layout/lv_demo_flex_layout_view.d \
./Application/lvgl/demos/flex_layout/lv_demo_flex_layout_view_child_node.d \
./Application/lvgl/demos/flex_layout/lv_demo_flex_layout_view_ctrl_pad.d 


# Each subdirectory must supply rules for building sources it contributes
Application/lvgl/demos/flex_layout/%.o Application/lvgl/demos/flex_layout/%.su Application/lvgl/demos/flex_layout/%.cyclo: ../Application/lvgl/demos/flex_layout/%.c Application/lvgl/demos/flex_layout/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../USB_Device/App -I../USB_Device/Target -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/System/Inc" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/lvgl" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/ui" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/Display" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-lvgl-2f-demos-2f-flex_layout

clean-Application-2f-lvgl-2f-demos-2f-flex_layout:
	-$(RM) ./Application/lvgl/demos/flex_layout/lv_demo_flex_layout_ctrl_pad.cyclo ./Application/lvgl/demos/flex_layout/lv_demo_flex_layout_ctrl_pad.d ./Application/lvgl/demos/flex_layout/lv_demo_flex_layout_ctrl_pad.o ./Application/lvgl/demos/flex_layout/lv_demo_flex_layout_ctrl_pad.su ./Application/lvgl/demos/flex_layout/lv_demo_flex_layout_flex_loader.cyclo ./Application/lvgl/demos/flex_layout/lv_demo_flex_layout_flex_loader.d ./Application/lvgl/demos/flex_layout/lv_demo_flex_layout_flex_loader.o ./Application/lvgl/demos/flex_layout/lv_demo_flex_layout_flex_loader.su ./Application/lvgl/demos/flex_layout/lv_demo_flex_layout_main.cyclo ./Application/lvgl/demos/flex_layout/lv_demo_flex_layout_main.d ./Application/lvgl/demos/flex_layout/lv_demo_flex_layout_main.o ./Application/lvgl/demos/flex_layout/lv_demo_flex_layout_main.su ./Application/lvgl/demos/flex_layout/lv_demo_flex_layout_view.cyclo ./Application/lvgl/demos/flex_layout/lv_demo_flex_layout_view.d ./Application/lvgl/demos/flex_layout/lv_demo_flex_layout_view.o ./Application/lvgl/demos/flex_layout/lv_demo_flex_layout_view.su ./Application/lvgl/demos/flex_layout/lv_demo_flex_layout_view_child_node.cyclo ./Application/lvgl/demos/flex_layout/lv_demo_flex_layout_view_child_node.d ./Application/lvgl/demos/flex_layout/lv_demo_flex_layout_view_child_node.o ./Application/lvgl/demos/flex_layout/lv_demo_flex_layout_view_child_node.su ./Application/lvgl/demos/flex_layout/lv_demo_flex_layout_view_ctrl_pad.cyclo ./Application/lvgl/demos/flex_layout/lv_demo_flex_layout_view_ctrl_pad.d ./Application/lvgl/demos/flex_layout/lv_demo_flex_layout_view_ctrl_pad.o ./Application/lvgl/demos/flex_layout/lv_demo_flex_layout_view_ctrl_pad.su

.PHONY: clean-Application-2f-lvgl-2f-demos-2f-flex_layout

