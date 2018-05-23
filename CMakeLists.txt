cmake_minimum_required(VERSION 3.10)
project(games)


set(CMAKE_C_STANDARD 99)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)


include_directories("thirdparty/")
include_directories("src/")

set(SOURCES ./src/main.c
            ./src/bulls.c ./src/bulls.h
            ./src/matches.c ./src/matches.h)

set(TSOURCES ./test/main.c ./test/games_test.c
            ./src/bulls.c ./src/bulls.h
            ./src/matches.c ./src/matches.h)


add_executable(games ${SOURCES})
add_executable(gamestest ${TSOURCES})

enable_testing()
add_test(gamestest gamestest)