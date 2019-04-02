cmake_minimum_required(VERSION 3.13)
project(game_of_life C)

set(CMAKE_C_STANDARD 11)

add_executable(game_of_life src/main.c src/createenviroment.c src/upload.c src/managestate.c src/pngexample.h src/get_screenshot.c src/get_screenshot.h src/true_png.c src/true_png.h)