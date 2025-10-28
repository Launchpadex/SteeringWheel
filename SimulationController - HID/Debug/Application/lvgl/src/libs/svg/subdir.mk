################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/lvgl/src/libs/svg/lv_svg.c \
../Application/lvgl/src/libs/svg/lv_svg_parser.c \
../Application/lvgl/src/libs/svg/lv_svg_render.c \
../Application/lvgl/src/libs/svg/lv_svg_token.c 

OBJS += \
./Application/lvgl/src/libs/svg/lv_svg.o \
./Application/lvgl/src/libs/svg/lv_svg_parser.o \
./Application/lvgl/src/libs/svg/lv_svg_render.o \
./Application/lvgl/src/libs/svg/lv_svg_token.o 

C_DEPS += \
./Application/lvgl/src/libs/svg/lv_svg.d \
./Application/lvgl/src/libs/svg/lv_svg_parser.d \
./Application/lvgl/src/libs/svg/lv_svg_render.d \
./Application/lvgl/src/libs/svg/lv_svg_token.d 


# Each subdirectory must supply rules for building sources it contributes
Application/lvgl/src/libs/svg/%.o Application/lvgl/src/libs/svg/%.su Application/lvgl/src/libs/svg/%.cyclo: ../Application/lvgl/src/libs/svg/%.c Application/lvgl/src/libs/svg/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../USB_Device/App -I../USB_Device/Target -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/System/Inc" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/lvgl" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/ui" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/Display" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-lvgl-2f-src-2f-libs-2f-svg

clean-Application-2f-lvgl-2f-src-2f-libs-2f-svg:
	-$(RM) ./Application/lvgl/src/libs/svg/lv_svg.cyclo ./Application/lvgl/src/libs/svg/lv_svg.d ./Application/lvgl/src/libs/svg/lv_svg.o ./Application/lvgl/src/libs/svg/lv_svg.su ./Application/lvgl/src/libs/svg/lv_svg_parser.cyclo ./Application/lvgl/src/libs/svg/lv_svg_parser.d ./Application/lvgl/src/libs/svg/lv_svg_parser.o ./Application/lvgl/src/libs/svg/lv_svg_parser.su ./Application/lvgl/src/libs/svg/lv_svg_render.cyclo ./Application/lvgl/src/libs/svg/lv_svg_render.d ./Application/lvgl/src/libs/svg/lv_svg_render.o ./Application/lvgl/src/libs/svg/lv_svg_render.su ./Application/lvgl/src/libs/svg/lv_svg_token.cyclo ./Application/lvgl/src/libs/svg/lv_svg_token.d ./Application/lvgl/src/libs/svg/lv_svg_token.o ./Application/lvgl/src/libs/svg/lv_svg_token.su

.PHONY: clean-Application-2f-lvgl-2f-src-2f-libs-2f-svg

