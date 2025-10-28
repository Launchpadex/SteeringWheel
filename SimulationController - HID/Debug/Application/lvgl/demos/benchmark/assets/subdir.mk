################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/lvgl/demos/benchmark/assets/img_benchmark_avatar.c \
../Application/lvgl/demos/benchmark/assets/img_benchmark_lvgl_logo_argb.c \
../Application/lvgl/demos/benchmark/assets/img_benchmark_lvgl_logo_rgb.c \
../Application/lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_12_compr_az.c.c \
../Application/lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_16_compr_az.c.c \
../Application/lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_28_compr_az.c.c 

OBJS += \
./Application/lvgl/demos/benchmark/assets/img_benchmark_avatar.o \
./Application/lvgl/demos/benchmark/assets/img_benchmark_lvgl_logo_argb.o \
./Application/lvgl/demos/benchmark/assets/img_benchmark_lvgl_logo_rgb.o \
./Application/lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_12_compr_az.c.o \
./Application/lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_16_compr_az.c.o \
./Application/lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_28_compr_az.c.o 

C_DEPS += \
./Application/lvgl/demos/benchmark/assets/img_benchmark_avatar.d \
./Application/lvgl/demos/benchmark/assets/img_benchmark_lvgl_logo_argb.d \
./Application/lvgl/demos/benchmark/assets/img_benchmark_lvgl_logo_rgb.d \
./Application/lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_12_compr_az.c.d \
./Application/lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_16_compr_az.c.d \
./Application/lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_28_compr_az.c.d 


# Each subdirectory must supply rules for building sources it contributes
Application/lvgl/demos/benchmark/assets/%.o Application/lvgl/demos/benchmark/assets/%.su Application/lvgl/demos/benchmark/assets/%.cyclo: ../Application/lvgl/demos/benchmark/assets/%.c Application/lvgl/demos/benchmark/assets/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../USB_Device/App -I../USB_Device/Target -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/System/Inc" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/lvgl" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/ui" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/Display" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-lvgl-2f-demos-2f-benchmark-2f-assets

clean-Application-2f-lvgl-2f-demos-2f-benchmark-2f-assets:
	-$(RM) ./Application/lvgl/demos/benchmark/assets/img_benchmark_avatar.cyclo ./Application/lvgl/demos/benchmark/assets/img_benchmark_avatar.d ./Application/lvgl/demos/benchmark/assets/img_benchmark_avatar.o ./Application/lvgl/demos/benchmark/assets/img_benchmark_avatar.su ./Application/lvgl/demos/benchmark/assets/img_benchmark_lvgl_logo_argb.cyclo ./Application/lvgl/demos/benchmark/assets/img_benchmark_lvgl_logo_argb.d ./Application/lvgl/demos/benchmark/assets/img_benchmark_lvgl_logo_argb.o ./Application/lvgl/demos/benchmark/assets/img_benchmark_lvgl_logo_argb.su ./Application/lvgl/demos/benchmark/assets/img_benchmark_lvgl_logo_rgb.cyclo ./Application/lvgl/demos/benchmark/assets/img_benchmark_lvgl_logo_rgb.d ./Application/lvgl/demos/benchmark/assets/img_benchmark_lvgl_logo_rgb.o ./Application/lvgl/demos/benchmark/assets/img_benchmark_lvgl_logo_rgb.su ./Application/lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_12_compr_az.c.cyclo ./Application/lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_12_compr_az.c.d ./Application/lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_12_compr_az.c.o ./Application/lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_12_compr_az.c.su ./Application/lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_16_compr_az.c.cyclo ./Application/lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_16_compr_az.c.d ./Application/lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_16_compr_az.c.o ./Application/lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_16_compr_az.c.su ./Application/lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_28_compr_az.c.cyclo ./Application/lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_28_compr_az.c.d ./Application/lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_28_compr_az.c.o ./Application/lvgl/demos/benchmark/assets/lv_font_benchmark_montserrat_28_compr_az.c.su

.PHONY: clean-Application-2f-lvgl-2f-demos-2f-benchmark-2f-assets

