cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)
project(led_controller C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()
add_executable(led_controller
    main.c
)
pico_enable_stdio_usb(led_controller 1)
pico_enable_stdio_uart(led_controller 1)
pico_add_extra_outputs(led_controller)
target_link_libraries(led_controller pico_stdlib)
