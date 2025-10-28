################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/lvgl/examples/styles/lv_example_style_1.c \
../Application/lvgl/examples/styles/lv_example_style_10.c \
../Application/lvgl/examples/styles/lv_example_style_11.c \
../Application/lvgl/examples/styles/lv_example_style_12.c \
../Application/lvgl/examples/styles/lv_example_style_13.c \
../Application/lvgl/examples/styles/lv_example_style_14.c \
../Application/lvgl/examples/styles/lv_example_style_15.c \
../Application/lvgl/examples/styles/lv_example_style_16.c \
../Application/lvgl/examples/styles/lv_example_style_17.c \
../Application/lvgl/examples/styles/lv_example_style_18.c \
../Application/lvgl/examples/styles/lv_example_style_2.c \
../Application/lvgl/examples/styles/lv_example_style_3.c \
../Application/lvgl/examples/styles/lv_example_style_4.c \
../Application/lvgl/examples/styles/lv_example_style_5.c \
../Application/lvgl/examples/styles/lv_example_style_6.c \
../Application/lvgl/examples/styles/lv_example_style_7.c \
../Application/lvgl/examples/styles/lv_example_style_8.c \
../Application/lvgl/examples/styles/lv_example_style_9.c 

OBJS += \
./Application/lvgl/examples/styles/lv_example_style_1.o \
./Application/lvgl/examples/styles/lv_example_style_10.o \
./Application/lvgl/examples/styles/lv_example_style_11.o \
./Application/lvgl/examples/styles/lv_example_style_12.o \
./Application/lvgl/examples/styles/lv_example_style_13.o \
./Application/lvgl/examples/styles/lv_example_style_14.o \
./Application/lvgl/examples/styles/lv_example_style_15.o \
./Application/lvgl/examples/styles/lv_example_style_16.o \
./Application/lvgl/examples/styles/lv_example_style_17.o \
./Application/lvgl/examples/styles/lv_example_style_18.o \
./Application/lvgl/examples/styles/lv_example_style_2.o \
./Application/lvgl/examples/styles/lv_example_style_3.o \
./Application/lvgl/examples/styles/lv_example_style_4.o \
./Application/lvgl/examples/styles/lv_example_style_5.o \
./Application/lvgl/examples/styles/lv_example_style_6.o \
./Application/lvgl/examples/styles/lv_example_style_7.o \
./Application/lvgl/examples/styles/lv_example_style_8.o \
./Application/lvgl/examples/styles/lv_example_style_9.o 

C_DEPS += \
./Application/lvgl/examples/styles/lv_example_style_1.d \
./Application/lvgl/examples/styles/lv_example_style_10.d \
./Application/lvgl/examples/styles/lv_example_style_11.d \
./Application/lvgl/examples/styles/lv_example_style_12.d \
./Application/lvgl/examples/styles/lv_example_style_13.d \
./Application/lvgl/examples/styles/lv_example_style_14.d \
./Application/lvgl/examples/styles/lv_example_style_15.d \
./Application/lvgl/examples/styles/lv_example_style_16.d \
./Application/lvgl/examples/styles/lv_example_style_17.d \
./Application/lvgl/examples/styles/lv_example_style_18.d \
./Application/lvgl/examples/styles/lv_example_style_2.d \
./Application/lvgl/examples/styles/lv_example_style_3.d \
./Application/lvgl/examples/styles/lv_example_style_4.d \
./Application/lvgl/examples/styles/lv_example_style_5.d \
./Application/lvgl/examples/styles/lv_example_style_6.d \
./Application/lvgl/examples/styles/lv_example_style_7.d \
./Application/lvgl/examples/styles/lv_example_style_8.d \
./Application/lvgl/examples/styles/lv_example_style_9.d 


# Each subdirectory must supply rules for building sources it contributes
Application/lvgl/examples/styles/%.o Application/lvgl/examples/styles/%.su Application/lvgl/examples/styles/%.cyclo: ../Application/lvgl/examples/styles/%.c Application/lvgl/examples/styles/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../USB_Device/App -I../USB_Device/Target -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/System/Inc" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/lvgl" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/ui" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/Display" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-lvgl-2f-examples-2f-styles

clean-Application-2f-lvgl-2f-examples-2f-styles:
	-$(RM) ./Application/lvgl/examples/styles/lv_example_style_1.cyclo ./Application/lvgl/examples/styles/lv_example_style_1.d ./Application/lvgl/examples/styles/lv_example_style_1.o ./Application/lvgl/examples/styles/lv_example_style_1.su ./Application/lvgl/examples/styles/lv_example_style_10.cyclo ./Application/lvgl/examples/styles/lv_example_style_10.d ./Application/lvgl/examples/styles/lv_example_style_10.o ./Application/lvgl/examples/styles/lv_example_style_10.su ./Application/lvgl/examples/styles/lv_example_style_11.cyclo ./Application/lvgl/examples/styles/lv_example_style_11.d ./Application/lvgl/examples/styles/lv_example_style_11.o ./Application/lvgl/examples/styles/lv_example_style_11.su ./Application/lvgl/examples/styles/lv_example_style_12.cyclo ./Application/lvgl/examples/styles/lv_example_style_12.d ./Application/lvgl/examples/styles/lv_example_style_12.o ./Application/lvgl/examples/styles/lv_example_style_12.su ./Application/lvgl/examples/styles/lv_example_style_13.cyclo ./Application/lvgl/examples/styles/lv_example_style_13.d ./Application/lvgl/examples/styles/lv_example_style_13.o ./Application/lvgl/examples/styles/lv_example_style_13.su ./Application/lvgl/examples/styles/lv_example_style_14.cyclo ./Application/lvgl/examples/styles/lv_example_style_14.d ./Application/lvgl/examples/styles/lv_example_style_14.o ./Application/lvgl/examples/styles/lv_example_style_14.su ./Application/lvgl/examples/styles/lv_example_style_15.cyclo ./Application/lvgl/examples/styles/lv_example_style_15.d ./Application/lvgl/examples/styles/lv_example_style_15.o ./Application/lvgl/examples/styles/lv_example_style_15.su ./Application/lvgl/examples/styles/lv_example_style_16.cyclo ./Application/lvgl/examples/styles/lv_example_style_16.d ./Application/lvgl/examples/styles/lv_example_style_16.o ./Application/lvgl/examples/styles/lv_example_style_16.su ./Application/lvgl/examples/styles/lv_example_style_17.cyclo ./Application/lvgl/examples/styles/lv_example_style_17.d ./Application/lvgl/examples/styles/lv_example_style_17.o ./Application/lvgl/examples/styles/lv_example_style_17.su ./Application/lvgl/examples/styles/lv_example_style_18.cyclo ./Application/lvgl/examples/styles/lv_example_style_18.d ./Application/lvgl/examples/styles/lv_example_style_18.o ./Application/lvgl/examples/styles/lv_example_style_18.su ./Application/lvgl/examples/styles/lv_example_style_2.cyclo ./Application/lvgl/examples/styles/lv_example_style_2.d ./Application/lvgl/examples/styles/lv_example_style_2.o ./Application/lvgl/examples/styles/lv_example_style_2.su ./Application/lvgl/examples/styles/lv_example_style_3.cyclo ./Application/lvgl/examples/styles/lv_example_style_3.d ./Application/lvgl/examples/styles/lv_example_style_3.o ./Application/lvgl/examples/styles/lv_example_style_3.su ./Application/lvgl/examples/styles/lv_example_style_4.cyclo ./Application/lvgl/examples/styles/lv_example_style_4.d ./Application/lvgl/examples/styles/lv_example_style_4.o ./Application/lvgl/examples/styles/lv_example_style_4.su ./Application/lvgl/examples/styles/lv_example_style_5.cyclo ./Application/lvgl/examples/styles/lv_example_style_5.d ./Application/lvgl/examples/styles/lv_example_style_5.o ./Application/lvgl/examples/styles/lv_example_style_5.su ./Application/lvgl/examples/styles/lv_example_style_6.cyclo ./Application/lvgl/examples/styles/lv_example_style_6.d ./Application/lvgl/examples/styles/lv_example_style_6.o ./Application/lvgl/examples/styles/lv_example_style_6.su ./Application/lvgl/examples/styles/lv_example_style_7.cyclo ./Application/lvgl/examples/styles/lv_example_style_7.d ./Application/lvgl/examples/styles/lv_example_style_7.o ./Application/lvgl/examples/styles/lv_example_style_7.su ./Application/lvgl/examples/styles/lv_example_style_8.cyclo ./Application/lvgl/examples/styles/lv_example_style_8.d ./Application/lvgl/examples/styles/lv_example_style_8.o ./Application/lvgl/examples/styles/lv_example_style_8.su ./Application/lvgl/examples/styles/lv_example_style_9.cyclo ./Application/lvgl/examples/styles/lv_example_style_9.d ./Application/lvgl/examples/styles/lv_example_style_9.o ./Application/lvgl/examples/styles/lv_example_style_9.su

.PHONY: clean-Application-2f-lvgl-2f-examples-2f-styles

