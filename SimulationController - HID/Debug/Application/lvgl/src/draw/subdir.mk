################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/lvgl/src/draw/lv_draw.c \
../Application/lvgl/src/draw/lv_draw_arc.c \
../Application/lvgl/src/draw/lv_draw_buf.c \
../Application/lvgl/src/draw/lv_draw_image.c \
../Application/lvgl/src/draw/lv_draw_label.c \
../Application/lvgl/src/draw/lv_draw_line.c \
../Application/lvgl/src/draw/lv_draw_mask.c \
../Application/lvgl/src/draw/lv_draw_rect.c \
../Application/lvgl/src/draw/lv_draw_triangle.c \
../Application/lvgl/src/draw/lv_draw_vector.c \
../Application/lvgl/src/draw/lv_image_decoder.c 

OBJS += \
./Application/lvgl/src/draw/lv_draw.o \
./Application/lvgl/src/draw/lv_draw_arc.o \
./Application/lvgl/src/draw/lv_draw_buf.o \
./Application/lvgl/src/draw/lv_draw_image.o \
./Application/lvgl/src/draw/lv_draw_label.o \
./Application/lvgl/src/draw/lv_draw_line.o \
./Application/lvgl/src/draw/lv_draw_mask.o \
./Application/lvgl/src/draw/lv_draw_rect.o \
./Application/lvgl/src/draw/lv_draw_triangle.o \
./Application/lvgl/src/draw/lv_draw_vector.o \
./Application/lvgl/src/draw/lv_image_decoder.o 

C_DEPS += \
./Application/lvgl/src/draw/lv_draw.d \
./Application/lvgl/src/draw/lv_draw_arc.d \
./Application/lvgl/src/draw/lv_draw_buf.d \
./Application/lvgl/src/draw/lv_draw_image.d \
./Application/lvgl/src/draw/lv_draw_label.d \
./Application/lvgl/src/draw/lv_draw_line.d \
./Application/lvgl/src/draw/lv_draw_mask.d \
./Application/lvgl/src/draw/lv_draw_rect.d \
./Application/lvgl/src/draw/lv_draw_triangle.d \
./Application/lvgl/src/draw/lv_draw_vector.d \
./Application/lvgl/src/draw/lv_image_decoder.d 


# Each subdirectory must supply rules for building sources it contributes
Application/lvgl/src/draw/%.o Application/lvgl/src/draw/%.su Application/lvgl/src/draw/%.cyclo: ../Application/lvgl/src/draw/%.c Application/lvgl/src/draw/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../USB_Device/App -I../USB_Device/Target -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/System/Inc" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/lvgl" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/ui" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/Display" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-lvgl-2f-src-2f-draw

clean-Application-2f-lvgl-2f-src-2f-draw:
	-$(RM) ./Application/lvgl/src/draw/lv_draw.cyclo ./Application/lvgl/src/draw/lv_draw.d ./Application/lvgl/src/draw/lv_draw.o ./Application/lvgl/src/draw/lv_draw.su ./Application/lvgl/src/draw/lv_draw_arc.cyclo ./Application/lvgl/src/draw/lv_draw_arc.d ./Application/lvgl/src/draw/lv_draw_arc.o ./Application/lvgl/src/draw/lv_draw_arc.su ./Application/lvgl/src/draw/lv_draw_buf.cyclo ./Application/lvgl/src/draw/lv_draw_buf.d ./Application/lvgl/src/draw/lv_draw_buf.o ./Application/lvgl/src/draw/lv_draw_buf.su ./Application/lvgl/src/draw/lv_draw_image.cyclo ./Application/lvgl/src/draw/lv_draw_image.d ./Application/lvgl/src/draw/lv_draw_image.o ./Application/lvgl/src/draw/lv_draw_image.su ./Application/lvgl/src/draw/lv_draw_label.cyclo ./Application/lvgl/src/draw/lv_draw_label.d ./Application/lvgl/src/draw/lv_draw_label.o ./Application/lvgl/src/draw/lv_draw_label.su ./Application/lvgl/src/draw/lv_draw_line.cyclo ./Application/lvgl/src/draw/lv_draw_line.d ./Application/lvgl/src/draw/lv_draw_line.o ./Application/lvgl/src/draw/lv_draw_line.su ./Application/lvgl/src/draw/lv_draw_mask.cyclo ./Application/lvgl/src/draw/lv_draw_mask.d ./Application/lvgl/src/draw/lv_draw_mask.o ./Application/lvgl/src/draw/lv_draw_mask.su ./Application/lvgl/src/draw/lv_draw_rect.cyclo ./Application/lvgl/src/draw/lv_draw_rect.d ./Application/lvgl/src/draw/lv_draw_rect.o ./Application/lvgl/src/draw/lv_draw_rect.su ./Application/lvgl/src/draw/lv_draw_triangle.cyclo ./Application/lvgl/src/draw/lv_draw_triangle.d ./Application/lvgl/src/draw/lv_draw_triangle.o ./Application/lvgl/src/draw/lv_draw_triangle.su ./Application/lvgl/src/draw/lv_draw_vector.cyclo ./Application/lvgl/src/draw/lv_draw_vector.d ./Application/lvgl/src/draw/lv_draw_vector.o ./Application/lvgl/src/draw/lv_draw_vector.su ./Application/lvgl/src/draw/lv_image_decoder.cyclo ./Application/lvgl/src/draw/lv_image_decoder.d ./Application/lvgl/src/draw/lv_image_decoder.o ./Application/lvgl/src/draw/lv_image_decoder.su

.PHONY: clean-Application-2f-lvgl-2f-src-2f-draw

