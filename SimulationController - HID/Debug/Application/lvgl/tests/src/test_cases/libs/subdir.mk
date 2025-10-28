################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/lvgl/tests/src/test_cases/libs/test_barcode.c \
../Application/lvgl/tests/src/test_cases/libs/test_bin_decoder.c \
../Application/lvgl/tests/src/test_cases/libs/test_bmp.c \
../Application/lvgl/tests/src/test_cases/libs/test_font_stress.c \
../Application/lvgl/tests/src/test_cases/libs/test_freetype.c \
../Application/lvgl/tests/src/test_cases/libs/test_libjpeg_turbo.c \
../Application/lvgl/tests/src/test_cases/libs/test_libpng.c \
../Application/lvgl/tests/src/test_cases/libs/test_lodepng.c \
../Application/lvgl/tests/src/test_cases/libs/test_memmove.c \
../Application/lvgl/tests/src/test_cases/libs/test_qrcode.c \
../Application/lvgl/tests/src/test_cases/libs/test_tiny_ttf.c \
../Application/lvgl/tests/src/test_cases/libs/test_tjpgd.c 

OBJS += \
./Application/lvgl/tests/src/test_cases/libs/test_barcode.o \
./Application/lvgl/tests/src/test_cases/libs/test_bin_decoder.o \
./Application/lvgl/tests/src/test_cases/libs/test_bmp.o \
./Application/lvgl/tests/src/test_cases/libs/test_font_stress.o \
./Application/lvgl/tests/src/test_cases/libs/test_freetype.o \
./Application/lvgl/tests/src/test_cases/libs/test_libjpeg_turbo.o \
./Application/lvgl/tests/src/test_cases/libs/test_libpng.o \
./Application/lvgl/tests/src/test_cases/libs/test_lodepng.o \
./Application/lvgl/tests/src/test_cases/libs/test_memmove.o \
./Application/lvgl/tests/src/test_cases/libs/test_qrcode.o \
./Application/lvgl/tests/src/test_cases/libs/test_tiny_ttf.o \
./Application/lvgl/tests/src/test_cases/libs/test_tjpgd.o 

C_DEPS += \
./Application/lvgl/tests/src/test_cases/libs/test_barcode.d \
./Application/lvgl/tests/src/test_cases/libs/test_bin_decoder.d \
./Application/lvgl/tests/src/test_cases/libs/test_bmp.d \
./Application/lvgl/tests/src/test_cases/libs/test_font_stress.d \
./Application/lvgl/tests/src/test_cases/libs/test_freetype.d \
./Application/lvgl/tests/src/test_cases/libs/test_libjpeg_turbo.d \
./Application/lvgl/tests/src/test_cases/libs/test_libpng.d \
./Application/lvgl/tests/src/test_cases/libs/test_lodepng.d \
./Application/lvgl/tests/src/test_cases/libs/test_memmove.d \
./Application/lvgl/tests/src/test_cases/libs/test_qrcode.d \
./Application/lvgl/tests/src/test_cases/libs/test_tiny_ttf.d \
./Application/lvgl/tests/src/test_cases/libs/test_tjpgd.d 


# Each subdirectory must supply rules for building sources it contributes
Application/lvgl/tests/src/test_cases/libs/%.o Application/lvgl/tests/src/test_cases/libs/%.su Application/lvgl/tests/src/test_cases/libs/%.cyclo: ../Application/lvgl/tests/src/test_cases/libs/%.c Application/lvgl/tests/src/test_cases/libs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../USB_Device/App -I../USB_Device/Target -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/System/Inc" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/lvgl" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/ui" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/Display" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-lvgl-2f-tests-2f-src-2f-test_cases-2f-libs

clean-Application-2f-lvgl-2f-tests-2f-src-2f-test_cases-2f-libs:
	-$(RM) ./Application/lvgl/tests/src/test_cases/libs/test_barcode.cyclo ./Application/lvgl/tests/src/test_cases/libs/test_barcode.d ./Application/lvgl/tests/src/test_cases/libs/test_barcode.o ./Application/lvgl/tests/src/test_cases/libs/test_barcode.su ./Application/lvgl/tests/src/test_cases/libs/test_bin_decoder.cyclo ./Application/lvgl/tests/src/test_cases/libs/test_bin_decoder.d ./Application/lvgl/tests/src/test_cases/libs/test_bin_decoder.o ./Application/lvgl/tests/src/test_cases/libs/test_bin_decoder.su ./Application/lvgl/tests/src/test_cases/libs/test_bmp.cyclo ./Application/lvgl/tests/src/test_cases/libs/test_bmp.d ./Application/lvgl/tests/src/test_cases/libs/test_bmp.o ./Application/lvgl/tests/src/test_cases/libs/test_bmp.su ./Application/lvgl/tests/src/test_cases/libs/test_font_stress.cyclo ./Application/lvgl/tests/src/test_cases/libs/test_font_stress.d ./Application/lvgl/tests/src/test_cases/libs/test_font_stress.o ./Application/lvgl/tests/src/test_cases/libs/test_font_stress.su ./Application/lvgl/tests/src/test_cases/libs/test_freetype.cyclo ./Application/lvgl/tests/src/test_cases/libs/test_freetype.d ./Application/lvgl/tests/src/test_cases/libs/test_freetype.o ./Application/lvgl/tests/src/test_cases/libs/test_freetype.su ./Application/lvgl/tests/src/test_cases/libs/test_libjpeg_turbo.cyclo ./Application/lvgl/tests/src/test_cases/libs/test_libjpeg_turbo.d ./Application/lvgl/tests/src/test_cases/libs/test_libjpeg_turbo.o ./Application/lvgl/tests/src/test_cases/libs/test_libjpeg_turbo.su ./Application/lvgl/tests/src/test_cases/libs/test_libpng.cyclo ./Application/lvgl/tests/src/test_cases/libs/test_libpng.d ./Application/lvgl/tests/src/test_cases/libs/test_libpng.o ./Application/lvgl/tests/src/test_cases/libs/test_libpng.su ./Application/lvgl/tests/src/test_cases/libs/test_lodepng.cyclo ./Application/lvgl/tests/src/test_cases/libs/test_lodepng.d ./Application/lvgl/tests/src/test_cases/libs/test_lodepng.o ./Application/lvgl/tests/src/test_cases/libs/test_lodepng.su ./Application/lvgl/tests/src/test_cases/libs/test_memmove.cyclo ./Application/lvgl/tests/src/test_cases/libs/test_memmove.d ./Application/lvgl/tests/src/test_cases/libs/test_memmove.o ./Application/lvgl/tests/src/test_cases/libs/test_memmove.su ./Application/lvgl/tests/src/test_cases/libs/test_qrcode.cyclo ./Application/lvgl/tests/src/test_cases/libs/test_qrcode.d ./Application/lvgl/tests/src/test_cases/libs/test_qrcode.o ./Application/lvgl/tests/src/test_cases/libs/test_qrcode.su ./Application/lvgl/tests/src/test_cases/libs/test_tiny_ttf.cyclo ./Application/lvgl/tests/src/test_cases/libs/test_tiny_ttf.d ./Application/lvgl/tests/src/test_cases/libs/test_tiny_ttf.o ./Application/lvgl/tests/src/test_cases/libs/test_tiny_ttf.su ./Application/lvgl/tests/src/test_cases/libs/test_tjpgd.cyclo ./Application/lvgl/tests/src/test_cases/libs/test_tjpgd.d ./Application/lvgl/tests/src/test_cases/libs/test_tjpgd.o ./Application/lvgl/tests/src/test_cases/libs/test_tjpgd.su

.PHONY: clean-Application-2f-lvgl-2f-tests-2f-src-2f-test_cases-2f-libs

