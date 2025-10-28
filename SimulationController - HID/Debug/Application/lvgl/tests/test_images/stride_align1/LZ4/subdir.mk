################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/lvgl/tests/test_images/stride_align1/LZ4/test_A1_LZ4_align1.c \
../Application/lvgl/tests/test_images/stride_align1/LZ4/test_A2_LZ4_align1.c \
../Application/lvgl/tests/test_images/stride_align1/LZ4/test_A4_LZ4_align1.c \
../Application/lvgl/tests/test_images/stride_align1/LZ4/test_A8_LZ4_align1.c \
../Application/lvgl/tests/test_images/stride_align1/LZ4/test_ARGB8888_LZ4_align1.c \
../Application/lvgl/tests/test_images/stride_align1/LZ4/test_I1_LZ4_align1.c \
../Application/lvgl/tests/test_images/stride_align1/LZ4/test_I2_LZ4_align1.c \
../Application/lvgl/tests/test_images/stride_align1/LZ4/test_I4_LZ4_align1.c \
../Application/lvgl/tests/test_images/stride_align1/LZ4/test_I8_LZ4_align1.c \
../Application/lvgl/tests/test_images/stride_align1/LZ4/test_L8_LZ4_align1.c \
../Application/lvgl/tests/test_images/stride_align1/LZ4/test_RGB565A8_LZ4_align1.c \
../Application/lvgl/tests/test_images/stride_align1/LZ4/test_RGB565_LZ4_align1.c \
../Application/lvgl/tests/test_images/stride_align1/LZ4/test_RGB888_LZ4_align1.c \
../Application/lvgl/tests/test_images/stride_align1/LZ4/test_XRGB8888_LZ4_align1.c 

OBJS += \
./Application/lvgl/tests/test_images/stride_align1/LZ4/test_A1_LZ4_align1.o \
./Application/lvgl/tests/test_images/stride_align1/LZ4/test_A2_LZ4_align1.o \
./Application/lvgl/tests/test_images/stride_align1/LZ4/test_A4_LZ4_align1.o \
./Application/lvgl/tests/test_images/stride_align1/LZ4/test_A8_LZ4_align1.o \
./Application/lvgl/tests/test_images/stride_align1/LZ4/test_ARGB8888_LZ4_align1.o \
./Application/lvgl/tests/test_images/stride_align1/LZ4/test_I1_LZ4_align1.o \
./Application/lvgl/tests/test_images/stride_align1/LZ4/test_I2_LZ4_align1.o \
./Application/lvgl/tests/test_images/stride_align1/LZ4/test_I4_LZ4_align1.o \
./Application/lvgl/tests/test_images/stride_align1/LZ4/test_I8_LZ4_align1.o \
./Application/lvgl/tests/test_images/stride_align1/LZ4/test_L8_LZ4_align1.o \
./Application/lvgl/tests/test_images/stride_align1/LZ4/test_RGB565A8_LZ4_align1.o \
./Application/lvgl/tests/test_images/stride_align1/LZ4/test_RGB565_LZ4_align1.o \
./Application/lvgl/tests/test_images/stride_align1/LZ4/test_RGB888_LZ4_align1.o \
./Application/lvgl/tests/test_images/stride_align1/LZ4/test_XRGB8888_LZ4_align1.o 

C_DEPS += \
./Application/lvgl/tests/test_images/stride_align1/LZ4/test_A1_LZ4_align1.d \
./Application/lvgl/tests/test_images/stride_align1/LZ4/test_A2_LZ4_align1.d \
./Application/lvgl/tests/test_images/stride_align1/LZ4/test_A4_LZ4_align1.d \
./Application/lvgl/tests/test_images/stride_align1/LZ4/test_A8_LZ4_align1.d \
./Application/lvgl/tests/test_images/stride_align1/LZ4/test_ARGB8888_LZ4_align1.d \
./Application/lvgl/tests/test_images/stride_align1/LZ4/test_I1_LZ4_align1.d \
./Application/lvgl/tests/test_images/stride_align1/LZ4/test_I2_LZ4_align1.d \
./Application/lvgl/tests/test_images/stride_align1/LZ4/test_I4_LZ4_align1.d \
./Application/lvgl/tests/test_images/stride_align1/LZ4/test_I8_LZ4_align1.d \
./Application/lvgl/tests/test_images/stride_align1/LZ4/test_L8_LZ4_align1.d \
./Application/lvgl/tests/test_images/stride_align1/LZ4/test_RGB565A8_LZ4_align1.d \
./Application/lvgl/tests/test_images/stride_align1/LZ4/test_RGB565_LZ4_align1.d \
./Application/lvgl/tests/test_images/stride_align1/LZ4/test_RGB888_LZ4_align1.d \
./Application/lvgl/tests/test_images/stride_align1/LZ4/test_XRGB8888_LZ4_align1.d 


# Each subdirectory must supply rules for building sources it contributes
Application/lvgl/tests/test_images/stride_align1/LZ4/%.o Application/lvgl/tests/test_images/stride_align1/LZ4/%.su Application/lvgl/tests/test_images/stride_align1/LZ4/%.cyclo: ../Application/lvgl/tests/test_images/stride_align1/LZ4/%.c Application/lvgl/tests/test_images/stride_align1/LZ4/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../USB_Device/App -I../USB_Device/Target -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/System/Inc" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/lvgl" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/ui" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/Display" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-lvgl-2f-tests-2f-test_images-2f-stride_align1-2f-LZ4

clean-Application-2f-lvgl-2f-tests-2f-test_images-2f-stride_align1-2f-LZ4:
	-$(RM) ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_A1_LZ4_align1.cyclo ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_A1_LZ4_align1.d ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_A1_LZ4_align1.o ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_A1_LZ4_align1.su ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_A2_LZ4_align1.cyclo ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_A2_LZ4_align1.d ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_A2_LZ4_align1.o ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_A2_LZ4_align1.su ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_A4_LZ4_align1.cyclo ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_A4_LZ4_align1.d ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_A4_LZ4_align1.o ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_A4_LZ4_align1.su ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_A8_LZ4_align1.cyclo ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_A8_LZ4_align1.d ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_A8_LZ4_align1.o ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_A8_LZ4_align1.su ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_ARGB8888_LZ4_align1.cyclo ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_ARGB8888_LZ4_align1.d ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_ARGB8888_LZ4_align1.o ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_ARGB8888_LZ4_align1.su ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_I1_LZ4_align1.cyclo ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_I1_LZ4_align1.d ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_I1_LZ4_align1.o ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_I1_LZ4_align1.su ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_I2_LZ4_align1.cyclo ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_I2_LZ4_align1.d ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_I2_LZ4_align1.o ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_I2_LZ4_align1.su ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_I4_LZ4_align1.cyclo ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_I4_LZ4_align1.d ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_I4_LZ4_align1.o ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_I4_LZ4_align1.su ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_I8_LZ4_align1.cyclo ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_I8_LZ4_align1.d ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_I8_LZ4_align1.o ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_I8_LZ4_align1.su ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_L8_LZ4_align1.cyclo ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_L8_LZ4_align1.d ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_L8_LZ4_align1.o ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_L8_LZ4_align1.su ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_RGB565A8_LZ4_align1.cyclo ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_RGB565A8_LZ4_align1.d ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_RGB565A8_LZ4_align1.o ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_RGB565A8_LZ4_align1.su ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_RGB565_LZ4_align1.cyclo ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_RGB565_LZ4_align1.d ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_RGB565_LZ4_align1.o ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_RGB565_LZ4_align1.su ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_RGB888_LZ4_align1.cyclo ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_RGB888_LZ4_align1.d ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_RGB888_LZ4_align1.o ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_RGB888_LZ4_align1.su ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_XRGB8888_LZ4_align1.cyclo ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_XRGB8888_LZ4_align1.d ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_XRGB8888_LZ4_align1.o ./Application/lvgl/tests/test_images/stride_align1/LZ4/test_XRGB8888_LZ4_align1.su

.PHONY: clean-Application-2f-lvgl-2f-tests-2f-test_images-2f-stride_align1-2f-LZ4

