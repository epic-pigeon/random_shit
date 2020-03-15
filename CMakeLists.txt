cmake_minimum_required(VERSION 3.15)
project(ctest C)

set(CMAKE_C_STANDARD 99)

add_executable(ctest main.c printstream.c printstream.h functions.c functions.h types.h)
