################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_A1_NONE_align64.c \
../Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_A2_NONE_align64.c \
../Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_A4_NONE_align64.c \
../Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_A8_NONE_align64.c \
../Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_ARGB8888_NONE_align64.c \
../Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_I1_NONE_align64.c \
../Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_I2_NONE_align64.c \
../Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_I4_NONE_align64.c \
../Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_I8_NONE_align64.c \
../Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_L8_NONE_align64.c \
../Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_RGB565A8_NONE_align64.c \
../Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_RGB565_NONE_align64.c \
../Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_RGB888_NONE_align64.c \
../Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_XRGB8888_NONE_align64.c 

OBJS += \
./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_A1_NONE_align64.o \
./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_A2_NONE_align64.o \
./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_A4_NONE_align64.o \
./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_A8_NONE_align64.o \
./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_ARGB8888_NONE_align64.o \
./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_I1_NONE_align64.o \
./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_I2_NONE_align64.o \
./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_I4_NONE_align64.o \
./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_I8_NONE_align64.o \
./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_L8_NONE_align64.o \
./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_RGB565A8_NONE_align64.o \
./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_RGB565_NONE_align64.o \
./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_RGB888_NONE_align64.o \
./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_XRGB8888_NONE_align64.o 

C_DEPS += \
./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_A1_NONE_align64.d \
./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_A2_NONE_align64.d \
./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_A4_NONE_align64.d \
./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_A8_NONE_align64.d \
./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_ARGB8888_NONE_align64.d \
./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_I1_NONE_align64.d \
./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_I2_NONE_align64.d \
./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_I4_NONE_align64.d \
./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_I8_NONE_align64.d \
./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_L8_NONE_align64.d \
./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_RGB565A8_NONE_align64.d \
./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_RGB565_NONE_align64.d \
./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_RGB888_NONE_align64.d \
./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_XRGB8888_NONE_align64.d 


# Each subdirectory must supply rules for building sources it contributes
Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/%.o Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/%.su Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/%.cyclo: ../Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/%.c Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../USB_Device/App -I../USB_Device/Target -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/System/Inc" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/lvgl" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/ui" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/Display" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-lvgl-2f-tests-2f-test_images-2f-stride_align64-2f-UNCOMPRESSED

clean-Application-2f-lvgl-2f-tests-2f-test_images-2f-stride_align64-2f-UNCOMPRESSED:
	-$(RM) ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_A1_NONE_align64.cyclo ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_A1_NONE_align64.d ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_A1_NONE_align64.o ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_A1_NONE_align64.su ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_A2_NONE_align64.cyclo ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_A2_NONE_align64.d ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_A2_NONE_align64.o ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_A2_NONE_align64.su ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_A4_NONE_align64.cyclo ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_A4_NONE_align64.d ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_A4_NONE_align64.o ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_A4_NONE_align64.su ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_A8_NONE_align64.cyclo ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_A8_NONE_align64.d ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_A8_NONE_align64.o ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_A8_NONE_align64.su ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_ARGB8888_NONE_align64.cyclo ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_ARGB8888_NONE_align64.d ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_ARGB8888_NONE_align64.o ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_ARGB8888_NONE_align64.su ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_I1_NONE_align64.cyclo ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_I1_NONE_align64.d ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_I1_NONE_align64.o ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_I1_NONE_align64.su ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_I2_NONE_align64.cyclo ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_I2_NONE_align64.d ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_I2_NONE_align64.o ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_I2_NONE_align64.su ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_I4_NONE_align64.cyclo ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_I4_NONE_align64.d ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_I4_NONE_align64.o ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_I4_NONE_align64.su ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_I8_NONE_align64.cyclo ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_I8_NONE_align64.d ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_I8_NONE_align64.o ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_I8_NONE_align64.su ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_L8_NONE_align64.cyclo ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_L8_NONE_align64.d ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_L8_NONE_align64.o ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_L8_NONE_align64.su ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_RGB565A8_NONE_align64.cyclo ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_RGB565A8_NONE_align64.d ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_RGB565A8_NONE_align64.o ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_RGB565A8_NONE_align64.su ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_RGB565_NONE_align64.cyclo ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_RGB565_NONE_align64.d ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_RGB565_NONE_align64.o ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_RGB565_NONE_align64.su ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_RGB888_NONE_align64.cyclo ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_RGB888_NONE_align64.d ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_RGB888_NONE_align64.o ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_RGB888_NONE_align64.su ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_XRGB8888_NONE_align64.cyclo ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_XRGB8888_NONE_align64.d ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_XRGB8888_NONE_align64.o ./Application/lvgl/tests/test_images/stride_align64/UNCOMPRESSED/test_XRGB8888_NONE_align64.su

.PHONY: clean-Application-2f-lvgl-2f-tests-2f-test_images-2f-stride_align64-2f-UNCOMPRESSED

