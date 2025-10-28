################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/lvgl/env_support/pikascript/pika_lv_point_t.c \
../Application/lvgl/env_support/pikascript/pika_lv_timer_t.c \
../Application/lvgl/env_support/pikascript/pika_lv_wegit.c \
../Application/lvgl/env_support/pikascript/pika_lvgl.c \
../Application/lvgl/env_support/pikascript/pika_lvgl_indev_t.c \
../Application/lvgl/env_support/pikascript/pika_lvgl_lv_event.c \
../Application/lvgl/env_support/pikascript/pika_lvgl_lv_obj.c \
../Application/lvgl/env_support/pikascript/pika_lvgl_lv_style_t.c 

OBJS += \
./Application/lvgl/env_support/pikascript/pika_lv_point_t.o \
./Application/lvgl/env_support/pikascript/pika_lv_timer_t.o \
./Application/lvgl/env_support/pikascript/pika_lv_wegit.o \
./Application/lvgl/env_support/pikascript/pika_lvgl.o \
./Application/lvgl/env_support/pikascript/pika_lvgl_indev_t.o \
./Application/lvgl/env_support/pikascript/pika_lvgl_lv_event.o \
./Application/lvgl/env_support/pikascript/pika_lvgl_lv_obj.o \
./Application/lvgl/env_support/pikascript/pika_lvgl_lv_style_t.o 

C_DEPS += \
./Application/lvgl/env_support/pikascript/pika_lv_point_t.d \
./Application/lvgl/env_support/pikascript/pika_lv_timer_t.d \
./Application/lvgl/env_support/pikascript/pika_lv_wegit.d \
./Application/lvgl/env_support/pikascript/pika_lvgl.d \
./Application/lvgl/env_support/pikascript/pika_lvgl_indev_t.d \
./Application/lvgl/env_support/pikascript/pika_lvgl_lv_event.d \
./Application/lvgl/env_support/pikascript/pika_lvgl_lv_obj.d \
./Application/lvgl/env_support/pikascript/pika_lvgl_lv_style_t.d 


# Each subdirectory must supply rules for building sources it contributes
Application/lvgl/env_support/pikascript/%.o Application/lvgl/env_support/pikascript/%.su Application/lvgl/env_support/pikascript/%.cyclo: ../Application/lvgl/env_support/pikascript/%.c Application/lvgl/env_support/pikascript/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../USB_Device/App -I../USB_Device/Target -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/System/Inc" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/lvgl" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/ui" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/Display" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-lvgl-2f-env_support-2f-pikascript

clean-Application-2f-lvgl-2f-env_support-2f-pikascript:
	-$(RM) ./Application/lvgl/env_support/pikascript/pika_lv_point_t.cyclo ./Application/lvgl/env_support/pikascript/pika_lv_point_t.d ./Application/lvgl/env_support/pikascript/pika_lv_point_t.o ./Application/lvgl/env_support/pikascript/pika_lv_point_t.su ./Application/lvgl/env_support/pikascript/pika_lv_timer_t.cyclo ./Application/lvgl/env_support/pikascript/pika_lv_timer_t.d ./Application/lvgl/env_support/pikascript/pika_lv_timer_t.o ./Application/lvgl/env_support/pikascript/pika_lv_timer_t.su ./Application/lvgl/env_support/pikascript/pika_lv_wegit.cyclo ./Application/lvgl/env_support/pikascript/pika_lv_wegit.d ./Application/lvgl/env_support/pikascript/pika_lv_wegit.o ./Application/lvgl/env_support/pikascript/pika_lv_wegit.su ./Application/lvgl/env_support/pikascript/pika_lvgl.cyclo ./Application/lvgl/env_support/pikascript/pika_lvgl.d ./Application/lvgl/env_support/pikascript/pika_lvgl.o ./Application/lvgl/env_support/pikascript/pika_lvgl.su ./Application/lvgl/env_support/pikascript/pika_lvgl_indev_t.cyclo ./Application/lvgl/env_support/pikascript/pika_lvgl_indev_t.d ./Application/lvgl/env_support/pikascript/pika_lvgl_indev_t.o ./Application/lvgl/env_support/pikascript/pika_lvgl_indev_t.su ./Application/lvgl/env_support/pikascript/pika_lvgl_lv_event.cyclo ./Application/lvgl/env_support/pikascript/pika_lvgl_lv_event.d ./Application/lvgl/env_support/pikascript/pika_lvgl_lv_event.o ./Application/lvgl/env_support/pikascript/pika_lvgl_lv_event.su ./Application/lvgl/env_support/pikascript/pika_lvgl_lv_obj.cyclo ./Application/lvgl/env_support/pikascript/pika_lvgl_lv_obj.d ./Application/lvgl/env_support/pikascript/pika_lvgl_lv_obj.o ./Application/lvgl/env_support/pikascript/pika_lvgl_lv_obj.su ./Application/lvgl/env_support/pikascript/pika_lvgl_lv_style_t.cyclo ./Application/lvgl/env_support/pikascript/pika_lvgl_lv_style_t.d ./Application/lvgl/env_support/pikascript/pika_lvgl_lv_style_t.o ./Application/lvgl/env_support/pikascript/pika_lvgl_lv_style_t.su

.PHONY: clean-Application-2f-lvgl-2f-env_support-2f-pikascript

