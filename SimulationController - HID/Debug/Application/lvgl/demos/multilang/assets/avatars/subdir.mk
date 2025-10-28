################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_1.c \
../Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_10.c \
../Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_11.c \
../Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_12.c \
../Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_13.c \
../Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_14.c \
../Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_15.c \
../Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_16.c \
../Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_17.c \
../Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_18.c \
../Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_19.c \
../Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_2.c \
../Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_22.c \
../Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_25.c \
../Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_3.c \
../Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_4.c \
../Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_5.c \
../Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_6.c \
../Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_7.c \
../Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_8.c \
../Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_9.c 

OBJS += \
./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_1.o \
./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_10.o \
./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_11.o \
./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_12.o \
./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_13.o \
./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_14.o \
./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_15.o \
./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_16.o \
./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_17.o \
./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_18.o \
./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_19.o \
./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_2.o \
./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_22.o \
./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_25.o \
./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_3.o \
./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_4.o \
./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_5.o \
./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_6.o \
./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_7.o \
./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_8.o \
./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_9.o 

C_DEPS += \
./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_1.d \
./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_10.d \
./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_11.d \
./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_12.d \
./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_13.d \
./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_14.d \
./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_15.d \
./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_16.d \
./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_17.d \
./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_18.d \
./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_19.d \
./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_2.d \
./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_22.d \
./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_25.d \
./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_3.d \
./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_4.d \
./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_5.d \
./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_6.d \
./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_7.d \
./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_8.d \
./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_9.d 


# Each subdirectory must supply rules for building sources it contributes
Application/lvgl/demos/multilang/assets/avatars/%.o Application/lvgl/demos/multilang/assets/avatars/%.su Application/lvgl/demos/multilang/assets/avatars/%.cyclo: ../Application/lvgl/demos/multilang/assets/avatars/%.c Application/lvgl/demos/multilang/assets/avatars/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../USB_Device/App -I../USB_Device/Target -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/System/Inc" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/lvgl" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/ui" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/Display" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-lvgl-2f-demos-2f-multilang-2f-assets-2f-avatars

clean-Application-2f-lvgl-2f-demos-2f-multilang-2f-assets-2f-avatars:
	-$(RM) ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_1.cyclo ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_1.d ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_1.o ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_1.su ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_10.cyclo ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_10.d ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_10.o ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_10.su ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_11.cyclo ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_11.d ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_11.o ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_11.su ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_12.cyclo ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_12.d ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_12.o ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_12.su ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_13.cyclo ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_13.d ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_13.o ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_13.su ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_14.cyclo ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_14.d ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_14.o ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_14.su ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_15.cyclo ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_15.d ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_15.o ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_15.su ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_16.cyclo ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_16.d ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_16.o ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_16.su ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_17.cyclo ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_17.d ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_17.o ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_17.su ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_18.cyclo ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_18.d ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_18.o ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_18.su ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_19.cyclo ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_19.d ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_19.o ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_19.su ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_2.cyclo ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_2.d ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_2.o ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_2.su ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_22.cyclo ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_22.d ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_22.o ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_22.su ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_25.cyclo ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_25.d ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_25.o ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_25.su ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_3.cyclo ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_3.d ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_3.o ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_3.su ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_4.cyclo ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_4.d ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_4.o ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_4.su ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_5.cyclo ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_5.d ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_5.o ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_5.su ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_6.cyclo ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_6.d ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_6.o ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_6.su ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_7.cyclo ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_7.d ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_7.o ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_7.su ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_8.cyclo
	-$(RM) ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_8.d ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_8.o ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_8.su ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_9.cyclo ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_9.d ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_9.o ./Application/lvgl/demos/multilang/assets/avatars/img_multilang_avatar_9.su

.PHONY: clean-Application-2f-lvgl-2f-demos-2f-multilang-2f-assets-2f-avatars

