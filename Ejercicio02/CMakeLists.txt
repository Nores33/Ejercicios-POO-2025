cmake_minimum_required(VERSION 3.16)

project(Ejercicio02 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Ejercicio02 main.cpp)

include(GNUInstallDirs)
install(TARGETS Ejercicio02
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
