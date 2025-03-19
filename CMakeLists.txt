cmake_minimum_required(VERSION 3.30)
project(c_language C)

set(CMAKE_C_STANDARD 11)

add_executable(c_language main.c
)
# update: W1 (2025-03-16 05:38:56)
add_executable(W1 ${CMAKE_SOURCE_DIR}/export/w1_김현민.c)
# update: W2 (2025-03-16 05:45:37)
add_executable(W2 ${CMAKE_SOURCE_DIR}/export/w2_김현민.c)
# update: W3 (2025-03-18 16:49:34)
add_executable(W3 ${CMAKE_SOURCE_DIR}/export/w3_김현민.c)
