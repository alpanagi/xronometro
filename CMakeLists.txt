cmake_minimum_required(VERSION 3.30)
project(xronometro)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PulseAudio REQUIRED)

add_executable(xronometro)
target_sources(xronometro PRIVATE
    src/main.cpp
)
target_link_libraries(xronometro
    ${PULSEAUDIO_LIBRARY}
    pulse-simple
)
