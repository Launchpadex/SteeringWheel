################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx.c \
../Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_arc.c \
../Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_border.c \
../Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_fill.c \
../Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_img.c \
../Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_label.c \
../Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_layer.c \
../Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_line.c \
../Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_stm32_hal.c \
../Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_triangle.c \
../Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_utils.c \
../Application/lvgl/src/draw/nema_gfx/lv_nema_gfx_path.c 

OBJS += \
./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx.o \
./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_arc.o \
./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_border.o \
./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_fill.o \
./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_img.o \
./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_label.o \
./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_layer.o \
./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_line.o \
./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_stm32_hal.o \
./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_triangle.o \
./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_utils.o \
./Application/lvgl/src/draw/nema_gfx/lv_nema_gfx_path.o 

C_DEPS += \
./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx.d \
./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_arc.d \
./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_border.d \
./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_fill.d \
./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_img.d \
./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_label.d \
./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_layer.d \
./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_line.d \
./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_stm32_hal.d \
./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_triangle.d \
./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_utils.d \
./Application/lvgl/src/draw/nema_gfx/lv_nema_gfx_path.d 


# Each subdirectory must supply rules for building sources it contributes
Application/lvgl/src/draw/nema_gfx/%.o Application/lvgl/src/draw/nema_gfx/%.su Application/lvgl/src/draw/nema_gfx/%.cyclo: ../Application/lvgl/src/draw/nema_gfx/%.c Application/lvgl/src/draw/nema_gfx/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../USB_Device/App -I../USB_Device/Target -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/System/Inc" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/lvgl" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/ui" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/Display" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-lvgl-2f-src-2f-draw-2f-nema_gfx

clean-Application-2f-lvgl-2f-src-2f-draw-2f-nema_gfx:
	-$(RM) ./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx.cyclo ./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx.d ./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx.o ./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx.su ./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_arc.cyclo ./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_arc.d ./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_arc.o ./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_arc.su ./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_border.cyclo ./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_border.d ./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_border.o ./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_border.su ./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_fill.cyclo ./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_fill.d ./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_fill.o ./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_fill.su ./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_img.cyclo ./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_img.d ./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_img.o ./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_img.su ./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_label.cyclo ./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_label.d ./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_label.o ./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_label.su ./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_layer.cyclo ./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_layer.d ./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_layer.o ./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_layer.su ./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_line.cyclo ./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_line.d ./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_line.o ./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_line.su ./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_stm32_hal.cyclo ./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_stm32_hal.d ./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_stm32_hal.o ./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_stm32_hal.su ./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_triangle.cyclo ./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_triangle.d ./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_triangle.o ./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_triangle.su ./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_utils.cyclo ./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_utils.d ./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_utils.o ./Application/lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_utils.su ./Application/lvgl/src/draw/nema_gfx/lv_nema_gfx_path.cyclo ./Application/lvgl/src/draw/nema_gfx/lv_nema_gfx_path.d ./Application/lvgl/src/draw/nema_gfx/lv_nema_gfx_path.o ./Application/lvgl/src/draw/nema_gfx/lv_nema_gfx_path.su

.PHONY: clean-Application-2f-lvgl-2f-src-2f-draw-2f-nema_gfx

