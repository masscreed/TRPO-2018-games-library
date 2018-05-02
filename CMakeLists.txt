cmake_minimum_required(VERSION 3.10)
project(games)

set(CMAKE_C_STANDARD 99)

include_directories("thirdparty/")

set(MSOURCES ./src/main.c
            ./src/matches.c
            ./src/matches.h)

set(BSOURCES ./src/main.c
            ./src/bulls.c
            ./src/bulls.h)


add_executable(matches ${MSOURCES})
add_executable(bulls ${BSOURCES})

