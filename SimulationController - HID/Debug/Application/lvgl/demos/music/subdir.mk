################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/lvgl/demos/music/lv_demo_music.c \
../Application/lvgl/demos/music/lv_demo_music_list.c \
../Application/lvgl/demos/music/lv_demo_music_main.c 

OBJS += \
./Application/lvgl/demos/music/lv_demo_music.o \
./Application/lvgl/demos/music/lv_demo_music_list.o \
./Application/lvgl/demos/music/lv_demo_music_main.o 

C_DEPS += \
./Application/lvgl/demos/music/lv_demo_music.d \
./Application/lvgl/demos/music/lv_demo_music_list.d \
./Application/lvgl/demos/music/lv_demo_music_main.d 


# Each subdirectory must supply rules for building sources it contributes
Application/lvgl/demos/music/%.o Application/lvgl/demos/music/%.su Application/lvgl/demos/music/%.cyclo: ../Application/lvgl/demos/music/%.c Application/lvgl/demos/music/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../USB_Device/App -I../USB_Device/Target -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/System/Inc" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/lvgl" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/ui" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/Display" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-lvgl-2f-demos-2f-music

clean-Application-2f-lvgl-2f-demos-2f-music:
	-$(RM) ./Application/lvgl/demos/music/lv_demo_music.cyclo ./Application/lvgl/demos/music/lv_demo_music.d ./Application/lvgl/demos/music/lv_demo_music.o ./Application/lvgl/demos/music/lv_demo_music.su ./Application/lvgl/demos/music/lv_demo_music_list.cyclo ./Application/lvgl/demos/music/lv_demo_music_list.d ./Application/lvgl/demos/music/lv_demo_music_list.o ./Application/lvgl/demos/music/lv_demo_music_list.su ./Application/lvgl/demos/music/lv_demo_music_main.cyclo ./Application/lvgl/demos/music/lv_demo_music_main.d ./Application/lvgl/demos/music/lv_demo_music_main.o ./Application/lvgl/demos/music/lv_demo_music_main.su

.PHONY: clean-Application-2f-lvgl-2f-demos-2f-music

