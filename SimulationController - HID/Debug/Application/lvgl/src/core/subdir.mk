################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/lvgl/src/core/lv_group.c \
../Application/lvgl/src/core/lv_obj.c \
../Application/lvgl/src/core/lv_obj_class.c \
../Application/lvgl/src/core/lv_obj_draw.c \
../Application/lvgl/src/core/lv_obj_event.c \
../Application/lvgl/src/core/lv_obj_id_builtin.c \
../Application/lvgl/src/core/lv_obj_pos.c \
../Application/lvgl/src/core/lv_obj_property.c \
../Application/lvgl/src/core/lv_obj_scroll.c \
../Application/lvgl/src/core/lv_obj_style.c \
../Application/lvgl/src/core/lv_obj_style_gen.c \
../Application/lvgl/src/core/lv_obj_tree.c \
../Application/lvgl/src/core/lv_refr.c 

OBJS += \
./Application/lvgl/src/core/lv_group.o \
./Application/lvgl/src/core/lv_obj.o \
./Application/lvgl/src/core/lv_obj_class.o \
./Application/lvgl/src/core/lv_obj_draw.o \
./Application/lvgl/src/core/lv_obj_event.o \
./Application/lvgl/src/core/lv_obj_id_builtin.o \
./Application/lvgl/src/core/lv_obj_pos.o \
./Application/lvgl/src/core/lv_obj_property.o \
./Application/lvgl/src/core/lv_obj_scroll.o \
./Application/lvgl/src/core/lv_obj_style.o \
./Application/lvgl/src/core/lv_obj_style_gen.o \
./Application/lvgl/src/core/lv_obj_tree.o \
./Application/lvgl/src/core/lv_refr.o 

C_DEPS += \
./Application/lvgl/src/core/lv_group.d \
./Application/lvgl/src/core/lv_obj.d \
./Application/lvgl/src/core/lv_obj_class.d \
./Application/lvgl/src/core/lv_obj_draw.d \
./Application/lvgl/src/core/lv_obj_event.d \
./Application/lvgl/src/core/lv_obj_id_builtin.d \
./Application/lvgl/src/core/lv_obj_pos.d \
./Application/lvgl/src/core/lv_obj_property.d \
./Application/lvgl/src/core/lv_obj_scroll.d \
./Application/lvgl/src/core/lv_obj_style.d \
./Application/lvgl/src/core/lv_obj_style_gen.d \
./Application/lvgl/src/core/lv_obj_tree.d \
./Application/lvgl/src/core/lv_refr.d 


# Each subdirectory must supply rules for building sources it contributes
Application/lvgl/src/core/%.o Application/lvgl/src/core/%.su Application/lvgl/src/core/%.cyclo: ../Application/lvgl/src/core/%.c Application/lvgl/src/core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../USB_Device/App -I../USB_Device/Target -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/System/Inc" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/lvgl" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/ui" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/Display" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-lvgl-2f-src-2f-core

clean-Application-2f-lvgl-2f-src-2f-core:
	-$(RM) ./Application/lvgl/src/core/lv_group.cyclo ./Application/lvgl/src/core/lv_group.d ./Application/lvgl/src/core/lv_group.o ./Application/lvgl/src/core/lv_group.su ./Application/lvgl/src/core/lv_obj.cyclo ./Application/lvgl/src/core/lv_obj.d ./Application/lvgl/src/core/lv_obj.o ./Application/lvgl/src/core/lv_obj.su ./Application/lvgl/src/core/lv_obj_class.cyclo ./Application/lvgl/src/core/lv_obj_class.d ./Application/lvgl/src/core/lv_obj_class.o ./Application/lvgl/src/core/lv_obj_class.su ./Application/lvgl/src/core/lv_obj_draw.cyclo ./Application/lvgl/src/core/lv_obj_draw.d ./Application/lvgl/src/core/lv_obj_draw.o ./Application/lvgl/src/core/lv_obj_draw.su ./Application/lvgl/src/core/lv_obj_event.cyclo ./Application/lvgl/src/core/lv_obj_event.d ./Application/lvgl/src/core/lv_obj_event.o ./Application/lvgl/src/core/lv_obj_event.su ./Application/lvgl/src/core/lv_obj_id_builtin.cyclo ./Application/lvgl/src/core/lv_obj_id_builtin.d ./Application/lvgl/src/core/lv_obj_id_builtin.o ./Application/lvgl/src/core/lv_obj_id_builtin.su ./Application/lvgl/src/core/lv_obj_pos.cyclo ./Application/lvgl/src/core/lv_obj_pos.d ./Application/lvgl/src/core/lv_obj_pos.o ./Application/lvgl/src/core/lv_obj_pos.su ./Application/lvgl/src/core/lv_obj_property.cyclo ./Application/lvgl/src/core/lv_obj_property.d ./Application/lvgl/src/core/lv_obj_property.o ./Application/lvgl/src/core/lv_obj_property.su ./Application/lvgl/src/core/lv_obj_scroll.cyclo ./Application/lvgl/src/core/lv_obj_scroll.d ./Application/lvgl/src/core/lv_obj_scroll.o ./Application/lvgl/src/core/lv_obj_scroll.su ./Application/lvgl/src/core/lv_obj_style.cyclo ./Application/lvgl/src/core/lv_obj_style.d ./Application/lvgl/src/core/lv_obj_style.o ./Application/lvgl/src/core/lv_obj_style.su ./Application/lvgl/src/core/lv_obj_style_gen.cyclo ./Application/lvgl/src/core/lv_obj_style_gen.d ./Application/lvgl/src/core/lv_obj_style_gen.o ./Application/lvgl/src/core/lv_obj_style_gen.su ./Application/lvgl/src/core/lv_obj_tree.cyclo ./Application/lvgl/src/core/lv_obj_tree.d ./Application/lvgl/src/core/lv_obj_tree.o ./Application/lvgl/src/core/lv_obj_tree.su ./Application/lvgl/src/core/lv_refr.cyclo ./Application/lvgl/src/core/lv_refr.d ./Application/lvgl/src/core/lv_refr.o ./Application/lvgl/src/core/lv_refr.su

.PHONY: clean-Application-2f-lvgl-2f-src-2f-core

