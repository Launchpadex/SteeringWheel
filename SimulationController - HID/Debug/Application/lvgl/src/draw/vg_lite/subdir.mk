################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/lvgl/src/draw/vg_lite/lv_draw_buf_vg_lite.c \
../Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite.c \
../Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_arc.c \
../Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_border.c \
../Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_box_shadow.c \
../Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_fill.c \
../Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_img.c \
../Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_label.c \
../Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_layer.c \
../Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_line.c \
../Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_mask_rect.c \
../Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_triangle.c \
../Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_vector.c \
../Application/lvgl/src/draw/vg_lite/lv_vg_lite_decoder.c \
../Application/lvgl/src/draw/vg_lite/lv_vg_lite_grad.c \
../Application/lvgl/src/draw/vg_lite/lv_vg_lite_math.c \
../Application/lvgl/src/draw/vg_lite/lv_vg_lite_path.c \
../Application/lvgl/src/draw/vg_lite/lv_vg_lite_pending.c \
../Application/lvgl/src/draw/vg_lite/lv_vg_lite_stroke.c \
../Application/lvgl/src/draw/vg_lite/lv_vg_lite_utils.c 

OBJS += \
./Application/lvgl/src/draw/vg_lite/lv_draw_buf_vg_lite.o \
./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite.o \
./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_arc.o \
./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_border.o \
./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_box_shadow.o \
./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_fill.o \
./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_img.o \
./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_label.o \
./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_layer.o \
./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_line.o \
./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_mask_rect.o \
./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_triangle.o \
./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_vector.o \
./Application/lvgl/src/draw/vg_lite/lv_vg_lite_decoder.o \
./Application/lvgl/src/draw/vg_lite/lv_vg_lite_grad.o \
./Application/lvgl/src/draw/vg_lite/lv_vg_lite_math.o \
./Application/lvgl/src/draw/vg_lite/lv_vg_lite_path.o \
./Application/lvgl/src/draw/vg_lite/lv_vg_lite_pending.o \
./Application/lvgl/src/draw/vg_lite/lv_vg_lite_stroke.o \
./Application/lvgl/src/draw/vg_lite/lv_vg_lite_utils.o 

C_DEPS += \
./Application/lvgl/src/draw/vg_lite/lv_draw_buf_vg_lite.d \
./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite.d \
./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_arc.d \
./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_border.d \
./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_box_shadow.d \
./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_fill.d \
./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_img.d \
./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_label.d \
./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_layer.d \
./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_line.d \
./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_mask_rect.d \
./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_triangle.d \
./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_vector.d \
./Application/lvgl/src/draw/vg_lite/lv_vg_lite_decoder.d \
./Application/lvgl/src/draw/vg_lite/lv_vg_lite_grad.d \
./Application/lvgl/src/draw/vg_lite/lv_vg_lite_math.d \
./Application/lvgl/src/draw/vg_lite/lv_vg_lite_path.d \
./Application/lvgl/src/draw/vg_lite/lv_vg_lite_pending.d \
./Application/lvgl/src/draw/vg_lite/lv_vg_lite_stroke.d \
./Application/lvgl/src/draw/vg_lite/lv_vg_lite_utils.d 


# Each subdirectory must supply rules for building sources it contributes
Application/lvgl/src/draw/vg_lite/%.o Application/lvgl/src/draw/vg_lite/%.su Application/lvgl/src/draw/vg_lite/%.cyclo: ../Application/lvgl/src/draw/vg_lite/%.c Application/lvgl/src/draw/vg_lite/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../USB_Device/App -I../USB_Device/Target -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/System/Inc" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/lvgl" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/ui" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/Display" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-lvgl-2f-src-2f-draw-2f-vg_lite

clean-Application-2f-lvgl-2f-src-2f-draw-2f-vg_lite:
	-$(RM) ./Application/lvgl/src/draw/vg_lite/lv_draw_buf_vg_lite.cyclo ./Application/lvgl/src/draw/vg_lite/lv_draw_buf_vg_lite.d ./Application/lvgl/src/draw/vg_lite/lv_draw_buf_vg_lite.o ./Application/lvgl/src/draw/vg_lite/lv_draw_buf_vg_lite.su ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite.cyclo ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite.d ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite.o ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite.su ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_arc.cyclo ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_arc.d ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_arc.o ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_arc.su ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_border.cyclo ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_border.d ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_border.o ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_border.su ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_box_shadow.cyclo ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_box_shadow.d ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_box_shadow.o ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_box_shadow.su ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_fill.cyclo ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_fill.d ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_fill.o ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_fill.su ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_img.cyclo ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_img.d ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_img.o ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_img.su ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_label.cyclo ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_label.d ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_label.o ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_label.su ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_layer.cyclo ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_layer.d ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_layer.o ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_layer.su ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_line.cyclo ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_line.d ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_line.o ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_line.su ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_mask_rect.cyclo ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_mask_rect.d ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_mask_rect.o ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_mask_rect.su ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_triangle.cyclo ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_triangle.d ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_triangle.o ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_triangle.su ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_vector.cyclo ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_vector.d ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_vector.o ./Application/lvgl/src/draw/vg_lite/lv_draw_vg_lite_vector.su ./Application/lvgl/src/draw/vg_lite/lv_vg_lite_decoder.cyclo ./Application/lvgl/src/draw/vg_lite/lv_vg_lite_decoder.d ./Application/lvgl/src/draw/vg_lite/lv_vg_lite_decoder.o ./Application/lvgl/src/draw/vg_lite/lv_vg_lite_decoder.su ./Application/lvgl/src/draw/vg_lite/lv_vg_lite_grad.cyclo ./Application/lvgl/src/draw/vg_lite/lv_vg_lite_grad.d ./Application/lvgl/src/draw/vg_lite/lv_vg_lite_grad.o ./Application/lvgl/src/draw/vg_lite/lv_vg_lite_grad.su ./Application/lvgl/src/draw/vg_lite/lv_vg_lite_math.cyclo ./Application/lvgl/src/draw/vg_lite/lv_vg_lite_math.d ./Application/lvgl/src/draw/vg_lite/lv_vg_lite_math.o ./Application/lvgl/src/draw/vg_lite/lv_vg_lite_math.su ./Application/lvgl/src/draw/vg_lite/lv_vg_lite_path.cyclo ./Application/lvgl/src/draw/vg_lite/lv_vg_lite_path.d ./Application/lvgl/src/draw/vg_lite/lv_vg_lite_path.o ./Application/lvgl/src/draw/vg_lite/lv_vg_lite_path.su ./Application/lvgl/src/draw/vg_lite/lv_vg_lite_pending.cyclo ./Application/lvgl/src/draw/vg_lite/lv_vg_lite_pending.d ./Application/lvgl/src/draw/vg_lite/lv_vg_lite_pending.o ./Application/lvgl/src/draw/vg_lite/lv_vg_lite_pending.su ./Application/lvgl/src/draw/vg_lite/lv_vg_lite_stroke.cyclo ./Application/lvgl/src/draw/vg_lite/lv_vg_lite_stroke.d ./Application/lvgl/src/draw/vg_lite/lv_vg_lite_stroke.o ./Application/lvgl/src/draw/vg_lite/lv_vg_lite_stroke.su ./Application/lvgl/src/draw/vg_lite/lv_vg_lite_utils.cyclo ./Application/lvgl/src/draw/vg_lite/lv_vg_lite_utils.d ./Application/lvgl/src/draw/vg_lite/lv_vg_lite_utils.o ./Application/lvgl/src/draw/vg_lite/lv_vg_lite_utils.su

.PHONY: clean-Application-2f-lvgl-2f-src-2f-draw-2f-vg_lite

