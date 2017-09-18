cmake_minimum_required(VERSION 3.7)
project(Examen2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Libro.cpp Libro.h Evaluador.cpp Evaluador.h NodoBinario.cpp NodoBinario.h)
add_executable(Examen2 ${SOURCE_FILES})