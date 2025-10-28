################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/lvgl/src/drivers/glfw/lv_glfw_window.c \
../Application/lvgl/src/drivers/glfw/lv_opengles_debug.c \
../Application/lvgl/src/drivers/glfw/lv_opengles_driver.c \
../Application/lvgl/src/drivers/glfw/lv_opengles_texture.c 

OBJS += \
./Application/lvgl/src/drivers/glfw/lv_glfw_window.o \
./Application/lvgl/src/drivers/glfw/lv_opengles_debug.o \
./Application/lvgl/src/drivers/glfw/lv_opengles_driver.o \
./Application/lvgl/src/drivers/glfw/lv_opengles_texture.o 

C_DEPS += \
./Application/lvgl/src/drivers/glfw/lv_glfw_window.d \
./Application/lvgl/src/drivers/glfw/lv_opengles_debug.d \
./Application/lvgl/src/drivers/glfw/lv_opengles_driver.d \
./Application/lvgl/src/drivers/glfw/lv_opengles_texture.d 


# Each subdirectory must supply rules for building sources it contributes
Application/lvgl/src/drivers/glfw/%.o Application/lvgl/src/drivers/glfw/%.su Application/lvgl/src/drivers/glfw/%.cyclo: ../Application/lvgl/src/drivers/glfw/%.c Application/lvgl/src/drivers/glfw/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../USB_Device/App -I../USB_Device/Target -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/System/Inc" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/lvgl" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/ui" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/Display" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-lvgl-2f-src-2f-drivers-2f-glfw

clean-Application-2f-lvgl-2f-src-2f-drivers-2f-glfw:
	-$(RM) ./Application/lvgl/src/drivers/glfw/lv_glfw_window.cyclo ./Application/lvgl/src/drivers/glfw/lv_glfw_window.d ./Application/lvgl/src/drivers/glfw/lv_glfw_window.o ./Application/lvgl/src/drivers/glfw/lv_glfw_window.su ./Application/lvgl/src/drivers/glfw/lv_opengles_debug.cyclo ./Application/lvgl/src/drivers/glfw/lv_opengles_debug.d ./Application/lvgl/src/drivers/glfw/lv_opengles_debug.o ./Application/lvgl/src/drivers/glfw/lv_opengles_debug.su ./Application/lvgl/src/drivers/glfw/lv_opengles_driver.cyclo ./Application/lvgl/src/drivers/glfw/lv_opengles_driver.d ./Application/lvgl/src/drivers/glfw/lv_opengles_driver.o ./Application/lvgl/src/drivers/glfw/lv_opengles_driver.su ./Application/lvgl/src/drivers/glfw/lv_opengles_texture.cyclo ./Application/lvgl/src/drivers/glfw/lv_opengles_texture.d ./Application/lvgl/src/drivers/glfw/lv_opengles_texture.o ./Application/lvgl/src/drivers/glfw/lv_opengles_texture.su

.PHONY: clean-Application-2f-lvgl-2f-src-2f-drivers-2f-glfw

