################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/lvgl/demos/high_res/lv_demo_high_res.c \
../Application/lvgl/demos/high_res/lv_demo_high_res_api_example.c \
../Application/lvgl/demos/high_res/lv_demo_high_res_app_about.c \
../Application/lvgl/demos/high_res/lv_demo_high_res_app_ev_charging.c \
../Application/lvgl/demos/high_res/lv_demo_high_res_app_smart_home.c \
../Application/lvgl/demos/high_res/lv_demo_high_res_app_smart_meter.c \
../Application/lvgl/demos/high_res/lv_demo_high_res_app_thermostat.c \
../Application/lvgl/demos/high_res/lv_demo_high_res_home.c \
../Application/lvgl/demos/high_res/lv_demo_high_res_top_margin.c \
../Application/lvgl/demos/high_res/lv_demo_high_res_util.c 

OBJS += \
./Application/lvgl/demos/high_res/lv_demo_high_res.o \
./Application/lvgl/demos/high_res/lv_demo_high_res_api_example.o \
./Application/lvgl/demos/high_res/lv_demo_high_res_app_about.o \
./Application/lvgl/demos/high_res/lv_demo_high_res_app_ev_charging.o \
./Application/lvgl/demos/high_res/lv_demo_high_res_app_smart_home.o \
./Application/lvgl/demos/high_res/lv_demo_high_res_app_smart_meter.o \
./Application/lvgl/demos/high_res/lv_demo_high_res_app_thermostat.o \
./Application/lvgl/demos/high_res/lv_demo_high_res_home.o \
./Application/lvgl/demos/high_res/lv_demo_high_res_top_margin.o \
./Application/lvgl/demos/high_res/lv_demo_high_res_util.o 

C_DEPS += \
./Application/lvgl/demos/high_res/lv_demo_high_res.d \
./Application/lvgl/demos/high_res/lv_demo_high_res_api_example.d \
./Application/lvgl/demos/high_res/lv_demo_high_res_app_about.d \
./Application/lvgl/demos/high_res/lv_demo_high_res_app_ev_charging.d \
./Application/lvgl/demos/high_res/lv_demo_high_res_app_smart_home.d \
./Application/lvgl/demos/high_res/lv_demo_high_res_app_smart_meter.d \
./Application/lvgl/demos/high_res/lv_demo_high_res_app_thermostat.d \
./Application/lvgl/demos/high_res/lv_demo_high_res_home.d \
./Application/lvgl/demos/high_res/lv_demo_high_res_top_margin.d \
./Application/lvgl/demos/high_res/lv_demo_high_res_util.d 


# Each subdirectory must supply rules for building sources it contributes
Application/lvgl/demos/high_res/%.o Application/lvgl/demos/high_res/%.su Application/lvgl/demos/high_res/%.cyclo: ../Application/lvgl/demos/high_res/%.c Application/lvgl/demos/high_res/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../USB_Device/App -I../USB_Device/Target -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/System/Inc" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/lvgl" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/ui" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/Display" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-lvgl-2f-demos-2f-high_res

clean-Application-2f-lvgl-2f-demos-2f-high_res:
	-$(RM) ./Application/lvgl/demos/high_res/lv_demo_high_res.cyclo ./Application/lvgl/demos/high_res/lv_demo_high_res.d ./Application/lvgl/demos/high_res/lv_demo_high_res.o ./Application/lvgl/demos/high_res/lv_demo_high_res.su ./Application/lvgl/demos/high_res/lv_demo_high_res_api_example.cyclo ./Application/lvgl/demos/high_res/lv_demo_high_res_api_example.d ./Application/lvgl/demos/high_res/lv_demo_high_res_api_example.o ./Application/lvgl/demos/high_res/lv_demo_high_res_api_example.su ./Application/lvgl/demos/high_res/lv_demo_high_res_app_about.cyclo ./Application/lvgl/demos/high_res/lv_demo_high_res_app_about.d ./Application/lvgl/demos/high_res/lv_demo_high_res_app_about.o ./Application/lvgl/demos/high_res/lv_demo_high_res_app_about.su ./Application/lvgl/demos/high_res/lv_demo_high_res_app_ev_charging.cyclo ./Application/lvgl/demos/high_res/lv_demo_high_res_app_ev_charging.d ./Application/lvgl/demos/high_res/lv_demo_high_res_app_ev_charging.o ./Application/lvgl/demos/high_res/lv_demo_high_res_app_ev_charging.su ./Application/lvgl/demos/high_res/lv_demo_high_res_app_smart_home.cyclo ./Application/lvgl/demos/high_res/lv_demo_high_res_app_smart_home.d ./Application/lvgl/demos/high_res/lv_demo_high_res_app_smart_home.o ./Application/lvgl/demos/high_res/lv_demo_high_res_app_smart_home.su ./Application/lvgl/demos/high_res/lv_demo_high_res_app_smart_meter.cyclo ./Application/lvgl/demos/high_res/lv_demo_high_res_app_smart_meter.d ./Application/lvgl/demos/high_res/lv_demo_high_res_app_smart_meter.o ./Application/lvgl/demos/high_res/lv_demo_high_res_app_smart_meter.su ./Application/lvgl/demos/high_res/lv_demo_high_res_app_thermostat.cyclo ./Application/lvgl/demos/high_res/lv_demo_high_res_app_thermostat.d ./Application/lvgl/demos/high_res/lv_demo_high_res_app_thermostat.o ./Application/lvgl/demos/high_res/lv_demo_high_res_app_thermostat.su ./Application/lvgl/demos/high_res/lv_demo_high_res_home.cyclo ./Application/lvgl/demos/high_res/lv_demo_high_res_home.d ./Application/lvgl/demos/high_res/lv_demo_high_res_home.o ./Application/lvgl/demos/high_res/lv_demo_high_res_home.su ./Application/lvgl/demos/high_res/lv_demo_high_res_top_margin.cyclo ./Application/lvgl/demos/high_res/lv_demo_high_res_top_margin.d ./Application/lvgl/demos/high_res/lv_demo_high_res_top_margin.o ./Application/lvgl/demos/high_res/lv_demo_high_res_top_margin.su ./Application/lvgl/demos/high_res/lv_demo_high_res_util.cyclo ./Application/lvgl/demos/high_res/lv_demo_high_res_util.d ./Application/lvgl/demos/high_res/lv_demo_high_res_util.o ./Application/lvgl/demos/high_res/lv_demo_high_res_util.su

.PHONY: clean-Application-2f-lvgl-2f-demos-2f-high_res

