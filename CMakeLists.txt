cmake_minimum_required(VERSION 3.30)
project(c_language C)

set(CMAKE_C_STANDARD 11)

add_executable(c_language main.c
)
# update: W1 (2025-03-16 05:38:56)
add_executable(W1 ${CMAKE_SOURCE_DIR}/export/W1_김현민.c)
# update: W2 (2025-03-16 05:45:37)
add_executable(W2 ${CMAKE_SOURCE_DIR}/export/W2_김현민.c)
# update: W3 (2025-03-18 16:49:34)
add_executable(W3 ${CMAKE_SOURCE_DIR}/export/W3_김현민.c)
# update: W4 (2025-03-25 16:57:20)
add_executable(W4 ${CMAKE_SOURCE_DIR}/export/W4_김현민.c)
# update: W5 (2025-04-01 16:45:23)
add_executable(W5 ${CMAKE_SOURCE_DIR}/export/W5_김현민.c)

# update: W6 (2025-04-08 16:35:59)
add_executable(W6 ${CMAKE_SOURCE_DIR}/export/W6_김현민.c)
