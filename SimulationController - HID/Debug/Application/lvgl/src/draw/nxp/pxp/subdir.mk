################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/lvgl/src/draw/nxp/pxp/lv_draw_buf_pxp.c \
../Application/lvgl/src/draw/nxp/pxp/lv_draw_pxp.c \
../Application/lvgl/src/draw/nxp/pxp/lv_draw_pxp_fill.c \
../Application/lvgl/src/draw/nxp/pxp/lv_draw_pxp_img.c \
../Application/lvgl/src/draw/nxp/pxp/lv_draw_pxp_layer.c \
../Application/lvgl/src/draw/nxp/pxp/lv_pxp_cfg.c \
../Application/lvgl/src/draw/nxp/pxp/lv_pxp_osa.c \
../Application/lvgl/src/draw/nxp/pxp/lv_pxp_utils.c 

OBJS += \
./Application/lvgl/src/draw/nxp/pxp/lv_draw_buf_pxp.o \
./Application/lvgl/src/draw/nxp/pxp/lv_draw_pxp.o \
./Application/lvgl/src/draw/nxp/pxp/lv_draw_pxp_fill.o \
./Application/lvgl/src/draw/nxp/pxp/lv_draw_pxp_img.o \
./Application/lvgl/src/draw/nxp/pxp/lv_draw_pxp_layer.o \
./Application/lvgl/src/draw/nxp/pxp/lv_pxp_cfg.o \
./Application/lvgl/src/draw/nxp/pxp/lv_pxp_osa.o \
./Application/lvgl/src/draw/nxp/pxp/lv_pxp_utils.o 

C_DEPS += \
./Application/lvgl/src/draw/nxp/pxp/lv_draw_buf_pxp.d \
./Application/lvgl/src/draw/nxp/pxp/lv_draw_pxp.d \
./Application/lvgl/src/draw/nxp/pxp/lv_draw_pxp_fill.d \
./Application/lvgl/src/draw/nxp/pxp/lv_draw_pxp_img.d \
./Application/lvgl/src/draw/nxp/pxp/lv_draw_pxp_layer.d \
./Application/lvgl/src/draw/nxp/pxp/lv_pxp_cfg.d \
./Application/lvgl/src/draw/nxp/pxp/lv_pxp_osa.d \
./Application/lvgl/src/draw/nxp/pxp/lv_pxp_utils.d 


# Each subdirectory must supply rules for building sources it contributes
Application/lvgl/src/draw/nxp/pxp/%.o Application/lvgl/src/draw/nxp/pxp/%.su Application/lvgl/src/draw/nxp/pxp/%.cyclo: ../Application/lvgl/src/draw/nxp/pxp/%.c Application/lvgl/src/draw/nxp/pxp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../USB_Device/App -I../USB_Device/Target -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/System/Inc" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/lvgl" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/ui" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/Display" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-lvgl-2f-src-2f-draw-2f-nxp-2f-pxp

clean-Application-2f-lvgl-2f-src-2f-draw-2f-nxp-2f-pxp:
	-$(RM) ./Application/lvgl/src/draw/nxp/pxp/lv_draw_buf_pxp.cyclo ./Application/lvgl/src/draw/nxp/pxp/lv_draw_buf_pxp.d ./Application/lvgl/src/draw/nxp/pxp/lv_draw_buf_pxp.o ./Application/lvgl/src/draw/nxp/pxp/lv_draw_buf_pxp.su ./Application/lvgl/src/draw/nxp/pxp/lv_draw_pxp.cyclo ./Application/lvgl/src/draw/nxp/pxp/lv_draw_pxp.d ./Application/lvgl/src/draw/nxp/pxp/lv_draw_pxp.o ./Application/lvgl/src/draw/nxp/pxp/lv_draw_pxp.su ./Application/lvgl/src/draw/nxp/pxp/lv_draw_pxp_fill.cyclo ./Application/lvgl/src/draw/nxp/pxp/lv_draw_pxp_fill.d ./Application/lvgl/src/draw/nxp/pxp/lv_draw_pxp_fill.o ./Application/lvgl/src/draw/nxp/pxp/lv_draw_pxp_fill.su ./Application/lvgl/src/draw/nxp/pxp/lv_draw_pxp_img.cyclo ./Application/lvgl/src/draw/nxp/pxp/lv_draw_pxp_img.d ./Application/lvgl/src/draw/nxp/pxp/lv_draw_pxp_img.o ./Application/lvgl/src/draw/nxp/pxp/lv_draw_pxp_img.su ./Application/lvgl/src/draw/nxp/pxp/lv_draw_pxp_layer.cyclo ./Application/lvgl/src/draw/nxp/pxp/lv_draw_pxp_layer.d ./Application/lvgl/src/draw/nxp/pxp/lv_draw_pxp_layer.o ./Application/lvgl/src/draw/nxp/pxp/lv_draw_pxp_layer.su ./Application/lvgl/src/draw/nxp/pxp/lv_pxp_cfg.cyclo ./Application/lvgl/src/draw/nxp/pxp/lv_pxp_cfg.d ./Application/lvgl/src/draw/nxp/pxp/lv_pxp_cfg.o ./Application/lvgl/src/draw/nxp/pxp/lv_pxp_cfg.su ./Application/lvgl/src/draw/nxp/pxp/lv_pxp_osa.cyclo ./Application/lvgl/src/draw/nxp/pxp/lv_pxp_osa.d ./Application/lvgl/src/draw/nxp/pxp/lv_pxp_osa.o ./Application/lvgl/src/draw/nxp/pxp/lv_pxp_osa.su ./Application/lvgl/src/draw/nxp/pxp/lv_pxp_utils.cyclo ./Application/lvgl/src/draw/nxp/pxp/lv_pxp_utils.d ./Application/lvgl/src/draw/nxp/pxp/lv_pxp_utils.o ./Application/lvgl/src/draw/nxp/pxp/lv_pxp_utils.su

.PHONY: clean-Application-2f-lvgl-2f-src-2f-draw-2f-nxp-2f-pxp

