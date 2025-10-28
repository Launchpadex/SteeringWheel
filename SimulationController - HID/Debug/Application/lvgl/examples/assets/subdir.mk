################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/lvgl/examples/assets/animimg001.c \
../Application/lvgl/examples/assets/animimg002.c \
../Application/lvgl/examples/assets/animimg003.c \
../Application/lvgl/examples/assets/img_caret_down.c \
../Application/lvgl/examples/assets/img_cogwheel_argb.c \
../Application/lvgl/examples/assets/img_cogwheel_indexed16.c \
../Application/lvgl/examples/assets/img_cogwheel_rgb.c \
../Application/lvgl/examples/assets/img_hand.c \
../Application/lvgl/examples/assets/img_skew_strip.c \
../Application/lvgl/examples/assets/img_star.c \
../Application/lvgl/examples/assets/imgbtn_left.c \
../Application/lvgl/examples/assets/imgbtn_mid.c \
../Application/lvgl/examples/assets/imgbtn_right.c 

OBJS += \
./Application/lvgl/examples/assets/animimg001.o \
./Application/lvgl/examples/assets/animimg002.o \
./Application/lvgl/examples/assets/animimg003.o \
./Application/lvgl/examples/assets/img_caret_down.o \
./Application/lvgl/examples/assets/img_cogwheel_argb.o \
./Application/lvgl/examples/assets/img_cogwheel_indexed16.o \
./Application/lvgl/examples/assets/img_cogwheel_rgb.o \
./Application/lvgl/examples/assets/img_hand.o \
./Application/lvgl/examples/assets/img_skew_strip.o \
./Application/lvgl/examples/assets/img_star.o \
./Application/lvgl/examples/assets/imgbtn_left.o \
./Application/lvgl/examples/assets/imgbtn_mid.o \
./Application/lvgl/examples/assets/imgbtn_right.o 

C_DEPS += \
./Application/lvgl/examples/assets/animimg001.d \
./Application/lvgl/examples/assets/animimg002.d \
./Application/lvgl/examples/assets/animimg003.d \
./Application/lvgl/examples/assets/img_caret_down.d \
./Application/lvgl/examples/assets/img_cogwheel_argb.d \
./Application/lvgl/examples/assets/img_cogwheel_indexed16.d \
./Application/lvgl/examples/assets/img_cogwheel_rgb.d \
./Application/lvgl/examples/assets/img_hand.d \
./Application/lvgl/examples/assets/img_skew_strip.d \
./Application/lvgl/examples/assets/img_star.d \
./Application/lvgl/examples/assets/imgbtn_left.d \
./Application/lvgl/examples/assets/imgbtn_mid.d \
./Application/lvgl/examples/assets/imgbtn_right.d 


# Each subdirectory must supply rules for building sources it contributes
Application/lvgl/examples/assets/%.o Application/lvgl/examples/assets/%.su Application/lvgl/examples/assets/%.cyclo: ../Application/lvgl/examples/assets/%.c Application/lvgl/examples/assets/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../USB_Device/App -I../USB_Device/Target -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/System/Inc" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/lvgl" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/ui" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/Display" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-lvgl-2f-examples-2f-assets

clean-Application-2f-lvgl-2f-examples-2f-assets:
	-$(RM) ./Application/lvgl/examples/assets/animimg001.cyclo ./Application/lvgl/examples/assets/animimg001.d ./Application/lvgl/examples/assets/animimg001.o ./Application/lvgl/examples/assets/animimg001.su ./Application/lvgl/examples/assets/animimg002.cyclo ./Application/lvgl/examples/assets/animimg002.d ./Application/lvgl/examples/assets/animimg002.o ./Application/lvgl/examples/assets/animimg002.su ./Application/lvgl/examples/assets/animimg003.cyclo ./Application/lvgl/examples/assets/animimg003.d ./Application/lvgl/examples/assets/animimg003.o ./Application/lvgl/examples/assets/animimg003.su ./Application/lvgl/examples/assets/img_caret_down.cyclo ./Application/lvgl/examples/assets/img_caret_down.d ./Application/lvgl/examples/assets/img_caret_down.o ./Application/lvgl/examples/assets/img_caret_down.su ./Application/lvgl/examples/assets/img_cogwheel_argb.cyclo ./Application/lvgl/examples/assets/img_cogwheel_argb.d ./Application/lvgl/examples/assets/img_cogwheel_argb.o ./Application/lvgl/examples/assets/img_cogwheel_argb.su ./Application/lvgl/examples/assets/img_cogwheel_indexed16.cyclo ./Application/lvgl/examples/assets/img_cogwheel_indexed16.d ./Application/lvgl/examples/assets/img_cogwheel_indexed16.o ./Application/lvgl/examples/assets/img_cogwheel_indexed16.su ./Application/lvgl/examples/assets/img_cogwheel_rgb.cyclo ./Application/lvgl/examples/assets/img_cogwheel_rgb.d ./Application/lvgl/examples/assets/img_cogwheel_rgb.o ./Application/lvgl/examples/assets/img_cogwheel_rgb.su ./Application/lvgl/examples/assets/img_hand.cyclo ./Application/lvgl/examples/assets/img_hand.d ./Application/lvgl/examples/assets/img_hand.o ./Application/lvgl/examples/assets/img_hand.su ./Application/lvgl/examples/assets/img_skew_strip.cyclo ./Application/lvgl/examples/assets/img_skew_strip.d ./Application/lvgl/examples/assets/img_skew_strip.o ./Application/lvgl/examples/assets/img_skew_strip.su ./Application/lvgl/examples/assets/img_star.cyclo ./Application/lvgl/examples/assets/img_star.d ./Application/lvgl/examples/assets/img_star.o ./Application/lvgl/examples/assets/img_star.su ./Application/lvgl/examples/assets/imgbtn_left.cyclo ./Application/lvgl/examples/assets/imgbtn_left.d ./Application/lvgl/examples/assets/imgbtn_left.o ./Application/lvgl/examples/assets/imgbtn_left.su ./Application/lvgl/examples/assets/imgbtn_mid.cyclo ./Application/lvgl/examples/assets/imgbtn_mid.d ./Application/lvgl/examples/assets/imgbtn_mid.o ./Application/lvgl/examples/assets/imgbtn_mid.su ./Application/lvgl/examples/assets/imgbtn_right.cyclo ./Application/lvgl/examples/assets/imgbtn_right.d ./Application/lvgl/examples/assets/imgbtn_right.o ./Application/lvgl/examples/assets/imgbtn_right.su

.PHONY: clean-Application-2f-lvgl-2f-examples-2f-assets

