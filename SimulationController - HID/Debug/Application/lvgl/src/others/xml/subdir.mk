################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/lvgl/src/others/xml/lv_xml.c \
../Application/lvgl/src/others/xml/lv_xml_base_types.c \
../Application/lvgl/src/others/xml/lv_xml_component.c \
../Application/lvgl/src/others/xml/lv_xml_parser.c \
../Application/lvgl/src/others/xml/lv_xml_style.c \
../Application/lvgl/src/others/xml/lv_xml_utils.c \
../Application/lvgl/src/others/xml/lv_xml_widget.c 

OBJS += \
./Application/lvgl/src/others/xml/lv_xml.o \
./Application/lvgl/src/others/xml/lv_xml_base_types.o \
./Application/lvgl/src/others/xml/lv_xml_component.o \
./Application/lvgl/src/others/xml/lv_xml_parser.o \
./Application/lvgl/src/others/xml/lv_xml_style.o \
./Application/lvgl/src/others/xml/lv_xml_utils.o \
./Application/lvgl/src/others/xml/lv_xml_widget.o 

C_DEPS += \
./Application/lvgl/src/others/xml/lv_xml.d \
./Application/lvgl/src/others/xml/lv_xml_base_types.d \
./Application/lvgl/src/others/xml/lv_xml_component.d \
./Application/lvgl/src/others/xml/lv_xml_parser.d \
./Application/lvgl/src/others/xml/lv_xml_style.d \
./Application/lvgl/src/others/xml/lv_xml_utils.d \
./Application/lvgl/src/others/xml/lv_xml_widget.d 


# Each subdirectory must supply rules for building sources it contributes
Application/lvgl/src/others/xml/%.o Application/lvgl/src/others/xml/%.su Application/lvgl/src/others/xml/%.cyclo: ../Application/lvgl/src/others/xml/%.c Application/lvgl/src/others/xml/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../USB_Device/App -I../USB_Device/Target -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/System/Inc" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/lvgl" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/ui" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/Display" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-lvgl-2f-src-2f-others-2f-xml

clean-Application-2f-lvgl-2f-src-2f-others-2f-xml:
	-$(RM) ./Application/lvgl/src/others/xml/lv_xml.cyclo ./Application/lvgl/src/others/xml/lv_xml.d ./Application/lvgl/src/others/xml/lv_xml.o ./Application/lvgl/src/others/xml/lv_xml.su ./Application/lvgl/src/others/xml/lv_xml_base_types.cyclo ./Application/lvgl/src/others/xml/lv_xml_base_types.d ./Application/lvgl/src/others/xml/lv_xml_base_types.o ./Application/lvgl/src/others/xml/lv_xml_base_types.su ./Application/lvgl/src/others/xml/lv_xml_component.cyclo ./Application/lvgl/src/others/xml/lv_xml_component.d ./Application/lvgl/src/others/xml/lv_xml_component.o ./Application/lvgl/src/others/xml/lv_xml_component.su ./Application/lvgl/src/others/xml/lv_xml_parser.cyclo ./Application/lvgl/src/others/xml/lv_xml_parser.d ./Application/lvgl/src/others/xml/lv_xml_parser.o ./Application/lvgl/src/others/xml/lv_xml_parser.su ./Application/lvgl/src/others/xml/lv_xml_style.cyclo ./Application/lvgl/src/others/xml/lv_xml_style.d ./Application/lvgl/src/others/xml/lv_xml_style.o ./Application/lvgl/src/others/xml/lv_xml_style.su ./Application/lvgl/src/others/xml/lv_xml_utils.cyclo ./Application/lvgl/src/others/xml/lv_xml_utils.d ./Application/lvgl/src/others/xml/lv_xml_utils.o ./Application/lvgl/src/others/xml/lv_xml_utils.su ./Application/lvgl/src/others/xml/lv_xml_widget.cyclo ./Application/lvgl/src/others/xml/lv_xml_widget.d ./Application/lvgl/src/others/xml/lv_xml_widget.o ./Application/lvgl/src/others/xml/lv_xml_widget.su

.PHONY: clean-Application-2f-lvgl-2f-src-2f-others-2f-xml

