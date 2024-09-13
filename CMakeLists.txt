cmake_minimum_required(VERSION 3.30)
project(countdown)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(countdown)
target_sources(countdown PRIVATE
    src/main.cpp
)
target_link_libraries(countdown
    ${PULSEAUDIO_LIBRARY}
    pulse-simple
)
