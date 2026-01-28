cmake_minimum_required(VERSION 3.16)

project(viikkotehtava LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(viikkotehtava main.cpp
    asiakas.h asiakas.cpp
    pankkitili.h pankkitili.cpp
    luottotili.h luottotili.cpp)

include(GNUInstallDirs)
install(TARGETS viikkotehtava
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
