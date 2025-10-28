################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/lvgl/examples/event/lv_example_event_bubble.c \
../Application/lvgl/examples/event/lv_example_event_button.c \
../Application/lvgl/examples/event/lv_example_event_click.c \
../Application/lvgl/examples/event/lv_example_event_draw.c \
../Application/lvgl/examples/event/lv_example_event_streak.c 

OBJS += \
./Application/lvgl/examples/event/lv_example_event_bubble.o \
./Application/lvgl/examples/event/lv_example_event_button.o \
./Application/lvgl/examples/event/lv_example_event_click.o \
./Application/lvgl/examples/event/lv_example_event_draw.o \
./Application/lvgl/examples/event/lv_example_event_streak.o 

C_DEPS += \
./Application/lvgl/examples/event/lv_example_event_bubble.d \
./Application/lvgl/examples/event/lv_example_event_button.d \
./Application/lvgl/examples/event/lv_example_event_click.d \
./Application/lvgl/examples/event/lv_example_event_draw.d \
./Application/lvgl/examples/event/lv_example_event_streak.d 


# Each subdirectory must supply rules for building sources it contributes
Application/lvgl/examples/event/%.o Application/lvgl/examples/event/%.su Application/lvgl/examples/event/%.cyclo: ../Application/lvgl/examples/event/%.c Application/lvgl/examples/event/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../USB_Device/App -I../USB_Device/Target -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/System/Inc" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/lvgl" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/ui" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/Display" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-lvgl-2f-examples-2f-event

clean-Application-2f-lvgl-2f-examples-2f-event:
	-$(RM) ./Application/lvgl/examples/event/lv_example_event_bubble.cyclo ./Application/lvgl/examples/event/lv_example_event_bubble.d ./Application/lvgl/examples/event/lv_example_event_bubble.o ./Application/lvgl/examples/event/lv_example_event_bubble.su ./Application/lvgl/examples/event/lv_example_event_button.cyclo ./Application/lvgl/examples/event/lv_example_event_button.d ./Application/lvgl/examples/event/lv_example_event_button.o ./Application/lvgl/examples/event/lv_example_event_button.su ./Application/lvgl/examples/event/lv_example_event_click.cyclo ./Application/lvgl/examples/event/lv_example_event_click.d ./Application/lvgl/examples/event/lv_example_event_click.o ./Application/lvgl/examples/event/lv_example_event_click.su ./Application/lvgl/examples/event/lv_example_event_draw.cyclo ./Application/lvgl/examples/event/lv_example_event_draw.d ./Application/lvgl/examples/event/lv_example_event_draw.o ./Application/lvgl/examples/event/lv_example_event_draw.su ./Application/lvgl/examples/event/lv_example_event_streak.cyclo ./Application/lvgl/examples/event/lv_example_event_streak.d ./Application/lvgl/examples/event/lv_example_event_streak.o ./Application/lvgl/examples/event/lv_example_event_streak.su

.PHONY: clean-Application-2f-lvgl-2f-examples-2f-event

