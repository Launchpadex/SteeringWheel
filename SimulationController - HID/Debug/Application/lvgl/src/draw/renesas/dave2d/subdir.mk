################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d.c \
../Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_arc.c \
../Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_border.c \
../Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_fill.c \
../Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_image.c \
../Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_label.c \
../Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_line.c \
../Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_mask_rectangle.c \
../Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_triangle.c \
../Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_utils.c 

OBJS += \
./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d.o \
./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_arc.o \
./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_border.o \
./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_fill.o \
./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_image.o \
./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_label.o \
./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_line.o \
./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_mask_rectangle.o \
./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_triangle.o \
./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_utils.o 

C_DEPS += \
./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d.d \
./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_arc.d \
./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_border.d \
./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_fill.d \
./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_image.d \
./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_label.d \
./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_line.d \
./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_mask_rectangle.d \
./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_triangle.d \
./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_utils.d 


# Each subdirectory must supply rules for building sources it contributes
Application/lvgl/src/draw/renesas/dave2d/%.o Application/lvgl/src/draw/renesas/dave2d/%.su Application/lvgl/src/draw/renesas/dave2d/%.cyclo: ../Application/lvgl/src/draw/renesas/dave2d/%.c Application/lvgl/src/draw/renesas/dave2d/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../USB_Device/App -I../USB_Device/Target -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/System/Inc" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/lvgl" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/ui" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/Display" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-lvgl-2f-src-2f-draw-2f-renesas-2f-dave2d

clean-Application-2f-lvgl-2f-src-2f-draw-2f-renesas-2f-dave2d:
	-$(RM) ./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d.cyclo ./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d.d ./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d.o ./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d.su ./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_arc.cyclo ./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_arc.d ./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_arc.o ./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_arc.su ./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_border.cyclo ./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_border.d ./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_border.o ./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_border.su ./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_fill.cyclo ./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_fill.d ./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_fill.o ./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_fill.su ./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_image.cyclo ./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_image.d ./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_image.o ./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_image.su ./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_label.cyclo ./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_label.d ./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_label.o ./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_label.su ./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_line.cyclo ./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_line.d ./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_line.o ./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_line.su ./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_mask_rectangle.cyclo ./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_mask_rectangle.d ./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_mask_rectangle.o ./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_mask_rectangle.su ./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_triangle.cyclo ./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_triangle.d ./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_triangle.o ./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_triangle.su ./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_utils.cyclo ./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_utils.d ./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_utils.o ./Application/lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_utils.su

.PHONY: clean-Application-2f-lvgl-2f-src-2f-draw-2f-renesas-2f-dave2d

