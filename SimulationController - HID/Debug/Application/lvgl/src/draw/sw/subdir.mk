################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/lvgl/src/draw/sw/lv_draw_sw.c \
../Application/lvgl/src/draw/sw/lv_draw_sw_arc.c \
../Application/lvgl/src/draw/sw/lv_draw_sw_border.c \
../Application/lvgl/src/draw/sw/lv_draw_sw_box_shadow.c \
../Application/lvgl/src/draw/sw/lv_draw_sw_fill.c \
../Application/lvgl/src/draw/sw/lv_draw_sw_gradient.c \
../Application/lvgl/src/draw/sw/lv_draw_sw_img.c \
../Application/lvgl/src/draw/sw/lv_draw_sw_letter.c \
../Application/lvgl/src/draw/sw/lv_draw_sw_line.c \
../Application/lvgl/src/draw/sw/lv_draw_sw_mask.c \
../Application/lvgl/src/draw/sw/lv_draw_sw_mask_rect.c \
../Application/lvgl/src/draw/sw/lv_draw_sw_transform.c \
../Application/lvgl/src/draw/sw/lv_draw_sw_triangle.c \
../Application/lvgl/src/draw/sw/lv_draw_sw_utils.c \
../Application/lvgl/src/draw/sw/lv_draw_sw_vector.c 

OBJS += \
./Application/lvgl/src/draw/sw/lv_draw_sw.o \
./Application/lvgl/src/draw/sw/lv_draw_sw_arc.o \
./Application/lvgl/src/draw/sw/lv_draw_sw_border.o \
./Application/lvgl/src/draw/sw/lv_draw_sw_box_shadow.o \
./Application/lvgl/src/draw/sw/lv_draw_sw_fill.o \
./Application/lvgl/src/draw/sw/lv_draw_sw_gradient.o \
./Application/lvgl/src/draw/sw/lv_draw_sw_img.o \
./Application/lvgl/src/draw/sw/lv_draw_sw_letter.o \
./Application/lvgl/src/draw/sw/lv_draw_sw_line.o \
./Application/lvgl/src/draw/sw/lv_draw_sw_mask.o \
./Application/lvgl/src/draw/sw/lv_draw_sw_mask_rect.o \
./Application/lvgl/src/draw/sw/lv_draw_sw_transform.o \
./Application/lvgl/src/draw/sw/lv_draw_sw_triangle.o \
./Application/lvgl/src/draw/sw/lv_draw_sw_utils.o \
./Application/lvgl/src/draw/sw/lv_draw_sw_vector.o 

C_DEPS += \
./Application/lvgl/src/draw/sw/lv_draw_sw.d \
./Application/lvgl/src/draw/sw/lv_draw_sw_arc.d \
./Application/lvgl/src/draw/sw/lv_draw_sw_border.d \
./Application/lvgl/src/draw/sw/lv_draw_sw_box_shadow.d \
./Application/lvgl/src/draw/sw/lv_draw_sw_fill.d \
./Application/lvgl/src/draw/sw/lv_draw_sw_gradient.d \
./Application/lvgl/src/draw/sw/lv_draw_sw_img.d \
./Application/lvgl/src/draw/sw/lv_draw_sw_letter.d \
./Application/lvgl/src/draw/sw/lv_draw_sw_line.d \
./Application/lvgl/src/draw/sw/lv_draw_sw_mask.d \
./Application/lvgl/src/draw/sw/lv_draw_sw_mask_rect.d \
./Application/lvgl/src/draw/sw/lv_draw_sw_transform.d \
./Application/lvgl/src/draw/sw/lv_draw_sw_triangle.d \
./Application/lvgl/src/draw/sw/lv_draw_sw_utils.d \
./Application/lvgl/src/draw/sw/lv_draw_sw_vector.d 


# Each subdirectory must supply rules for building sources it contributes
Application/lvgl/src/draw/sw/%.o Application/lvgl/src/draw/sw/%.su Application/lvgl/src/draw/sw/%.cyclo: ../Application/lvgl/src/draw/sw/%.c Application/lvgl/src/draw/sw/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../USB_Device/App -I../USB_Device/Target -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/System/Inc" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/lvgl" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/ui" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/Display" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-lvgl-2f-src-2f-draw-2f-sw

clean-Application-2f-lvgl-2f-src-2f-draw-2f-sw:
	-$(RM) ./Application/lvgl/src/draw/sw/lv_draw_sw.cyclo ./Application/lvgl/src/draw/sw/lv_draw_sw.d ./Application/lvgl/src/draw/sw/lv_draw_sw.o ./Application/lvgl/src/draw/sw/lv_draw_sw.su ./Application/lvgl/src/draw/sw/lv_draw_sw_arc.cyclo ./Application/lvgl/src/draw/sw/lv_draw_sw_arc.d ./Application/lvgl/src/draw/sw/lv_draw_sw_arc.o ./Application/lvgl/src/draw/sw/lv_draw_sw_arc.su ./Application/lvgl/src/draw/sw/lv_draw_sw_border.cyclo ./Application/lvgl/src/draw/sw/lv_draw_sw_border.d ./Application/lvgl/src/draw/sw/lv_draw_sw_border.o ./Application/lvgl/src/draw/sw/lv_draw_sw_border.su ./Application/lvgl/src/draw/sw/lv_draw_sw_box_shadow.cyclo ./Application/lvgl/src/draw/sw/lv_draw_sw_box_shadow.d ./Application/lvgl/src/draw/sw/lv_draw_sw_box_shadow.o ./Application/lvgl/src/draw/sw/lv_draw_sw_box_shadow.su ./Application/lvgl/src/draw/sw/lv_draw_sw_fill.cyclo ./Application/lvgl/src/draw/sw/lv_draw_sw_fill.d ./Application/lvgl/src/draw/sw/lv_draw_sw_fill.o ./Application/lvgl/src/draw/sw/lv_draw_sw_fill.su ./Application/lvgl/src/draw/sw/lv_draw_sw_gradient.cyclo ./Application/lvgl/src/draw/sw/lv_draw_sw_gradient.d ./Application/lvgl/src/draw/sw/lv_draw_sw_gradient.o ./Application/lvgl/src/draw/sw/lv_draw_sw_gradient.su ./Application/lvgl/src/draw/sw/lv_draw_sw_img.cyclo ./Application/lvgl/src/draw/sw/lv_draw_sw_img.d ./Application/lvgl/src/draw/sw/lv_draw_sw_img.o ./Application/lvgl/src/draw/sw/lv_draw_sw_img.su ./Application/lvgl/src/draw/sw/lv_draw_sw_letter.cyclo ./Application/lvgl/src/draw/sw/lv_draw_sw_letter.d ./Application/lvgl/src/draw/sw/lv_draw_sw_letter.o ./Application/lvgl/src/draw/sw/lv_draw_sw_letter.su ./Application/lvgl/src/draw/sw/lv_draw_sw_line.cyclo ./Application/lvgl/src/draw/sw/lv_draw_sw_line.d ./Application/lvgl/src/draw/sw/lv_draw_sw_line.o ./Application/lvgl/src/draw/sw/lv_draw_sw_line.su ./Application/lvgl/src/draw/sw/lv_draw_sw_mask.cyclo ./Application/lvgl/src/draw/sw/lv_draw_sw_mask.d ./Application/lvgl/src/draw/sw/lv_draw_sw_mask.o ./Application/lvgl/src/draw/sw/lv_draw_sw_mask.su ./Application/lvgl/src/draw/sw/lv_draw_sw_mask_rect.cyclo ./Application/lvgl/src/draw/sw/lv_draw_sw_mask_rect.d ./Application/lvgl/src/draw/sw/lv_draw_sw_mask_rect.o ./Application/lvgl/src/draw/sw/lv_draw_sw_mask_rect.su ./Application/lvgl/src/draw/sw/lv_draw_sw_transform.cyclo ./Application/lvgl/src/draw/sw/lv_draw_sw_transform.d ./Application/lvgl/src/draw/sw/lv_draw_sw_transform.o ./Application/lvgl/src/draw/sw/lv_draw_sw_transform.su ./Application/lvgl/src/draw/sw/lv_draw_sw_triangle.cyclo ./Application/lvgl/src/draw/sw/lv_draw_sw_triangle.d ./Application/lvgl/src/draw/sw/lv_draw_sw_triangle.o ./Application/lvgl/src/draw/sw/lv_draw_sw_triangle.su ./Application/lvgl/src/draw/sw/lv_draw_sw_utils.cyclo ./Application/lvgl/src/draw/sw/lv_draw_sw_utils.d ./Application/lvgl/src/draw/sw/lv_draw_sw_utils.o ./Application/lvgl/src/draw/sw/lv_draw_sw_utils.su ./Application/lvgl/src/draw/sw/lv_draw_sw_vector.cyclo ./Application/lvgl/src/draw/sw/lv_draw_sw_vector.d ./Application/lvgl/src/draw/sw/lv_draw_sw_vector.o ./Application/lvgl/src/draw/sw/lv_draw_sw_vector.su

.PHONY: clean-Application-2f-lvgl-2f-src-2f-draw-2f-sw

