################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/lvgl/src/drivers/nuttx/lv_nuttx_cache.c \
../Application/lvgl/src/drivers/nuttx/lv_nuttx_entry.c \
../Application/lvgl/src/drivers/nuttx/lv_nuttx_fbdev.c \
../Application/lvgl/src/drivers/nuttx/lv_nuttx_image_cache.c \
../Application/lvgl/src/drivers/nuttx/lv_nuttx_lcd.c \
../Application/lvgl/src/drivers/nuttx/lv_nuttx_libuv.c \
../Application/lvgl/src/drivers/nuttx/lv_nuttx_profiler.c \
../Application/lvgl/src/drivers/nuttx/lv_nuttx_touchscreen.c 

OBJS += \
./Application/lvgl/src/drivers/nuttx/lv_nuttx_cache.o \
./Application/lvgl/src/drivers/nuttx/lv_nuttx_entry.o \
./Application/lvgl/src/drivers/nuttx/lv_nuttx_fbdev.o \
./Application/lvgl/src/drivers/nuttx/lv_nuttx_image_cache.o \
./Application/lvgl/src/drivers/nuttx/lv_nuttx_lcd.o \
./Application/lvgl/src/drivers/nuttx/lv_nuttx_libuv.o \
./Application/lvgl/src/drivers/nuttx/lv_nuttx_profiler.o \
./Application/lvgl/src/drivers/nuttx/lv_nuttx_touchscreen.o 

C_DEPS += \
./Application/lvgl/src/drivers/nuttx/lv_nuttx_cache.d \
./Application/lvgl/src/drivers/nuttx/lv_nuttx_entry.d \
./Application/lvgl/src/drivers/nuttx/lv_nuttx_fbdev.d \
./Application/lvgl/src/drivers/nuttx/lv_nuttx_image_cache.d \
./Application/lvgl/src/drivers/nuttx/lv_nuttx_lcd.d \
./Application/lvgl/src/drivers/nuttx/lv_nuttx_libuv.d \
./Application/lvgl/src/drivers/nuttx/lv_nuttx_profiler.d \
./Application/lvgl/src/drivers/nuttx/lv_nuttx_touchscreen.d 


# Each subdirectory must supply rules for building sources it contributes
Application/lvgl/src/drivers/nuttx/%.o Application/lvgl/src/drivers/nuttx/%.su Application/lvgl/src/drivers/nuttx/%.cyclo: ../Application/lvgl/src/drivers/nuttx/%.c Application/lvgl/src/drivers/nuttx/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../USB_Device/App -I../USB_Device/Target -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/System/Inc" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/lvgl" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/ui" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/Display" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-lvgl-2f-src-2f-drivers-2f-nuttx

clean-Application-2f-lvgl-2f-src-2f-drivers-2f-nuttx:
	-$(RM) ./Application/lvgl/src/drivers/nuttx/lv_nuttx_cache.cyclo ./Application/lvgl/src/drivers/nuttx/lv_nuttx_cache.d ./Application/lvgl/src/drivers/nuttx/lv_nuttx_cache.o ./Application/lvgl/src/drivers/nuttx/lv_nuttx_cache.su ./Application/lvgl/src/drivers/nuttx/lv_nuttx_entry.cyclo ./Application/lvgl/src/drivers/nuttx/lv_nuttx_entry.d ./Application/lvgl/src/drivers/nuttx/lv_nuttx_entry.o ./Application/lvgl/src/drivers/nuttx/lv_nuttx_entry.su ./Application/lvgl/src/drivers/nuttx/lv_nuttx_fbdev.cyclo ./Application/lvgl/src/drivers/nuttx/lv_nuttx_fbdev.d ./Application/lvgl/src/drivers/nuttx/lv_nuttx_fbdev.o ./Application/lvgl/src/drivers/nuttx/lv_nuttx_fbdev.su ./Application/lvgl/src/drivers/nuttx/lv_nuttx_image_cache.cyclo ./Application/lvgl/src/drivers/nuttx/lv_nuttx_image_cache.d ./Application/lvgl/src/drivers/nuttx/lv_nuttx_image_cache.o ./Application/lvgl/src/drivers/nuttx/lv_nuttx_image_cache.su ./Application/lvgl/src/drivers/nuttx/lv_nuttx_lcd.cyclo ./Application/lvgl/src/drivers/nuttx/lv_nuttx_lcd.d ./Application/lvgl/src/drivers/nuttx/lv_nuttx_lcd.o ./Application/lvgl/src/drivers/nuttx/lv_nuttx_lcd.su ./Application/lvgl/src/drivers/nuttx/lv_nuttx_libuv.cyclo ./Application/lvgl/src/drivers/nuttx/lv_nuttx_libuv.d ./Application/lvgl/src/drivers/nuttx/lv_nuttx_libuv.o ./Application/lvgl/src/drivers/nuttx/lv_nuttx_libuv.su ./Application/lvgl/src/drivers/nuttx/lv_nuttx_profiler.cyclo ./Application/lvgl/src/drivers/nuttx/lv_nuttx_profiler.d ./Application/lvgl/src/drivers/nuttx/lv_nuttx_profiler.o ./Application/lvgl/src/drivers/nuttx/lv_nuttx_profiler.su ./Application/lvgl/src/drivers/nuttx/lv_nuttx_touchscreen.cyclo ./Application/lvgl/src/drivers/nuttx/lv_nuttx_touchscreen.d ./Application/lvgl/src/drivers/nuttx/lv_nuttx_touchscreen.o ./Application/lvgl/src/drivers/nuttx/lv_nuttx_touchscreen.su

.PHONY: clean-Application-2f-lvgl-2f-src-2f-drivers-2f-nuttx

