################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/lvgl/src/widgets/property/lv_animimage_properties.c \
../Application/lvgl/src/widgets/property/lv_dropdown_properties.c \
../Application/lvgl/src/widgets/property/lv_image_properties.c \
../Application/lvgl/src/widgets/property/lv_keyboard_properties.c \
../Application/lvgl/src/widgets/property/lv_label_properties.c \
../Application/lvgl/src/widgets/property/lv_obj_properties.c \
../Application/lvgl/src/widgets/property/lv_roller_properties.c \
../Application/lvgl/src/widgets/property/lv_slider_properties.c \
../Application/lvgl/src/widgets/property/lv_style_properties.c \
../Application/lvgl/src/widgets/property/lv_textarea_properties.c 

OBJS += \
./Application/lvgl/src/widgets/property/lv_animimage_properties.o \
./Application/lvgl/src/widgets/property/lv_dropdown_properties.o \
./Application/lvgl/src/widgets/property/lv_image_properties.o \
./Application/lvgl/src/widgets/property/lv_keyboard_properties.o \
./Application/lvgl/src/widgets/property/lv_label_properties.o \
./Application/lvgl/src/widgets/property/lv_obj_properties.o \
./Application/lvgl/src/widgets/property/lv_roller_properties.o \
./Application/lvgl/src/widgets/property/lv_slider_properties.o \
./Application/lvgl/src/widgets/property/lv_style_properties.o \
./Application/lvgl/src/widgets/property/lv_textarea_properties.o 

C_DEPS += \
./Application/lvgl/src/widgets/property/lv_animimage_properties.d \
./Application/lvgl/src/widgets/property/lv_dropdown_properties.d \
./Application/lvgl/src/widgets/property/lv_image_properties.d \
./Application/lvgl/src/widgets/property/lv_keyboard_properties.d \
./Application/lvgl/src/widgets/property/lv_label_properties.d \
./Application/lvgl/src/widgets/property/lv_obj_properties.d \
./Application/lvgl/src/widgets/property/lv_roller_properties.d \
./Application/lvgl/src/widgets/property/lv_slider_properties.d \
./Application/lvgl/src/widgets/property/lv_style_properties.d \
./Application/lvgl/src/widgets/property/lv_textarea_properties.d 


# Each subdirectory must supply rules for building sources it contributes
Application/lvgl/src/widgets/property/%.o Application/lvgl/src/widgets/property/%.su Application/lvgl/src/widgets/property/%.cyclo: ../Application/lvgl/src/widgets/property/%.c Application/lvgl/src/widgets/property/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../USB_Device/App -I../USB_Device/Target -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/System/Inc" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/lvgl" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/ui" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/Display" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-lvgl-2f-src-2f-widgets-2f-property

clean-Application-2f-lvgl-2f-src-2f-widgets-2f-property:
	-$(RM) ./Application/lvgl/src/widgets/property/lv_animimage_properties.cyclo ./Application/lvgl/src/widgets/property/lv_animimage_properties.d ./Application/lvgl/src/widgets/property/lv_animimage_properties.o ./Application/lvgl/src/widgets/property/lv_animimage_properties.su ./Application/lvgl/src/widgets/property/lv_dropdown_properties.cyclo ./Application/lvgl/src/widgets/property/lv_dropdown_properties.d ./Application/lvgl/src/widgets/property/lv_dropdown_properties.o ./Application/lvgl/src/widgets/property/lv_dropdown_properties.su ./Application/lvgl/src/widgets/property/lv_image_properties.cyclo ./Application/lvgl/src/widgets/property/lv_image_properties.d ./Application/lvgl/src/widgets/property/lv_image_properties.o ./Application/lvgl/src/widgets/property/lv_image_properties.su ./Application/lvgl/src/widgets/property/lv_keyboard_properties.cyclo ./Application/lvgl/src/widgets/property/lv_keyboard_properties.d ./Application/lvgl/src/widgets/property/lv_keyboard_properties.o ./Application/lvgl/src/widgets/property/lv_keyboard_properties.su ./Application/lvgl/src/widgets/property/lv_label_properties.cyclo ./Application/lvgl/src/widgets/property/lv_label_properties.d ./Application/lvgl/src/widgets/property/lv_label_properties.o ./Application/lvgl/src/widgets/property/lv_label_properties.su ./Application/lvgl/src/widgets/property/lv_obj_properties.cyclo ./Application/lvgl/src/widgets/property/lv_obj_properties.d ./Application/lvgl/src/widgets/property/lv_obj_properties.o ./Application/lvgl/src/widgets/property/lv_obj_properties.su ./Application/lvgl/src/widgets/property/lv_roller_properties.cyclo ./Application/lvgl/src/widgets/property/lv_roller_properties.d ./Application/lvgl/src/widgets/property/lv_roller_properties.o ./Application/lvgl/src/widgets/property/lv_roller_properties.su ./Application/lvgl/src/widgets/property/lv_slider_properties.cyclo ./Application/lvgl/src/widgets/property/lv_slider_properties.d ./Application/lvgl/src/widgets/property/lv_slider_properties.o ./Application/lvgl/src/widgets/property/lv_slider_properties.su ./Application/lvgl/src/widgets/property/lv_style_properties.cyclo ./Application/lvgl/src/widgets/property/lv_style_properties.d ./Application/lvgl/src/widgets/property/lv_style_properties.o ./Application/lvgl/src/widgets/property/lv_style_properties.su ./Application/lvgl/src/widgets/property/lv_textarea_properties.cyclo ./Application/lvgl/src/widgets/property/lv_textarea_properties.d ./Application/lvgl/src/widgets/property/lv_textarea_properties.o ./Application/lvgl/src/widgets/property/lv_textarea_properties.su

.PHONY: clean-Application-2f-lvgl-2f-src-2f-widgets-2f-property

