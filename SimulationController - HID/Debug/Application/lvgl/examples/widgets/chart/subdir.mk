################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/lvgl/examples/widgets/chart/lv_example_chart_1.c \
../Application/lvgl/examples/widgets/chart/lv_example_chart_2.c \
../Application/lvgl/examples/widgets/chart/lv_example_chart_3.c \
../Application/lvgl/examples/widgets/chart/lv_example_chart_4.c \
../Application/lvgl/examples/widgets/chart/lv_example_chart_5.c \
../Application/lvgl/examples/widgets/chart/lv_example_chart_6.c \
../Application/lvgl/examples/widgets/chart/lv_example_chart_7.c \
../Application/lvgl/examples/widgets/chart/lv_example_chart_8.c 

OBJS += \
./Application/lvgl/examples/widgets/chart/lv_example_chart_1.o \
./Application/lvgl/examples/widgets/chart/lv_example_chart_2.o \
./Application/lvgl/examples/widgets/chart/lv_example_chart_3.o \
./Application/lvgl/examples/widgets/chart/lv_example_chart_4.o \
./Application/lvgl/examples/widgets/chart/lv_example_chart_5.o \
./Application/lvgl/examples/widgets/chart/lv_example_chart_6.o \
./Application/lvgl/examples/widgets/chart/lv_example_chart_7.o \
./Application/lvgl/examples/widgets/chart/lv_example_chart_8.o 

C_DEPS += \
./Application/lvgl/examples/widgets/chart/lv_example_chart_1.d \
./Application/lvgl/examples/widgets/chart/lv_example_chart_2.d \
./Application/lvgl/examples/widgets/chart/lv_example_chart_3.d \
./Application/lvgl/examples/widgets/chart/lv_example_chart_4.d \
./Application/lvgl/examples/widgets/chart/lv_example_chart_5.d \
./Application/lvgl/examples/widgets/chart/lv_example_chart_6.d \
./Application/lvgl/examples/widgets/chart/lv_example_chart_7.d \
./Application/lvgl/examples/widgets/chart/lv_example_chart_8.d 


# Each subdirectory must supply rules for building sources it contributes
Application/lvgl/examples/widgets/chart/%.o Application/lvgl/examples/widgets/chart/%.su Application/lvgl/examples/widgets/chart/%.cyclo: ../Application/lvgl/examples/widgets/chart/%.c Application/lvgl/examples/widgets/chart/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../USB_Device/App -I../USB_Device/Target -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/System/Inc" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/lvgl" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/ui" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/Display" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-lvgl-2f-examples-2f-widgets-2f-chart

clean-Application-2f-lvgl-2f-examples-2f-widgets-2f-chart:
	-$(RM) ./Application/lvgl/examples/widgets/chart/lv_example_chart_1.cyclo ./Application/lvgl/examples/widgets/chart/lv_example_chart_1.d ./Application/lvgl/examples/widgets/chart/lv_example_chart_1.o ./Application/lvgl/examples/widgets/chart/lv_example_chart_1.su ./Application/lvgl/examples/widgets/chart/lv_example_chart_2.cyclo ./Application/lvgl/examples/widgets/chart/lv_example_chart_2.d ./Application/lvgl/examples/widgets/chart/lv_example_chart_2.o ./Application/lvgl/examples/widgets/chart/lv_example_chart_2.su ./Application/lvgl/examples/widgets/chart/lv_example_chart_3.cyclo ./Application/lvgl/examples/widgets/chart/lv_example_chart_3.d ./Application/lvgl/examples/widgets/chart/lv_example_chart_3.o ./Application/lvgl/examples/widgets/chart/lv_example_chart_3.su ./Application/lvgl/examples/widgets/chart/lv_example_chart_4.cyclo ./Application/lvgl/examples/widgets/chart/lv_example_chart_4.d ./Application/lvgl/examples/widgets/chart/lv_example_chart_4.o ./Application/lvgl/examples/widgets/chart/lv_example_chart_4.su ./Application/lvgl/examples/widgets/chart/lv_example_chart_5.cyclo ./Application/lvgl/examples/widgets/chart/lv_example_chart_5.d ./Application/lvgl/examples/widgets/chart/lv_example_chart_5.o ./Application/lvgl/examples/widgets/chart/lv_example_chart_5.su ./Application/lvgl/examples/widgets/chart/lv_example_chart_6.cyclo ./Application/lvgl/examples/widgets/chart/lv_example_chart_6.d ./Application/lvgl/examples/widgets/chart/lv_example_chart_6.o ./Application/lvgl/examples/widgets/chart/lv_example_chart_6.su ./Application/lvgl/examples/widgets/chart/lv_example_chart_7.cyclo ./Application/lvgl/examples/widgets/chart/lv_example_chart_7.d ./Application/lvgl/examples/widgets/chart/lv_example_chart_7.o ./Application/lvgl/examples/widgets/chart/lv_example_chart_7.su ./Application/lvgl/examples/widgets/chart/lv_example_chart_8.cyclo ./Application/lvgl/examples/widgets/chart/lv_example_chart_8.d ./Application/lvgl/examples/widgets/chart/lv_example_chart_8.o ./Application/lvgl/examples/widgets/chart/lv_example_chart_8.su

.PHONY: clean-Application-2f-lvgl-2f-examples-2f-widgets-2f-chart

