################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/lvgl/examples/widgets/scale/lv_example_scale_1.c \
../Application/lvgl/examples/widgets/scale/lv_example_scale_2.c \
../Application/lvgl/examples/widgets/scale/lv_example_scale_3.c \
../Application/lvgl/examples/widgets/scale/lv_example_scale_4.c \
../Application/lvgl/examples/widgets/scale/lv_example_scale_5.c \
../Application/lvgl/examples/widgets/scale/lv_example_scale_6.c \
../Application/lvgl/examples/widgets/scale/lv_example_scale_7.c \
../Application/lvgl/examples/widgets/scale/lv_example_scale_8.c \
../Application/lvgl/examples/widgets/scale/lv_example_scale_9.c 

OBJS += \
./Application/lvgl/examples/widgets/scale/lv_example_scale_1.o \
./Application/lvgl/examples/widgets/scale/lv_example_scale_2.o \
./Application/lvgl/examples/widgets/scale/lv_example_scale_3.o \
./Application/lvgl/examples/widgets/scale/lv_example_scale_4.o \
./Application/lvgl/examples/widgets/scale/lv_example_scale_5.o \
./Application/lvgl/examples/widgets/scale/lv_example_scale_6.o \
./Application/lvgl/examples/widgets/scale/lv_example_scale_7.o \
./Application/lvgl/examples/widgets/scale/lv_example_scale_8.o \
./Application/lvgl/examples/widgets/scale/lv_example_scale_9.o 

C_DEPS += \
./Application/lvgl/examples/widgets/scale/lv_example_scale_1.d \
./Application/lvgl/examples/widgets/scale/lv_example_scale_2.d \
./Application/lvgl/examples/widgets/scale/lv_example_scale_3.d \
./Application/lvgl/examples/widgets/scale/lv_example_scale_4.d \
./Application/lvgl/examples/widgets/scale/lv_example_scale_5.d \
./Application/lvgl/examples/widgets/scale/lv_example_scale_6.d \
./Application/lvgl/examples/widgets/scale/lv_example_scale_7.d \
./Application/lvgl/examples/widgets/scale/lv_example_scale_8.d \
./Application/lvgl/examples/widgets/scale/lv_example_scale_9.d 


# Each subdirectory must supply rules for building sources it contributes
Application/lvgl/examples/widgets/scale/%.o Application/lvgl/examples/widgets/scale/%.su Application/lvgl/examples/widgets/scale/%.cyclo: ../Application/lvgl/examples/widgets/scale/%.c Application/lvgl/examples/widgets/scale/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../USB_Device/App -I../USB_Device/Target -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/System/Inc" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/lvgl" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/ui" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/Display" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-lvgl-2f-examples-2f-widgets-2f-scale

clean-Application-2f-lvgl-2f-examples-2f-widgets-2f-scale:
	-$(RM) ./Application/lvgl/examples/widgets/scale/lv_example_scale_1.cyclo ./Application/lvgl/examples/widgets/scale/lv_example_scale_1.d ./Application/lvgl/examples/widgets/scale/lv_example_scale_1.o ./Application/lvgl/examples/widgets/scale/lv_example_scale_1.su ./Application/lvgl/examples/widgets/scale/lv_example_scale_2.cyclo ./Application/lvgl/examples/widgets/scale/lv_example_scale_2.d ./Application/lvgl/examples/widgets/scale/lv_example_scale_2.o ./Application/lvgl/examples/widgets/scale/lv_example_scale_2.su ./Application/lvgl/examples/widgets/scale/lv_example_scale_3.cyclo ./Application/lvgl/examples/widgets/scale/lv_example_scale_3.d ./Application/lvgl/examples/widgets/scale/lv_example_scale_3.o ./Application/lvgl/examples/widgets/scale/lv_example_scale_3.su ./Application/lvgl/examples/widgets/scale/lv_example_scale_4.cyclo ./Application/lvgl/examples/widgets/scale/lv_example_scale_4.d ./Application/lvgl/examples/widgets/scale/lv_example_scale_4.o ./Application/lvgl/examples/widgets/scale/lv_example_scale_4.su ./Application/lvgl/examples/widgets/scale/lv_example_scale_5.cyclo ./Application/lvgl/examples/widgets/scale/lv_example_scale_5.d ./Application/lvgl/examples/widgets/scale/lv_example_scale_5.o ./Application/lvgl/examples/widgets/scale/lv_example_scale_5.su ./Application/lvgl/examples/widgets/scale/lv_example_scale_6.cyclo ./Application/lvgl/examples/widgets/scale/lv_example_scale_6.d ./Application/lvgl/examples/widgets/scale/lv_example_scale_6.o ./Application/lvgl/examples/widgets/scale/lv_example_scale_6.su ./Application/lvgl/examples/widgets/scale/lv_example_scale_7.cyclo ./Application/lvgl/examples/widgets/scale/lv_example_scale_7.d ./Application/lvgl/examples/widgets/scale/lv_example_scale_7.o ./Application/lvgl/examples/widgets/scale/lv_example_scale_7.su ./Application/lvgl/examples/widgets/scale/lv_example_scale_8.cyclo ./Application/lvgl/examples/widgets/scale/lv_example_scale_8.d ./Application/lvgl/examples/widgets/scale/lv_example_scale_8.o ./Application/lvgl/examples/widgets/scale/lv_example_scale_8.su ./Application/lvgl/examples/widgets/scale/lv_example_scale_9.cyclo ./Application/lvgl/examples/widgets/scale/lv_example_scale_9.d ./Application/lvgl/examples/widgets/scale/lv_example_scale_9.o ./Application/lvgl/examples/widgets/scale/lv_example_scale_9.su

.PHONY: clean-Application-2f-lvgl-2f-examples-2f-widgets-2f-scale

