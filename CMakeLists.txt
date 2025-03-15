cmake_minimum_required(VERSION 3.30)
project(c_language C)

set(CMAKE_C_STANDARD 11)

add_executable(c_language main.c
)
# update: w1 (2025-03-16 05:38:56)
add_executable(w1 ${CMAKE_SOURCE_DIR}/export/w1_김현민.c)
