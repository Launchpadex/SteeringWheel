################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/lvgl/src/libs/freetype/lv_freetype.c \
../Application/lvgl/src/libs/freetype/lv_freetype_glyph.c \
../Application/lvgl/src/libs/freetype/lv_freetype_image.c \
../Application/lvgl/src/libs/freetype/lv_freetype_outline.c \
../Application/lvgl/src/libs/freetype/lv_ftsystem.c 

OBJS += \
./Application/lvgl/src/libs/freetype/lv_freetype.o \
./Application/lvgl/src/libs/freetype/lv_freetype_glyph.o \
./Application/lvgl/src/libs/freetype/lv_freetype_image.o \
./Application/lvgl/src/libs/freetype/lv_freetype_outline.o \
./Application/lvgl/src/libs/freetype/lv_ftsystem.o 

C_DEPS += \
./Application/lvgl/src/libs/freetype/lv_freetype.d \
./Application/lvgl/src/libs/freetype/lv_freetype_glyph.d \
./Application/lvgl/src/libs/freetype/lv_freetype_image.d \
./Application/lvgl/src/libs/freetype/lv_freetype_outline.d \
./Application/lvgl/src/libs/freetype/lv_ftsystem.d 


# Each subdirectory must supply rules for building sources it contributes
Application/lvgl/src/libs/freetype/%.o Application/lvgl/src/libs/freetype/%.su Application/lvgl/src/libs/freetype/%.cyclo: ../Application/lvgl/src/libs/freetype/%.c Application/lvgl/src/libs/freetype/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../USB_Device/App -I../USB_Device/Target -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/System/Inc" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/lvgl" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/ui" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/Display" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-lvgl-2f-src-2f-libs-2f-freetype

clean-Application-2f-lvgl-2f-src-2f-libs-2f-freetype:
	-$(RM) ./Application/lvgl/src/libs/freetype/lv_freetype.cyclo ./Application/lvgl/src/libs/freetype/lv_freetype.d ./Application/lvgl/src/libs/freetype/lv_freetype.o ./Application/lvgl/src/libs/freetype/lv_freetype.su ./Application/lvgl/src/libs/freetype/lv_freetype_glyph.cyclo ./Application/lvgl/src/libs/freetype/lv_freetype_glyph.d ./Application/lvgl/src/libs/freetype/lv_freetype_glyph.o ./Application/lvgl/src/libs/freetype/lv_freetype_glyph.su ./Application/lvgl/src/libs/freetype/lv_freetype_image.cyclo ./Application/lvgl/src/libs/freetype/lv_freetype_image.d ./Application/lvgl/src/libs/freetype/lv_freetype_image.o ./Application/lvgl/src/libs/freetype/lv_freetype_image.su ./Application/lvgl/src/libs/freetype/lv_freetype_outline.cyclo ./Application/lvgl/src/libs/freetype/lv_freetype_outline.d ./Application/lvgl/src/libs/freetype/lv_freetype_outline.o ./Application/lvgl/src/libs/freetype/lv_freetype_outline.su ./Application/lvgl/src/libs/freetype/lv_ftsystem.cyclo ./Application/lvgl/src/libs/freetype/lv_ftsystem.d ./Application/lvgl/src/libs/freetype/lv_ftsystem.o ./Application/lvgl/src/libs/freetype/lv_ftsystem.su

.PHONY: clean-Application-2f-lvgl-2f-src-2f-libs-2f-freetype

