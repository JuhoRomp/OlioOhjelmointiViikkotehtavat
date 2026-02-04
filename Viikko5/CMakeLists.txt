cmake_minimum_required(VERSION 3.16)

project(Viikko5 LANGUAGES CXX)

add_executable(Viikko5
    main.cpp
    notifikaattori.cpp
    seuraaja.cpp
)

include(GNUInstallDirs)
install(TARGETS Viikko5
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
