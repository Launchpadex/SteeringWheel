################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/Display/Src/font12.c \
../Application/Display/Src/font24.c \
../Application/Display/Src/ili9341.c \
../Application/Display/Src/lvgl_lcd.c \
../Application/Display/Src/misko_touch.c 

OBJS += \
./Application/Display/Src/font12.o \
./Application/Display/Src/font24.o \
./Application/Display/Src/ili9341.o \
./Application/Display/Src/lvgl_lcd.o \
./Application/Display/Src/misko_touch.o 

C_DEPS += \
./Application/Display/Src/font12.d \
./Application/Display/Src/font24.d \
./Application/Display/Src/ili9341.d \
./Application/Display/Src/lvgl_lcd.d \
./Application/Display/Src/misko_touch.d 


# Each subdirectory must supply rules for building sources it contributes
Application/Display/Src/%.o Application/Display/Src/%.su Application/Display/Src/%.cyclo: ../Application/Display/Src/%.c Application/Display/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../USB_Device/App -I../USB_Device/Target -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/System/Inc" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/lvgl" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/ui" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/Display/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-Display-2f-Src

clean-Application-2f-Display-2f-Src:
	-$(RM) ./Application/Display/Src/font12.cyclo ./Application/Display/Src/font12.d ./Application/Display/Src/font12.o ./Application/Display/Src/font12.su ./Application/Display/Src/font24.cyclo ./Application/Display/Src/font24.d ./Application/Display/Src/font24.o ./Application/Display/Src/font24.su ./Application/Display/Src/ili9341.cyclo ./Application/Display/Src/ili9341.d ./Application/Display/Src/ili9341.o ./Application/Display/Src/ili9341.su ./Application/Display/Src/lvgl_lcd.cyclo ./Application/Display/Src/lvgl_lcd.d ./Application/Display/Src/lvgl_lcd.o ./Application/Display/Src/lvgl_lcd.su ./Application/Display/Src/misko_touch.cyclo ./Application/Display/Src/misko_touch.d ./Application/Display/Src/misko_touch.o ./Application/Display/Src/misko_touch.su

.PHONY: clean-Application-2f-Display-2f-Src

