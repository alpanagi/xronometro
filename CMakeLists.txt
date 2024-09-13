cmake_minimum_required(VERSION 3.30)
project(timer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(timer)
target_sources(timer PRIVATE
    src/main.cpp
)
