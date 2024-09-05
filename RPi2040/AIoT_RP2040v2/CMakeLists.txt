cmake_minimum_required(VERSION 3.25)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(parpadeo_led C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

set(DRIVER_SOURCE_DIR "./driver-libraries" )
include_directories( ${PROJECT_SOURCE_DIR} ${DRIVER_SOURCE_DIR} ${DRIVER_SOURCE_DIR}/Arduino )

set (ARDUINO_SOURCE_DIR "${DRIVER_SOURCE_DIR}/Arduino")
FILE(GLOB_RECURSE Arduino_Sources       ${ARDUINO_SOURCE_DIR}/SPI.cpp ${ARDUINO_SOURCE_DIR}/delay.cpp ${ARDUINO_SOURCE_DIR}/rpipicow/picow_init.cpp
                                        ${ARDUINO_SOURCE_DIR}/rpipicow/picow_digital.cpp ${ARDUINO_SOURCE_DIR}/wiring_private.cpp ${ARDUINO_SOURCE_DIR}/wiring_digital.cpp
                                        ${ARDUINO_SOURCE_DIR}/wiring_analog.cpp ${ARDUINO_SOURCE_DIR}/Print.cpp )

add_executable(parpadeo_led
        parpadeo_led.c
        )

pico_add_extra_outputs(parpadeo_led)

target_link_libraries(parpadeo_led 
        pico_stdlib
        )
