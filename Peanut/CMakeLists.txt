cmake_minimum_required(VERSION 3.50)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../bin/")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../bin/")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../bin/")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Peanut)

include_directories(./Src/)
include_directories("${CMAKE_BINARY_DIR}/../Pch/Include/")

set(HEADERS
    ./src/Core/Defines.h
    ./src/Core/Updatable.h
    ./src/Utils/Math.h
    ./src/Utils/Types.h
    ./src/Events/EventInterface.h
    ./src/Events/Event.h
)

set(SOURCES
    ./Src/Main.cc
    ./Src/Core/App.cc
    ./Src/Events/EventInterface.cc
)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Build type" FORCE)
endif()

add_executable(Peanut ${HEADERS} ${SOURCES})

target_link_libraries(Peanut PUBLIC Pch)