################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/lvgl/src/libs/fsdrv/lv_fs_cbfs.c \
../Application/lvgl/src/libs/fsdrv/lv_fs_fatfs.c \
../Application/lvgl/src/libs/fsdrv/lv_fs_littlefs.c \
../Application/lvgl/src/libs/fsdrv/lv_fs_memfs.c \
../Application/lvgl/src/libs/fsdrv/lv_fs_posix.c \
../Application/lvgl/src/libs/fsdrv/lv_fs_stdio.c \
../Application/lvgl/src/libs/fsdrv/lv_fs_win32.c 

OBJS += \
./Application/lvgl/src/libs/fsdrv/lv_fs_cbfs.o \
./Application/lvgl/src/libs/fsdrv/lv_fs_fatfs.o \
./Application/lvgl/src/libs/fsdrv/lv_fs_littlefs.o \
./Application/lvgl/src/libs/fsdrv/lv_fs_memfs.o \
./Application/lvgl/src/libs/fsdrv/lv_fs_posix.o \
./Application/lvgl/src/libs/fsdrv/lv_fs_stdio.o \
./Application/lvgl/src/libs/fsdrv/lv_fs_win32.o 

C_DEPS += \
./Application/lvgl/src/libs/fsdrv/lv_fs_cbfs.d \
./Application/lvgl/src/libs/fsdrv/lv_fs_fatfs.d \
./Application/lvgl/src/libs/fsdrv/lv_fs_littlefs.d \
./Application/lvgl/src/libs/fsdrv/lv_fs_memfs.d \
./Application/lvgl/src/libs/fsdrv/lv_fs_posix.d \
./Application/lvgl/src/libs/fsdrv/lv_fs_stdio.d \
./Application/lvgl/src/libs/fsdrv/lv_fs_win32.d 


# Each subdirectory must supply rules for building sources it contributes
Application/lvgl/src/libs/fsdrv/%.o Application/lvgl/src/libs/fsdrv/%.su Application/lvgl/src/libs/fsdrv/%.cyclo: ../Application/lvgl/src/libs/fsdrv/%.c Application/lvgl/src/libs/fsdrv/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../USB_Device/App -I../USB_Device/Target -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/System/Inc" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/lvgl" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/ui" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/Display" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-lvgl-2f-src-2f-libs-2f-fsdrv

clean-Application-2f-lvgl-2f-src-2f-libs-2f-fsdrv:
	-$(RM) ./Application/lvgl/src/libs/fsdrv/lv_fs_cbfs.cyclo ./Application/lvgl/src/libs/fsdrv/lv_fs_cbfs.d ./Application/lvgl/src/libs/fsdrv/lv_fs_cbfs.o ./Application/lvgl/src/libs/fsdrv/lv_fs_cbfs.su ./Application/lvgl/src/libs/fsdrv/lv_fs_fatfs.cyclo ./Application/lvgl/src/libs/fsdrv/lv_fs_fatfs.d ./Application/lvgl/src/libs/fsdrv/lv_fs_fatfs.o ./Application/lvgl/src/libs/fsdrv/lv_fs_fatfs.su ./Application/lvgl/src/libs/fsdrv/lv_fs_littlefs.cyclo ./Application/lvgl/src/libs/fsdrv/lv_fs_littlefs.d ./Application/lvgl/src/libs/fsdrv/lv_fs_littlefs.o ./Application/lvgl/src/libs/fsdrv/lv_fs_littlefs.su ./Application/lvgl/src/libs/fsdrv/lv_fs_memfs.cyclo ./Application/lvgl/src/libs/fsdrv/lv_fs_memfs.d ./Application/lvgl/src/libs/fsdrv/lv_fs_memfs.o ./Application/lvgl/src/libs/fsdrv/lv_fs_memfs.su ./Application/lvgl/src/libs/fsdrv/lv_fs_posix.cyclo ./Application/lvgl/src/libs/fsdrv/lv_fs_posix.d ./Application/lvgl/src/libs/fsdrv/lv_fs_posix.o ./Application/lvgl/src/libs/fsdrv/lv_fs_posix.su ./Application/lvgl/src/libs/fsdrv/lv_fs_stdio.cyclo ./Application/lvgl/src/libs/fsdrv/lv_fs_stdio.d ./Application/lvgl/src/libs/fsdrv/lv_fs_stdio.o ./Application/lvgl/src/libs/fsdrv/lv_fs_stdio.su ./Application/lvgl/src/libs/fsdrv/lv_fs_win32.cyclo ./Application/lvgl/src/libs/fsdrv/lv_fs_win32.d ./Application/lvgl/src/libs/fsdrv/lv_fs_win32.o ./Application/lvgl/src/libs/fsdrv/lv_fs_win32.su

.PHONY: clean-Application-2f-lvgl-2f-src-2f-libs-2f-fsdrv

