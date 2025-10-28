################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/lvgl/src/draw/nxp/vglite/lv_draw_buf_vglite.c \
../Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite.c \
../Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_arc.c \
../Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_border.c \
../Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_fill.c \
../Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_img.c \
../Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_label.c \
../Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_layer.c \
../Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_line.c \
../Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_triangle.c \
../Application/lvgl/src/draw/nxp/vglite/lv_vglite_buf.c \
../Application/lvgl/src/draw/nxp/vglite/lv_vglite_matrix.c \
../Application/lvgl/src/draw/nxp/vglite/lv_vglite_path.c \
../Application/lvgl/src/draw/nxp/vglite/lv_vglite_utils.c 

OBJS += \
./Application/lvgl/src/draw/nxp/vglite/lv_draw_buf_vglite.o \
./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite.o \
./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_arc.o \
./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_border.o \
./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_fill.o \
./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_img.o \
./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_label.o \
./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_layer.o \
./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_line.o \
./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_triangle.o \
./Application/lvgl/src/draw/nxp/vglite/lv_vglite_buf.o \
./Application/lvgl/src/draw/nxp/vglite/lv_vglite_matrix.o \
./Application/lvgl/src/draw/nxp/vglite/lv_vglite_path.o \
./Application/lvgl/src/draw/nxp/vglite/lv_vglite_utils.o 

C_DEPS += \
./Application/lvgl/src/draw/nxp/vglite/lv_draw_buf_vglite.d \
./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite.d \
./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_arc.d \
./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_border.d \
./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_fill.d \
./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_img.d \
./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_label.d \
./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_layer.d \
./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_line.d \
./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_triangle.d \
./Application/lvgl/src/draw/nxp/vglite/lv_vglite_buf.d \
./Application/lvgl/src/draw/nxp/vglite/lv_vglite_matrix.d \
./Application/lvgl/src/draw/nxp/vglite/lv_vglite_path.d \
./Application/lvgl/src/draw/nxp/vglite/lv_vglite_utils.d 


# Each subdirectory must supply rules for building sources it contributes
Application/lvgl/src/draw/nxp/vglite/%.o Application/lvgl/src/draw/nxp/vglite/%.su Application/lvgl/src/draw/nxp/vglite/%.cyclo: ../Application/lvgl/src/draw/nxp/vglite/%.c Application/lvgl/src/draw/nxp/vglite/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../USB_Device/App -I../USB_Device/Target -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/System/Inc" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/lvgl" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/ui" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/Display" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-lvgl-2f-src-2f-draw-2f-nxp-2f-vglite

clean-Application-2f-lvgl-2f-src-2f-draw-2f-nxp-2f-vglite:
	-$(RM) ./Application/lvgl/src/draw/nxp/vglite/lv_draw_buf_vglite.cyclo ./Application/lvgl/src/draw/nxp/vglite/lv_draw_buf_vglite.d ./Application/lvgl/src/draw/nxp/vglite/lv_draw_buf_vglite.o ./Application/lvgl/src/draw/nxp/vglite/lv_draw_buf_vglite.su ./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite.cyclo ./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite.d ./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite.o ./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite.su ./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_arc.cyclo ./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_arc.d ./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_arc.o ./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_arc.su ./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_border.cyclo ./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_border.d ./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_border.o ./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_border.su ./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_fill.cyclo ./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_fill.d ./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_fill.o ./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_fill.su ./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_img.cyclo ./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_img.d ./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_img.o ./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_img.su ./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_label.cyclo ./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_label.d ./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_label.o ./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_label.su ./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_layer.cyclo ./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_layer.d ./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_layer.o ./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_layer.su ./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_line.cyclo ./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_line.d ./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_line.o ./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_line.su ./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_triangle.cyclo ./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_triangle.d ./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_triangle.o ./Application/lvgl/src/draw/nxp/vglite/lv_draw_vglite_triangle.su ./Application/lvgl/src/draw/nxp/vglite/lv_vglite_buf.cyclo ./Application/lvgl/src/draw/nxp/vglite/lv_vglite_buf.d ./Application/lvgl/src/draw/nxp/vglite/lv_vglite_buf.o ./Application/lvgl/src/draw/nxp/vglite/lv_vglite_buf.su ./Application/lvgl/src/draw/nxp/vglite/lv_vglite_matrix.cyclo ./Application/lvgl/src/draw/nxp/vglite/lv_vglite_matrix.d ./Application/lvgl/src/draw/nxp/vglite/lv_vglite_matrix.o ./Application/lvgl/src/draw/nxp/vglite/lv_vglite_matrix.su ./Application/lvgl/src/draw/nxp/vglite/lv_vglite_path.cyclo ./Application/lvgl/src/draw/nxp/vglite/lv_vglite_path.d ./Application/lvgl/src/draw/nxp/vglite/lv_vglite_path.o ./Application/lvgl/src/draw/nxp/vglite/lv_vglite_path.su ./Application/lvgl/src/draw/nxp/vglite/lv_vglite_utils.cyclo ./Application/lvgl/src/draw/nxp/vglite/lv_vglite_utils.d ./Application/lvgl/src/draw/nxp/vglite/lv_vglite_utils.o ./Application/lvgl/src/draw/nxp/vglite/lv_vglite_utils.su

.PHONY: clean-Application-2f-lvgl-2f-src-2f-draw-2f-nxp-2f-vglite

