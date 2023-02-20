cmake_minimum_required(VERSION 3.24)
project(Project)

set(CMAKE_CXX_STANDARD 20)

add_executable(Project main.cpp Animal.cpp Animal.h Game.cpp Game.h League.cpp League.h Player.cpp Player.h User.cpp User.h)
