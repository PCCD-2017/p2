cmake_minimum_required (VERSION 2.6)
project (p2)
add_executable(ej1 ej1.c ej4.c p2_ej4.c)
add_executable(ej2 ej2.c)
add_executable(ej3 ej3.c)
add_executable(ej4 ej4.c)
add_executable(p2ej4 p2_ej4.c)
set(
        CMAKE_RUNTIME_OUTPUT_DIRECTORY
        ${CMAKE_SOURCE_DIR}/out
)