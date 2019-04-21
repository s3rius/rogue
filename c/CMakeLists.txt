cmake_minimum_required(VERSION 3.3)
project(c-rogue)
include_directories(./include/)
file(GLOB SOURCES
        ./include/*.h
        ./src/*.c
        ./src/utils/*.c
        ./src/windows/*.c
        )

#file(GLOB c-rogue_SRC
#        "/src/*.c"
#        "/include/*.h"
#        )

add_executable(c-rogue ${SOURCES})

target_link_libraries(${PROJECT_NAME} ncurses)
