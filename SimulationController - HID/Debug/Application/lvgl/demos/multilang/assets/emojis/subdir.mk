################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/lvgl/demos/multilang/assets/emojis/img_emoji_artist_palette.c \
../Application/lvgl/demos/multilang/assets/emojis/img_emoji_books.c \
../Application/lvgl/demos/multilang/assets/emojis/img_emoji_camera_with_flash.c \
../Application/lvgl/demos/multilang/assets/emojis/img_emoji_cat_face.c \
../Application/lvgl/demos/multilang/assets/emojis/img_emoji_deciduous_tree.c \
../Application/lvgl/demos/multilang/assets/emojis/img_emoji_dog_face.c \
../Application/lvgl/demos/multilang/assets/emojis/img_emoji_earth_globe_europe_africa.c \
../Application/lvgl/demos/multilang/assets/emojis/img_emoji_flexed_biceps.c \
../Application/lvgl/demos/multilang/assets/emojis/img_emoji_movie_camera.c \
../Application/lvgl/demos/multilang/assets/emojis/img_emoji_red_heart.c \
../Application/lvgl/demos/multilang/assets/emojis/img_emoji_rocket.c \
../Application/lvgl/demos/multilang/assets/emojis/img_emoji_soccer_ball.c 

OBJS += \
./Application/lvgl/demos/multilang/assets/emojis/img_emoji_artist_palette.o \
./Application/lvgl/demos/multilang/assets/emojis/img_emoji_books.o \
./Application/lvgl/demos/multilang/assets/emojis/img_emoji_camera_with_flash.o \
./Application/lvgl/demos/multilang/assets/emojis/img_emoji_cat_face.o \
./Application/lvgl/demos/multilang/assets/emojis/img_emoji_deciduous_tree.o \
./Application/lvgl/demos/multilang/assets/emojis/img_emoji_dog_face.o \
./Application/lvgl/demos/multilang/assets/emojis/img_emoji_earth_globe_europe_africa.o \
./Application/lvgl/demos/multilang/assets/emojis/img_emoji_flexed_biceps.o \
./Application/lvgl/demos/multilang/assets/emojis/img_emoji_movie_camera.o \
./Application/lvgl/demos/multilang/assets/emojis/img_emoji_red_heart.o \
./Application/lvgl/demos/multilang/assets/emojis/img_emoji_rocket.o \
./Application/lvgl/demos/multilang/assets/emojis/img_emoji_soccer_ball.o 

C_DEPS += \
./Application/lvgl/demos/multilang/assets/emojis/img_emoji_artist_palette.d \
./Application/lvgl/demos/multilang/assets/emojis/img_emoji_books.d \
./Application/lvgl/demos/multilang/assets/emojis/img_emoji_camera_with_flash.d \
./Application/lvgl/demos/multilang/assets/emojis/img_emoji_cat_face.d \
./Application/lvgl/demos/multilang/assets/emojis/img_emoji_deciduous_tree.d \
./Application/lvgl/demos/multilang/assets/emojis/img_emoji_dog_face.d \
./Application/lvgl/demos/multilang/assets/emojis/img_emoji_earth_globe_europe_africa.d \
./Application/lvgl/demos/multilang/assets/emojis/img_emoji_flexed_biceps.d \
./Application/lvgl/demos/multilang/assets/emojis/img_emoji_movie_camera.d \
./Application/lvgl/demos/multilang/assets/emojis/img_emoji_red_heart.d \
./Application/lvgl/demos/multilang/assets/emojis/img_emoji_rocket.d \
./Application/lvgl/demos/multilang/assets/emojis/img_emoji_soccer_ball.d 


# Each subdirectory must supply rules for building sources it contributes
Application/lvgl/demos/multilang/assets/emojis/%.o Application/lvgl/demos/multilang/assets/emojis/%.su Application/lvgl/demos/multilang/assets/emojis/%.cyclo: ../Application/lvgl/demos/multilang/assets/emojis/%.c Application/lvgl/demos/multilang/assets/emojis/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../USB_Device/App -I../USB_Device/Target -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/System/Inc" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/lvgl" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/ui" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application" -I"C:/Users/Ziga/Desktop/EDUCATION/STM32Workspace/SimulationController - HID/Application/Display" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-lvgl-2f-demos-2f-multilang-2f-assets-2f-emojis

clean-Application-2f-lvgl-2f-demos-2f-multilang-2f-assets-2f-emojis:
	-$(RM) ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_artist_palette.cyclo ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_artist_palette.d ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_artist_palette.o ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_artist_palette.su ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_books.cyclo ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_books.d ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_books.o ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_books.su ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_camera_with_flash.cyclo ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_camera_with_flash.d ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_camera_with_flash.o ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_camera_with_flash.su ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_cat_face.cyclo ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_cat_face.d ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_cat_face.o ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_cat_face.su ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_deciduous_tree.cyclo ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_deciduous_tree.d ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_deciduous_tree.o ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_deciduous_tree.su ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_dog_face.cyclo ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_dog_face.d ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_dog_face.o ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_dog_face.su ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_earth_globe_europe_africa.cyclo ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_earth_globe_europe_africa.d ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_earth_globe_europe_africa.o ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_earth_globe_europe_africa.su ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_flexed_biceps.cyclo ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_flexed_biceps.d ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_flexed_biceps.o ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_flexed_biceps.su ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_movie_camera.cyclo ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_movie_camera.d ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_movie_camera.o ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_movie_camera.su ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_red_heart.cyclo ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_red_heart.d ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_red_heart.o ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_red_heart.su ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_rocket.cyclo ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_rocket.d ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_rocket.o ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_rocket.su ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_soccer_ball.cyclo ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_soccer_ball.d ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_soccer_ball.o ./Application/lvgl/demos/multilang/assets/emojis/img_emoji_soccer_ball.su

.PHONY: clean-Application-2f-lvgl-2f-demos-2f-multilang-2f-assets-2f-emojis

