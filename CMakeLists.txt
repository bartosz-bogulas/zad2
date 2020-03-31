cmake_minimum_required(VERSION 3.15)
project(z2)

set(CMAKE_CXX_STANDARD 14)

include_directories(inc)

add_executable(z2
        inc/BazaTestu.hh
        inc/LZespolona.hh
        inc/WyrazenieZesp.hh
        src/BazaTestu.cpp
        src/LZespolona.cpp
        src/main.cpp
        src/WyrazenieZesp.cpp
        Makefile)
