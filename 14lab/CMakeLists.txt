cmake_minimum_required(VERSION 3.14)
project(14lab C)

set(CMAKE_C_STANDARD 11)

find_library(LIBGD libgd2.dll PATHS lib/gd-2.0.33-1-bin/bin)
add_executable(14lab main.c bmp.c bmp.h structs.h game_config.c game_config.h)
target_link_libraries(14lab ${LIBGD})