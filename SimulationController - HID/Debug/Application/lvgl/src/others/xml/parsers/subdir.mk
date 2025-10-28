################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/lvgl/src/others/xml/parsers/lv_xml_button_parser.c \
../Application/lvgl/src/others/xml/parsers/lv_xml_chart_parser.c \
../Application/lvgl/src/others/xml/parsers/lv_xml_image_parser.c \
../Application/lvgl/src/others/xml/parsers/lv_xml_label_parser.c \
../Application/lvgl/src/others/xml/parsers/lv_xml_obj_parser.c \
../Application/lvgl/src/others/xml/parsers/lv_xml_slider_parser.c \
../Application/lvgl/src/others/xml/parsers/lv_xml_tabview_parser.c 

OBJS += \
./Application/lvgl/src/others/xml/parsers/lv_xml_button_parser.o \
./Application/lvgl/src/others/xml/parsers/lv_xml_chart_parser.o \
./Application/lvgl/src/others/xml/parsers/lv_xml_image_parser.o \
./Application/lvgl/src/others/xml/parsers/lv_xml_label_parser.o \
./Application/lvgl/src/others/xml/parsers/lv_xml_obj_parser.o \
./Application/lvgl/src/others/xml/parsers/lv_xml_slider_parser.o \
./Application/lvgl/src/others/xml/parsers/lv_xml_tabview_parser.o 

C_DEPS += \
./Application/lvgl/src/others/xml/parsers/lv_xml_button_parser.d \
./Application/lvgl/src/others/xml/parsers/lv_xml_chart_parser.d \
./Application/lvgl/src/others/xml/parsers/lv_xml_image_parser.d \
./Application/lvgl/src/others/xml/parsers/lv_xml_label_parser.d \
./Application/lvgl/src/others/xml/parsers/lv_xml_obj_parser.d \
./Application/lvgl/src/others/xml/parsers/lv_xml_slider_parser.d \
./Application/lvgl/src/others/xml/parsers/lv_xml_tabview_parser.d 


# Each subdirectory must supply rules for building sources it contributes
Application/lvgl/src/others/xml/parsers/%.o Application/lvgl/src/others/xml/parsers/%.su Application/lvgl/src/others/xml/parsers/%.cyclo: ../Application/lvgl/src/others/xml/parsers/%.c Application/lvgl/src/others/xml/parsers/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../USB_Device/App -I../USB_Device/Target -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/System/Inc" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/lvgl" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/ui" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/Display" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-lvgl-2f-src-2f-others-2f-xml-2f-parsers

clean-Application-2f-lvgl-2f-src-2f-others-2f-xml-2f-parsers:
	-$(RM) ./Application/lvgl/src/others/xml/parsers/lv_xml_button_parser.cyclo ./Application/lvgl/src/others/xml/parsers/lv_xml_button_parser.d ./Application/lvgl/src/others/xml/parsers/lv_xml_button_parser.o ./Application/lvgl/src/others/xml/parsers/lv_xml_button_parser.su ./Application/lvgl/src/others/xml/parsers/lv_xml_chart_parser.cyclo ./Application/lvgl/src/others/xml/parsers/lv_xml_chart_parser.d ./Application/lvgl/src/others/xml/parsers/lv_xml_chart_parser.o ./Application/lvgl/src/others/xml/parsers/lv_xml_chart_parser.su ./Application/lvgl/src/others/xml/parsers/lv_xml_image_parser.cyclo ./Application/lvgl/src/others/xml/parsers/lv_xml_image_parser.d ./Application/lvgl/src/others/xml/parsers/lv_xml_image_parser.o ./Application/lvgl/src/others/xml/parsers/lv_xml_image_parser.su ./Application/lvgl/src/others/xml/parsers/lv_xml_label_parser.cyclo ./Application/lvgl/src/others/xml/parsers/lv_xml_label_parser.d ./Application/lvgl/src/others/xml/parsers/lv_xml_label_parser.o ./Application/lvgl/src/others/xml/parsers/lv_xml_label_parser.su ./Application/lvgl/src/others/xml/parsers/lv_xml_obj_parser.cyclo ./Application/lvgl/src/others/xml/parsers/lv_xml_obj_parser.d ./Application/lvgl/src/others/xml/parsers/lv_xml_obj_parser.o ./Application/lvgl/src/others/xml/parsers/lv_xml_obj_parser.su ./Application/lvgl/src/others/xml/parsers/lv_xml_slider_parser.cyclo ./Application/lvgl/src/others/xml/parsers/lv_xml_slider_parser.d ./Application/lvgl/src/others/xml/parsers/lv_xml_slider_parser.o ./Application/lvgl/src/others/xml/parsers/lv_xml_slider_parser.su ./Application/lvgl/src/others/xml/parsers/lv_xml_tabview_parser.cyclo ./Application/lvgl/src/others/xml/parsers/lv_xml_tabview_parser.d ./Application/lvgl/src/others/xml/parsers/lv_xml_tabview_parser.o ./Application/lvgl/src/others/xml/parsers/lv_xml_tabview_parser.su

.PHONY: clean-Application-2f-lvgl-2f-src-2f-others-2f-xml-2f-parsers

