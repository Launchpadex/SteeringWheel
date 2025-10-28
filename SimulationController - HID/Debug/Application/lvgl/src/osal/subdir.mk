################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/lvgl/src/osal/lv_cmsis_rtos2.c \
../Application/lvgl/src/osal/lv_freertos.c \
../Application/lvgl/src/osal/lv_mqx.c \
../Application/lvgl/src/osal/lv_os.c \
../Application/lvgl/src/osal/lv_pthread.c \
../Application/lvgl/src/osal/lv_rtthread.c \
../Application/lvgl/src/osal/lv_sdl2.c \
../Application/lvgl/src/osal/lv_windows.c 

OBJS += \
./Application/lvgl/src/osal/lv_cmsis_rtos2.o \
./Application/lvgl/src/osal/lv_freertos.o \
./Application/lvgl/src/osal/lv_mqx.o \
./Application/lvgl/src/osal/lv_os.o \
./Application/lvgl/src/osal/lv_pthread.o \
./Application/lvgl/src/osal/lv_rtthread.o \
./Application/lvgl/src/osal/lv_sdl2.o \
./Application/lvgl/src/osal/lv_windows.o 

C_DEPS += \
./Application/lvgl/src/osal/lv_cmsis_rtos2.d \
./Application/lvgl/src/osal/lv_freertos.d \
./Application/lvgl/src/osal/lv_mqx.d \
./Application/lvgl/src/osal/lv_os.d \
./Application/lvgl/src/osal/lv_pthread.d \
./Application/lvgl/src/osal/lv_rtthread.d \
./Application/lvgl/src/osal/lv_sdl2.d \
./Application/lvgl/src/osal/lv_windows.d 


# Each subdirectory must supply rules for building sources it contributes
Application/lvgl/src/osal/%.o Application/lvgl/src/osal/%.su Application/lvgl/src/osal/%.cyclo: ../Application/lvgl/src/osal/%.c Application/lvgl/src/osal/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../USB_Device/App -I../USB_Device/Target -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/System/Inc" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/lvgl" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/ui" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/Display" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-lvgl-2f-src-2f-osal

clean-Application-2f-lvgl-2f-src-2f-osal:
	-$(RM) ./Application/lvgl/src/osal/lv_cmsis_rtos2.cyclo ./Application/lvgl/src/osal/lv_cmsis_rtos2.d ./Application/lvgl/src/osal/lv_cmsis_rtos2.o ./Application/lvgl/src/osal/lv_cmsis_rtos2.su ./Application/lvgl/src/osal/lv_freertos.cyclo ./Application/lvgl/src/osal/lv_freertos.d ./Application/lvgl/src/osal/lv_freertos.o ./Application/lvgl/src/osal/lv_freertos.su ./Application/lvgl/src/osal/lv_mqx.cyclo ./Application/lvgl/src/osal/lv_mqx.d ./Application/lvgl/src/osal/lv_mqx.o ./Application/lvgl/src/osal/lv_mqx.su ./Application/lvgl/src/osal/lv_os.cyclo ./Application/lvgl/src/osal/lv_os.d ./Application/lvgl/src/osal/lv_os.o ./Application/lvgl/src/osal/lv_os.su ./Application/lvgl/src/osal/lv_pthread.cyclo ./Application/lvgl/src/osal/lv_pthread.d ./Application/lvgl/src/osal/lv_pthread.o ./Application/lvgl/src/osal/lv_pthread.su ./Application/lvgl/src/osal/lv_rtthread.cyclo ./Application/lvgl/src/osal/lv_rtthread.d ./Application/lvgl/src/osal/lv_rtthread.o ./Application/lvgl/src/osal/lv_rtthread.su ./Application/lvgl/src/osal/lv_sdl2.cyclo ./Application/lvgl/src/osal/lv_sdl2.d ./Application/lvgl/src/osal/lv_sdl2.o ./Application/lvgl/src/osal/lv_sdl2.su ./Application/lvgl/src/osal/lv_windows.cyclo ./Application/lvgl/src/osal/lv_windows.d ./Application/lvgl/src/osal/lv_windows.o ./Application/lvgl/src/osal/lv_windows.su

.PHONY: clean-Application-2f-lvgl-2f-src-2f-osal

