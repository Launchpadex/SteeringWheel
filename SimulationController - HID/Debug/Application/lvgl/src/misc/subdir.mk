################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/lvgl/src/misc/lv_anim.c \
../Application/lvgl/src/misc/lv_anim_timeline.c \
../Application/lvgl/src/misc/lv_area.c \
../Application/lvgl/src/misc/lv_array.c \
../Application/lvgl/src/misc/lv_async.c \
../Application/lvgl/src/misc/lv_bidi.c \
../Application/lvgl/src/misc/lv_circle_buf.c \
../Application/lvgl/src/misc/lv_color.c \
../Application/lvgl/src/misc/lv_color_op.c \
../Application/lvgl/src/misc/lv_event.c \
../Application/lvgl/src/misc/lv_fs.c \
../Application/lvgl/src/misc/lv_iter.c \
../Application/lvgl/src/misc/lv_ll.c \
../Application/lvgl/src/misc/lv_log.c \
../Application/lvgl/src/misc/lv_lru.c \
../Application/lvgl/src/misc/lv_math.c \
../Application/lvgl/src/misc/lv_matrix.c \
../Application/lvgl/src/misc/lv_palette.c \
../Application/lvgl/src/misc/lv_profiler_builtin.c \
../Application/lvgl/src/misc/lv_rb.c \
../Application/lvgl/src/misc/lv_style.c \
../Application/lvgl/src/misc/lv_style_gen.c \
../Application/lvgl/src/misc/lv_templ.c \
../Application/lvgl/src/misc/lv_text.c \
../Application/lvgl/src/misc/lv_text_ap.c \
../Application/lvgl/src/misc/lv_timer.c \
../Application/lvgl/src/misc/lv_tree.c \
../Application/lvgl/src/misc/lv_utils.c 

OBJS += \
./Application/lvgl/src/misc/lv_anim.o \
./Application/lvgl/src/misc/lv_anim_timeline.o \
./Application/lvgl/src/misc/lv_area.o \
./Application/lvgl/src/misc/lv_array.o \
./Application/lvgl/src/misc/lv_async.o \
./Application/lvgl/src/misc/lv_bidi.o \
./Application/lvgl/src/misc/lv_circle_buf.o \
./Application/lvgl/src/misc/lv_color.o \
./Application/lvgl/src/misc/lv_color_op.o \
./Application/lvgl/src/misc/lv_event.o \
./Application/lvgl/src/misc/lv_fs.o \
./Application/lvgl/src/misc/lv_iter.o \
./Application/lvgl/src/misc/lv_ll.o \
./Application/lvgl/src/misc/lv_log.o \
./Application/lvgl/src/misc/lv_lru.o \
./Application/lvgl/src/misc/lv_math.o \
./Application/lvgl/src/misc/lv_matrix.o \
./Application/lvgl/src/misc/lv_palette.o \
./Application/lvgl/src/misc/lv_profiler_builtin.o \
./Application/lvgl/src/misc/lv_rb.o \
./Application/lvgl/src/misc/lv_style.o \
./Application/lvgl/src/misc/lv_style_gen.o \
./Application/lvgl/src/misc/lv_templ.o \
./Application/lvgl/src/misc/lv_text.o \
./Application/lvgl/src/misc/lv_text_ap.o \
./Application/lvgl/src/misc/lv_timer.o \
./Application/lvgl/src/misc/lv_tree.o \
./Application/lvgl/src/misc/lv_utils.o 

C_DEPS += \
./Application/lvgl/src/misc/lv_anim.d \
./Application/lvgl/src/misc/lv_anim_timeline.d \
./Application/lvgl/src/misc/lv_area.d \
./Application/lvgl/src/misc/lv_array.d \
./Application/lvgl/src/misc/lv_async.d \
./Application/lvgl/src/misc/lv_bidi.d \
./Application/lvgl/src/misc/lv_circle_buf.d \
./Application/lvgl/src/misc/lv_color.d \
./Application/lvgl/src/misc/lv_color_op.d \
./Application/lvgl/src/misc/lv_event.d \
./Application/lvgl/src/misc/lv_fs.d \
./Application/lvgl/src/misc/lv_iter.d \
./Application/lvgl/src/misc/lv_ll.d \
./Application/lvgl/src/misc/lv_log.d \
./Application/lvgl/src/misc/lv_lru.d \
./Application/lvgl/src/misc/lv_math.d \
./Application/lvgl/src/misc/lv_matrix.d \
./Application/lvgl/src/misc/lv_palette.d \
./Application/lvgl/src/misc/lv_profiler_builtin.d \
./Application/lvgl/src/misc/lv_rb.d \
./Application/lvgl/src/misc/lv_style.d \
./Application/lvgl/src/misc/lv_style_gen.d \
./Application/lvgl/src/misc/lv_templ.d \
./Application/lvgl/src/misc/lv_text.d \
./Application/lvgl/src/misc/lv_text_ap.d \
./Application/lvgl/src/misc/lv_timer.d \
./Application/lvgl/src/misc/lv_tree.d \
./Application/lvgl/src/misc/lv_utils.d 


# Each subdirectory must supply rules for building sources it contributes
Application/lvgl/src/misc/%.o Application/lvgl/src/misc/%.su Application/lvgl/src/misc/%.cyclo: ../Application/lvgl/src/misc/%.c Application/lvgl/src/misc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../USB_Device/App -I../USB_Device/Target -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/System/Inc" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/lvgl" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/ui" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/Display" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-lvgl-2f-src-2f-misc

clean-Application-2f-lvgl-2f-src-2f-misc:
	-$(RM) ./Application/lvgl/src/misc/lv_anim.cyclo ./Application/lvgl/src/misc/lv_anim.d ./Application/lvgl/src/misc/lv_anim.o ./Application/lvgl/src/misc/lv_anim.su ./Application/lvgl/src/misc/lv_anim_timeline.cyclo ./Application/lvgl/src/misc/lv_anim_timeline.d ./Application/lvgl/src/misc/lv_anim_timeline.o ./Application/lvgl/src/misc/lv_anim_timeline.su ./Application/lvgl/src/misc/lv_area.cyclo ./Application/lvgl/src/misc/lv_area.d ./Application/lvgl/src/misc/lv_area.o ./Application/lvgl/src/misc/lv_area.su ./Application/lvgl/src/misc/lv_array.cyclo ./Application/lvgl/src/misc/lv_array.d ./Application/lvgl/src/misc/lv_array.o ./Application/lvgl/src/misc/lv_array.su ./Application/lvgl/src/misc/lv_async.cyclo ./Application/lvgl/src/misc/lv_async.d ./Application/lvgl/src/misc/lv_async.o ./Application/lvgl/src/misc/lv_async.su ./Application/lvgl/src/misc/lv_bidi.cyclo ./Application/lvgl/src/misc/lv_bidi.d ./Application/lvgl/src/misc/lv_bidi.o ./Application/lvgl/src/misc/lv_bidi.su ./Application/lvgl/src/misc/lv_circle_buf.cyclo ./Application/lvgl/src/misc/lv_circle_buf.d ./Application/lvgl/src/misc/lv_circle_buf.o ./Application/lvgl/src/misc/lv_circle_buf.su ./Application/lvgl/src/misc/lv_color.cyclo ./Application/lvgl/src/misc/lv_color.d ./Application/lvgl/src/misc/lv_color.o ./Application/lvgl/src/misc/lv_color.su ./Application/lvgl/src/misc/lv_color_op.cyclo ./Application/lvgl/src/misc/lv_color_op.d ./Application/lvgl/src/misc/lv_color_op.o ./Application/lvgl/src/misc/lv_color_op.su ./Application/lvgl/src/misc/lv_event.cyclo ./Application/lvgl/src/misc/lv_event.d ./Application/lvgl/src/misc/lv_event.o ./Application/lvgl/src/misc/lv_event.su ./Application/lvgl/src/misc/lv_fs.cyclo ./Application/lvgl/src/misc/lv_fs.d ./Application/lvgl/src/misc/lv_fs.o ./Application/lvgl/src/misc/lv_fs.su ./Application/lvgl/src/misc/lv_iter.cyclo ./Application/lvgl/src/misc/lv_iter.d ./Application/lvgl/src/misc/lv_iter.o ./Application/lvgl/src/misc/lv_iter.su ./Application/lvgl/src/misc/lv_ll.cyclo ./Application/lvgl/src/misc/lv_ll.d ./Application/lvgl/src/misc/lv_ll.o ./Application/lvgl/src/misc/lv_ll.su ./Application/lvgl/src/misc/lv_log.cyclo ./Application/lvgl/src/misc/lv_log.d ./Application/lvgl/src/misc/lv_log.o ./Application/lvgl/src/misc/lv_log.su ./Application/lvgl/src/misc/lv_lru.cyclo ./Application/lvgl/src/misc/lv_lru.d ./Application/lvgl/src/misc/lv_lru.o ./Application/lvgl/src/misc/lv_lru.su ./Application/lvgl/src/misc/lv_math.cyclo ./Application/lvgl/src/misc/lv_math.d ./Application/lvgl/src/misc/lv_math.o ./Application/lvgl/src/misc/lv_math.su ./Application/lvgl/src/misc/lv_matrix.cyclo ./Application/lvgl/src/misc/lv_matrix.d ./Application/lvgl/src/misc/lv_matrix.o ./Application/lvgl/src/misc/lv_matrix.su ./Application/lvgl/src/misc/lv_palette.cyclo ./Application/lvgl/src/misc/lv_palette.d ./Application/lvgl/src/misc/lv_palette.o ./Application/lvgl/src/misc/lv_palette.su ./Application/lvgl/src/misc/lv_profiler_builtin.cyclo ./Application/lvgl/src/misc/lv_profiler_builtin.d ./Application/lvgl/src/misc/lv_profiler_builtin.o ./Application/lvgl/src/misc/lv_profiler_builtin.su ./Application/lvgl/src/misc/lv_rb.cyclo ./Application/lvgl/src/misc/lv_rb.d ./Application/lvgl/src/misc/lv_rb.o ./Application/lvgl/src/misc/lv_rb.su ./Application/lvgl/src/misc/lv_style.cyclo ./Application/lvgl/src/misc/lv_style.d ./Application/lvgl/src/misc/lv_style.o ./Application/lvgl/src/misc/lv_style.su ./Application/lvgl/src/misc/lv_style_gen.cyclo ./Application/lvgl/src/misc/lv_style_gen.d ./Application/lvgl/src/misc/lv_style_gen.o ./Application/lvgl/src/misc/lv_style_gen.su ./Application/lvgl/src/misc/lv_templ.cyclo ./Application/lvgl/src/misc/lv_templ.d ./Application/lvgl/src/misc/lv_templ.o ./Application/lvgl/src/misc/lv_templ.su ./Application/lvgl/src/misc/lv_text.cyclo ./Application/lvgl/src/misc/lv_text.d ./Application/lvgl/src/misc/lv_text.o ./Application/lvgl/src/misc/lv_text.su ./Application/lvgl/src/misc/lv_text_ap.cyclo ./Application/lvgl/src/misc/lv_text_ap.d ./Application/lvgl/src/misc/lv_text_ap.o ./Application/lvgl/src/misc/lv_text_ap.su ./Application/lvgl/src/misc/lv_timer.cyclo ./Application/lvgl/src/misc/lv_timer.d ./Application/lvgl/src/misc/lv_timer.o ./Application/lvgl/src/misc/lv_timer.su ./Application/lvgl/src/misc/lv_tree.cyclo ./Application/lvgl/src/misc/lv_tree.d ./Application/lvgl/src/misc/lv_tree.o ./Application/lvgl/src/misc/lv_tree.su ./Application/lvgl/src/misc/lv_utils.cyclo ./Application/lvgl/src/misc/lv_utils.d ./Application/lvgl/src/misc/lv_utils.o ./Application/lvgl/src/misc/lv_utils.su

.PHONY: clean-Application-2f-lvgl-2f-src-2f-misc

