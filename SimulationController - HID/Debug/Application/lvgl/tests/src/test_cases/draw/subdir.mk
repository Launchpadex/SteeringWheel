################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/lvgl/tests/src/test_cases/draw/test_bg_image.c \
../Application/lvgl/tests/src/test_cases/draw/test_clip_corner.c \
../Application/lvgl/tests/src/test_cases/draw/test_draw_blend.c \
../Application/lvgl/tests/src/test_cases/draw/test_draw_label.c \
../Application/lvgl/tests/src/test_cases/draw/test_draw_layer.c \
../Application/lvgl/tests/src/test_cases/draw/test_draw_svg.c \
../Application/lvgl/tests/src/test_cases/draw/test_draw_sw_post_process.c \
../Application/lvgl/tests/src/test_cases/draw/test_draw_vector.c \
../Application/lvgl/tests/src/test_cases/draw/test_image_formats.c \
../Application/lvgl/tests/src/test_cases/draw/test_layer_transform.c \
../Application/lvgl/tests/src/test_cases/draw/test_render_to_al88.c \
../Application/lvgl/tests/src/test_cases/draw/test_render_to_argb1555.c \
../Application/lvgl/tests/src/test_cases/draw/test_render_to_argb2222.c \
../Application/lvgl/tests/src/test_cases/draw/test_render_to_argb4444.c \
../Application/lvgl/tests/src/test_cases/draw/test_render_to_argb8888.c \
../Application/lvgl/tests/src/test_cases/draw/test_render_to_i1.c \
../Application/lvgl/tests/src/test_cases/draw/test_render_to_l8.c \
../Application/lvgl/tests/src/test_cases/draw/test_render_to_rgb565.c \
../Application/lvgl/tests/src/test_cases/draw/test_render_to_rgb888.c \
../Application/lvgl/tests/src/test_cases/draw/test_render_to_xrgb8888.c 

OBJS += \
./Application/lvgl/tests/src/test_cases/draw/test_bg_image.o \
./Application/lvgl/tests/src/test_cases/draw/test_clip_corner.o \
./Application/lvgl/tests/src/test_cases/draw/test_draw_blend.o \
./Application/lvgl/tests/src/test_cases/draw/test_draw_label.o \
./Application/lvgl/tests/src/test_cases/draw/test_draw_layer.o \
./Application/lvgl/tests/src/test_cases/draw/test_draw_svg.o \
./Application/lvgl/tests/src/test_cases/draw/test_draw_sw_post_process.o \
./Application/lvgl/tests/src/test_cases/draw/test_draw_vector.o \
./Application/lvgl/tests/src/test_cases/draw/test_image_formats.o \
./Application/lvgl/tests/src/test_cases/draw/test_layer_transform.o \
./Application/lvgl/tests/src/test_cases/draw/test_render_to_al88.o \
./Application/lvgl/tests/src/test_cases/draw/test_render_to_argb1555.o \
./Application/lvgl/tests/src/test_cases/draw/test_render_to_argb2222.o \
./Application/lvgl/tests/src/test_cases/draw/test_render_to_argb4444.o \
./Application/lvgl/tests/src/test_cases/draw/test_render_to_argb8888.o \
./Application/lvgl/tests/src/test_cases/draw/test_render_to_i1.o \
./Application/lvgl/tests/src/test_cases/draw/test_render_to_l8.o \
./Application/lvgl/tests/src/test_cases/draw/test_render_to_rgb565.o \
./Application/lvgl/tests/src/test_cases/draw/test_render_to_rgb888.o \
./Application/lvgl/tests/src/test_cases/draw/test_render_to_xrgb8888.o 

C_DEPS += \
./Application/lvgl/tests/src/test_cases/draw/test_bg_image.d \
./Application/lvgl/tests/src/test_cases/draw/test_clip_corner.d \
./Application/lvgl/tests/src/test_cases/draw/test_draw_blend.d \
./Application/lvgl/tests/src/test_cases/draw/test_draw_label.d \
./Application/lvgl/tests/src/test_cases/draw/test_draw_layer.d \
./Application/lvgl/tests/src/test_cases/draw/test_draw_svg.d \
./Application/lvgl/tests/src/test_cases/draw/test_draw_sw_post_process.d \
./Application/lvgl/tests/src/test_cases/draw/test_draw_vector.d \
./Application/lvgl/tests/src/test_cases/draw/test_image_formats.d \
./Application/lvgl/tests/src/test_cases/draw/test_layer_transform.d \
./Application/lvgl/tests/src/test_cases/draw/test_render_to_al88.d \
./Application/lvgl/tests/src/test_cases/draw/test_render_to_argb1555.d \
./Application/lvgl/tests/src/test_cases/draw/test_render_to_argb2222.d \
./Application/lvgl/tests/src/test_cases/draw/test_render_to_argb4444.d \
./Application/lvgl/tests/src/test_cases/draw/test_render_to_argb8888.d \
./Application/lvgl/tests/src/test_cases/draw/test_render_to_i1.d \
./Application/lvgl/tests/src/test_cases/draw/test_render_to_l8.d \
./Application/lvgl/tests/src/test_cases/draw/test_render_to_rgb565.d \
./Application/lvgl/tests/src/test_cases/draw/test_render_to_rgb888.d \
./Application/lvgl/tests/src/test_cases/draw/test_render_to_xrgb8888.d 


# Each subdirectory must supply rules for building sources it contributes
Application/lvgl/tests/src/test_cases/draw/%.o Application/lvgl/tests/src/test_cases/draw/%.su Application/lvgl/tests/src/test_cases/draw/%.cyclo: ../Application/lvgl/tests/src/test_cases/draw/%.c Application/lvgl/tests/src/test_cases/draw/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../USB_Device/App -I../USB_Device/Target -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/System/Inc" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/lvgl" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/ui" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/Display" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-lvgl-2f-tests-2f-src-2f-test_cases-2f-draw

clean-Application-2f-lvgl-2f-tests-2f-src-2f-test_cases-2f-draw:
	-$(RM) ./Application/lvgl/tests/src/test_cases/draw/test_bg_image.cyclo ./Application/lvgl/tests/src/test_cases/draw/test_bg_image.d ./Application/lvgl/tests/src/test_cases/draw/test_bg_image.o ./Application/lvgl/tests/src/test_cases/draw/test_bg_image.su ./Application/lvgl/tests/src/test_cases/draw/test_clip_corner.cyclo ./Application/lvgl/tests/src/test_cases/draw/test_clip_corner.d ./Application/lvgl/tests/src/test_cases/draw/test_clip_corner.o ./Application/lvgl/tests/src/test_cases/draw/test_clip_corner.su ./Application/lvgl/tests/src/test_cases/draw/test_draw_blend.cyclo ./Application/lvgl/tests/src/test_cases/draw/test_draw_blend.d ./Application/lvgl/tests/src/test_cases/draw/test_draw_blend.o ./Application/lvgl/tests/src/test_cases/draw/test_draw_blend.su ./Application/lvgl/tests/src/test_cases/draw/test_draw_label.cyclo ./Application/lvgl/tests/src/test_cases/draw/test_draw_label.d ./Application/lvgl/tests/src/test_cases/draw/test_draw_label.o ./Application/lvgl/tests/src/test_cases/draw/test_draw_label.su ./Application/lvgl/tests/src/test_cases/draw/test_draw_layer.cyclo ./Application/lvgl/tests/src/test_cases/draw/test_draw_layer.d ./Application/lvgl/tests/src/test_cases/draw/test_draw_layer.o ./Application/lvgl/tests/src/test_cases/draw/test_draw_layer.su ./Application/lvgl/tests/src/test_cases/draw/test_draw_svg.cyclo ./Application/lvgl/tests/src/test_cases/draw/test_draw_svg.d ./Application/lvgl/tests/src/test_cases/draw/test_draw_svg.o ./Application/lvgl/tests/src/test_cases/draw/test_draw_svg.su ./Application/lvgl/tests/src/test_cases/draw/test_draw_sw_post_process.cyclo ./Application/lvgl/tests/src/test_cases/draw/test_draw_sw_post_process.d ./Application/lvgl/tests/src/test_cases/draw/test_draw_sw_post_process.o ./Application/lvgl/tests/src/test_cases/draw/test_draw_sw_post_process.su ./Application/lvgl/tests/src/test_cases/draw/test_draw_vector.cyclo ./Application/lvgl/tests/src/test_cases/draw/test_draw_vector.d ./Application/lvgl/tests/src/test_cases/draw/test_draw_vector.o ./Application/lvgl/tests/src/test_cases/draw/test_draw_vector.su ./Application/lvgl/tests/src/test_cases/draw/test_image_formats.cyclo ./Application/lvgl/tests/src/test_cases/draw/test_image_formats.d ./Application/lvgl/tests/src/test_cases/draw/test_image_formats.o ./Application/lvgl/tests/src/test_cases/draw/test_image_formats.su ./Application/lvgl/tests/src/test_cases/draw/test_layer_transform.cyclo ./Application/lvgl/tests/src/test_cases/draw/test_layer_transform.d ./Application/lvgl/tests/src/test_cases/draw/test_layer_transform.o ./Application/lvgl/tests/src/test_cases/draw/test_layer_transform.su ./Application/lvgl/tests/src/test_cases/draw/test_render_to_al88.cyclo ./Application/lvgl/tests/src/test_cases/draw/test_render_to_al88.d ./Application/lvgl/tests/src/test_cases/draw/test_render_to_al88.o ./Application/lvgl/tests/src/test_cases/draw/test_render_to_al88.su ./Application/lvgl/tests/src/test_cases/draw/test_render_to_argb1555.cyclo ./Application/lvgl/tests/src/test_cases/draw/test_render_to_argb1555.d ./Application/lvgl/tests/src/test_cases/draw/test_render_to_argb1555.o ./Application/lvgl/tests/src/test_cases/draw/test_render_to_argb1555.su ./Application/lvgl/tests/src/test_cases/draw/test_render_to_argb2222.cyclo ./Application/lvgl/tests/src/test_cases/draw/test_render_to_argb2222.d ./Application/lvgl/tests/src/test_cases/draw/test_render_to_argb2222.o ./Application/lvgl/tests/src/test_cases/draw/test_render_to_argb2222.su ./Application/lvgl/tests/src/test_cases/draw/test_render_to_argb4444.cyclo ./Application/lvgl/tests/src/test_cases/draw/test_render_to_argb4444.d ./Application/lvgl/tests/src/test_cases/draw/test_render_to_argb4444.o ./Application/lvgl/tests/src/test_cases/draw/test_render_to_argb4444.su ./Application/lvgl/tests/src/test_cases/draw/test_render_to_argb8888.cyclo ./Application/lvgl/tests/src/test_cases/draw/test_render_to_argb8888.d ./Application/lvgl/tests/src/test_cases/draw/test_render_to_argb8888.o ./Application/lvgl/tests/src/test_cases/draw/test_render_to_argb8888.su ./Application/lvgl/tests/src/test_cases/draw/test_render_to_i1.cyclo ./Application/lvgl/tests/src/test_cases/draw/test_render_to_i1.d ./Application/lvgl/tests/src/test_cases/draw/test_render_to_i1.o ./Application/lvgl/tests/src/test_cases/draw/test_render_to_i1.su ./Application/lvgl/tests/src/test_cases/draw/test_render_to_l8.cyclo ./Application/lvgl/tests/src/test_cases/draw/test_render_to_l8.d ./Application/lvgl/tests/src/test_cases/draw/test_render_to_l8.o ./Application/lvgl/tests/src/test_cases/draw/test_render_to_l8.su ./Application/lvgl/tests/src/test_cases/draw/test_render_to_rgb565.cyclo ./Application/lvgl/tests/src/test_cases/draw/test_render_to_rgb565.d ./Application/lvgl/tests/src/test_cases/draw/test_render_to_rgb565.o ./Application/lvgl/tests/src/test_cases/draw/test_render_to_rgb565.su ./Application/lvgl/tests/src/test_cases/draw/test_render_to_rgb888.cyclo ./Application/lvgl/tests/src/test_cases/draw/test_render_to_rgb888.d ./Application/lvgl/tests/src/test_cases/draw/test_render_to_rgb888.o ./Application/lvgl/tests/src/test_cases/draw/test_render_to_rgb888.su ./Application/lvgl/tests/src/test_cases/draw/test_render_to_xrgb8888.cyclo ./Application/lvgl/tests/src/test_cases/draw/test_render_to_xrgb8888.d ./Application/lvgl/tests/src/test_cases/draw/test_render_to_xrgb8888.o ./Application/lvgl/tests/src/test_cases/draw/test_render_to_xrgb8888.su

.PHONY: clean-Application-2f-lvgl-2f-tests-2f-src-2f-test_cases-2f-draw

