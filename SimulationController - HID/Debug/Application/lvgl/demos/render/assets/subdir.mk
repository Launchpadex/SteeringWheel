################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/lvgl/demos/render/assets/img_render_arc_bg.c \
../Application/lvgl/demos/render/assets/img_render_lvgl_logo_argb8888.c \
../Application/lvgl/demos/render/assets/img_render_lvgl_logo_i1.c \
../Application/lvgl/demos/render/assets/img_render_lvgl_logo_l8.c \
../Application/lvgl/demos/render/assets/img_render_lvgl_logo_rgb565.c \
../Application/lvgl/demos/render/assets/img_render_lvgl_logo_rgb565a8.c \
../Application/lvgl/demos/render/assets/img_render_lvgl_logo_rgb888.c \
../Application/lvgl/demos/render/assets/img_render_lvgl_logo_xrgb8888.c 

OBJS += \
./Application/lvgl/demos/render/assets/img_render_arc_bg.o \
./Application/lvgl/demos/render/assets/img_render_lvgl_logo_argb8888.o \
./Application/lvgl/demos/render/assets/img_render_lvgl_logo_i1.o \
./Application/lvgl/demos/render/assets/img_render_lvgl_logo_l8.o \
./Application/lvgl/demos/render/assets/img_render_lvgl_logo_rgb565.o \
./Application/lvgl/demos/render/assets/img_render_lvgl_logo_rgb565a8.o \
./Application/lvgl/demos/render/assets/img_render_lvgl_logo_rgb888.o \
./Application/lvgl/demos/render/assets/img_render_lvgl_logo_xrgb8888.o 

C_DEPS += \
./Application/lvgl/demos/render/assets/img_render_arc_bg.d \
./Application/lvgl/demos/render/assets/img_render_lvgl_logo_argb8888.d \
./Application/lvgl/demos/render/assets/img_render_lvgl_logo_i1.d \
./Application/lvgl/demos/render/assets/img_render_lvgl_logo_l8.d \
./Application/lvgl/demos/render/assets/img_render_lvgl_logo_rgb565.d \
./Application/lvgl/demos/render/assets/img_render_lvgl_logo_rgb565a8.d \
./Application/lvgl/demos/render/assets/img_render_lvgl_logo_rgb888.d \
./Application/lvgl/demos/render/assets/img_render_lvgl_logo_xrgb8888.d 


# Each subdirectory must supply rules for building sources it contributes
Application/lvgl/demos/render/assets/%.o Application/lvgl/demos/render/assets/%.su Application/lvgl/demos/render/assets/%.cyclo: ../Application/lvgl/demos/render/assets/%.c Application/lvgl/demos/render/assets/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../USB_Device/App -I../USB_Device/Target -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/System/Inc" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/lvgl" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/ui" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/Display" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-lvgl-2f-demos-2f-render-2f-assets

clean-Application-2f-lvgl-2f-demos-2f-render-2f-assets:
	-$(RM) ./Application/lvgl/demos/render/assets/img_render_arc_bg.cyclo ./Application/lvgl/demos/render/assets/img_render_arc_bg.d ./Application/lvgl/demos/render/assets/img_render_arc_bg.o ./Application/lvgl/demos/render/assets/img_render_arc_bg.su ./Application/lvgl/demos/render/assets/img_render_lvgl_logo_argb8888.cyclo ./Application/lvgl/demos/render/assets/img_render_lvgl_logo_argb8888.d ./Application/lvgl/demos/render/assets/img_render_lvgl_logo_argb8888.o ./Application/lvgl/demos/render/assets/img_render_lvgl_logo_argb8888.su ./Application/lvgl/demos/render/assets/img_render_lvgl_logo_i1.cyclo ./Application/lvgl/demos/render/assets/img_render_lvgl_logo_i1.d ./Application/lvgl/demos/render/assets/img_render_lvgl_logo_i1.o ./Application/lvgl/demos/render/assets/img_render_lvgl_logo_i1.su ./Application/lvgl/demos/render/assets/img_render_lvgl_logo_l8.cyclo ./Application/lvgl/demos/render/assets/img_render_lvgl_logo_l8.d ./Application/lvgl/demos/render/assets/img_render_lvgl_logo_l8.o ./Application/lvgl/demos/render/assets/img_render_lvgl_logo_l8.su ./Application/lvgl/demos/render/assets/img_render_lvgl_logo_rgb565.cyclo ./Application/lvgl/demos/render/assets/img_render_lvgl_logo_rgb565.d ./Application/lvgl/demos/render/assets/img_render_lvgl_logo_rgb565.o ./Application/lvgl/demos/render/assets/img_render_lvgl_logo_rgb565.su ./Application/lvgl/demos/render/assets/img_render_lvgl_logo_rgb565a8.cyclo ./Application/lvgl/demos/render/assets/img_render_lvgl_logo_rgb565a8.d ./Application/lvgl/demos/render/assets/img_render_lvgl_logo_rgb565a8.o ./Application/lvgl/demos/render/assets/img_render_lvgl_logo_rgb565a8.su ./Application/lvgl/demos/render/assets/img_render_lvgl_logo_rgb888.cyclo ./Application/lvgl/demos/render/assets/img_render_lvgl_logo_rgb888.d ./Application/lvgl/demos/render/assets/img_render_lvgl_logo_rgb888.o ./Application/lvgl/demos/render/assets/img_render_lvgl_logo_rgb888.su ./Application/lvgl/demos/render/assets/img_render_lvgl_logo_xrgb8888.cyclo ./Application/lvgl/demos/render/assets/img_render_lvgl_logo_xrgb8888.d ./Application/lvgl/demos/render/assets/img_render_lvgl_logo_xrgb8888.o ./Application/lvgl/demos/render/assets/img_render_lvgl_logo_xrgb8888.su

.PHONY: clean-Application-2f-lvgl-2f-demos-2f-render-2f-assets

