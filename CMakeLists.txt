cmake_minimum_required(VERSION 3.8)
project(Project)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Chip.cpp Chip.h GamePlayer.cpp GamePlayer.h Board.cpp Board.h Human.cpp Human.h Newton.cpp Newton.h Blocker.cpp Blocker.h)
add_executable(Project ${SOURCE_FILES} Chip.cpp Chip.h GamePlayer.cpp GamePlayer.h Human.cpp Human.h)