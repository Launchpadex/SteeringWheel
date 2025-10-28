################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/lvgl/demos/ebike/lv_demo_ebike.c \
../Application/lvgl/demos/ebike/lv_demo_ebike_home.c \
../Application/lvgl/demos/ebike/lv_demo_ebike_settings.c \
../Application/lvgl/demos/ebike/lv_demo_ebike_stats.c 

OBJS += \
./Application/lvgl/demos/ebike/lv_demo_ebike.o \
./Application/lvgl/demos/ebike/lv_demo_ebike_home.o \
./Application/lvgl/demos/ebike/lv_demo_ebike_settings.o \
./Application/lvgl/demos/ebike/lv_demo_ebike_stats.o 

C_DEPS += \
./Application/lvgl/demos/ebike/lv_demo_ebike.d \
./Application/lvgl/demos/ebike/lv_demo_ebike_home.d \
./Application/lvgl/demos/ebike/lv_demo_ebike_settings.d \
./Application/lvgl/demos/ebike/lv_demo_ebike_stats.d 


# Each subdirectory must supply rules for building sources it contributes
Application/lvgl/demos/ebike/%.o Application/lvgl/demos/ebike/%.su Application/lvgl/demos/ebike/%.cyclo: ../Application/lvgl/demos/ebike/%.c Application/lvgl/demos/ebike/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../USB_Device/App -I../USB_Device/Target -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/System/Inc" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/lvgl" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/ui" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/Display" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-lvgl-2f-demos-2f-ebike

clean-Application-2f-lvgl-2f-demos-2f-ebike:
	-$(RM) ./Application/lvgl/demos/ebike/lv_demo_ebike.cyclo ./Application/lvgl/demos/ebike/lv_demo_ebike.d ./Application/lvgl/demos/ebike/lv_demo_ebike.o ./Application/lvgl/demos/ebike/lv_demo_ebike.su ./Application/lvgl/demos/ebike/lv_demo_ebike_home.cyclo ./Application/lvgl/demos/ebike/lv_demo_ebike_home.d ./Application/lvgl/demos/ebike/lv_demo_ebike_home.o ./Application/lvgl/demos/ebike/lv_demo_ebike_home.su ./Application/lvgl/demos/ebike/lv_demo_ebike_settings.cyclo ./Application/lvgl/demos/ebike/lv_demo_ebike_settings.d ./Application/lvgl/demos/ebike/lv_demo_ebike_settings.o ./Application/lvgl/demos/ebike/lv_demo_ebike_settings.su ./Application/lvgl/demos/ebike/lv_demo_ebike_stats.cyclo ./Application/lvgl/demos/ebike/lv_demo_ebike_stats.d ./Application/lvgl/demos/ebike/lv_demo_ebike_stats.o ./Application/lvgl/demos/ebike/lv_demo_ebike_stats.su

.PHONY: clean-Application-2f-lvgl-2f-demos-2f-ebike

