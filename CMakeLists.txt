cmake_minimum_required(VERSION 3.5)

project(GuessByte LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    guessbyte.cpp
    main.cpp
)

set(HEADERS
    guessbyte.h
)

add_executable(GuessByte ${SOURCES} ${HEADERS})

install(TARGETS GuessByte
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
