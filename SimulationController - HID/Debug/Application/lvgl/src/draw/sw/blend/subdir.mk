################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend.c \
../Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_al88.c \
../Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_argb8888.c \
../Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_i1.c \
../Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_l8.c \
../Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_rgb565.c \
../Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_rgb888.c 

OBJS += \
./Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend.o \
./Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_al88.o \
./Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_argb8888.o \
./Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_i1.o \
./Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_l8.o \
./Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_rgb565.o \
./Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_rgb888.o 

C_DEPS += \
./Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend.d \
./Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_al88.d \
./Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_argb8888.d \
./Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_i1.d \
./Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_l8.d \
./Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_rgb565.d \
./Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_rgb888.d 


# Each subdirectory must supply rules for building sources it contributes
Application/lvgl/src/draw/sw/blend/%.o Application/lvgl/src/draw/sw/blend/%.su Application/lvgl/src/draw/sw/blend/%.cyclo: ../Application/lvgl/src/draw/sw/blend/%.c Application/lvgl/src/draw/sw/blend/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../USB_Device/App -I../USB_Device/Target -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/System/Inc" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/lvgl" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/ui" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/Display" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-lvgl-2f-src-2f-draw-2f-sw-2f-blend

clean-Application-2f-lvgl-2f-src-2f-draw-2f-sw-2f-blend:
	-$(RM) ./Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend.cyclo ./Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend.d ./Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend.o ./Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend.su ./Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_al88.cyclo ./Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_al88.d ./Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_al88.o ./Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_al88.su ./Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_argb8888.cyclo ./Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_argb8888.d ./Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_argb8888.o ./Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_argb8888.su ./Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_i1.cyclo ./Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_i1.d ./Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_i1.o ./Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_i1.su ./Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_l8.cyclo ./Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_l8.d ./Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_l8.o ./Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_l8.su ./Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_rgb565.cyclo ./Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_rgb565.d ./Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_rgb565.o ./Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_rgb565.su ./Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_rgb888.cyclo ./Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_rgb888.d ./Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_rgb888.o ./Application/lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_rgb888.su

.PHONY: clean-Application-2f-lvgl-2f-src-2f-draw-2f-sw-2f-blend

