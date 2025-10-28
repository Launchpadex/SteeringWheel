################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/lvgl/src/misc/cache/lv_cache.c \
../Application/lvgl/src/misc/cache/lv_cache_entry.c \
../Application/lvgl/src/misc/cache/lv_cache_lru_rb.c \
../Application/lvgl/src/misc/cache/lv_image_cache.c \
../Application/lvgl/src/misc/cache/lv_image_header_cache.c 

OBJS += \
./Application/lvgl/src/misc/cache/lv_cache.o \
./Application/lvgl/src/misc/cache/lv_cache_entry.o \
./Application/lvgl/src/misc/cache/lv_cache_lru_rb.o \
./Application/lvgl/src/misc/cache/lv_image_cache.o \
./Application/lvgl/src/misc/cache/lv_image_header_cache.o 

C_DEPS += \
./Application/lvgl/src/misc/cache/lv_cache.d \
./Application/lvgl/src/misc/cache/lv_cache_entry.d \
./Application/lvgl/src/misc/cache/lv_cache_lru_rb.d \
./Application/lvgl/src/misc/cache/lv_image_cache.d \
./Application/lvgl/src/misc/cache/lv_image_header_cache.d 


# Each subdirectory must supply rules for building sources it contributes
Application/lvgl/src/misc/cache/%.o Application/lvgl/src/misc/cache/%.su Application/lvgl/src/misc/cache/%.cyclo: ../Application/lvgl/src/misc/cache/%.c Application/lvgl/src/misc/cache/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../USB_Device/App -I../USB_Device/Target -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/System/Inc" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/lvgl" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/ui" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/Display" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-lvgl-2f-src-2f-misc-2f-cache

clean-Application-2f-lvgl-2f-src-2f-misc-2f-cache:
	-$(RM) ./Application/lvgl/src/misc/cache/lv_cache.cyclo ./Application/lvgl/src/misc/cache/lv_cache.d ./Application/lvgl/src/misc/cache/lv_cache.o ./Application/lvgl/src/misc/cache/lv_cache.su ./Application/lvgl/src/misc/cache/lv_cache_entry.cyclo ./Application/lvgl/src/misc/cache/lv_cache_entry.d ./Application/lvgl/src/misc/cache/lv_cache_entry.o ./Application/lvgl/src/misc/cache/lv_cache_entry.su ./Application/lvgl/src/misc/cache/lv_cache_lru_rb.cyclo ./Application/lvgl/src/misc/cache/lv_cache_lru_rb.d ./Application/lvgl/src/misc/cache/lv_cache_lru_rb.o ./Application/lvgl/src/misc/cache/lv_cache_lru_rb.su ./Application/lvgl/src/misc/cache/lv_image_cache.cyclo ./Application/lvgl/src/misc/cache/lv_image_cache.d ./Application/lvgl/src/misc/cache/lv_image_cache.o ./Application/lvgl/src/misc/cache/lv_image_cache.su ./Application/lvgl/src/misc/cache/lv_image_header_cache.cyclo ./Application/lvgl/src/misc/cache/lv_image_header_cache.d ./Application/lvgl/src/misc/cache/lv_image_header_cache.o ./Application/lvgl/src/misc/cache/lv_image_header_cache.su

.PHONY: clean-Application-2f-lvgl-2f-src-2f-misc-2f-cache

