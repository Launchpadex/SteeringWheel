################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/Display/font12.c \
../Application/Display/font24.c \
../Application/Display/ili9341.c \
../Application/Display/lvgl_lcd.c \
../Application/Display/misko_touch.c 

OBJS += \
./Application/Display/font12.o \
./Application/Display/font24.o \
./Application/Display/ili9341.o \
./Application/Display/lvgl_lcd.o \
./Application/Display/misko_touch.o 

C_DEPS += \
./Application/Display/font12.d \
./Application/Display/font24.d \
./Application/Display/ili9341.d \
./Application/Display/lvgl_lcd.d \
./Application/Display/misko_touch.d 


# Each subdirectory must supply rules for building sources it contributes
Application/Display/%.o Application/Display/%.su Application/Display/%.cyclo: ../Application/Display/%.c Application/Display/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../USB_Device/App -I../USB_Device/Target -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/System/Inc" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/lvgl" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/ui" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/Display" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-Display

clean-Application-2f-Display:
	-$(RM) ./Application/Display/font12.cyclo ./Application/Display/font12.d ./Application/Display/font12.o ./Application/Display/font12.su ./Application/Display/font24.cyclo ./Application/Display/font24.d ./Application/Display/font24.o ./Application/Display/font24.su ./Application/Display/ili9341.cyclo ./Application/Display/ili9341.d ./Application/Display/ili9341.o ./Application/Display/ili9341.su ./Application/Display/lvgl_lcd.cyclo ./Application/Display/lvgl_lcd.d ./Application/Display/lvgl_lcd.o ./Application/Display/lvgl_lcd.su ./Application/Display/misko_touch.cyclo ./Application/Display/misko_touch.d ./Application/Display/misko_touch.o ./Application/Display/misko_touch.su

.PHONY: clean-Application-2f-Display

