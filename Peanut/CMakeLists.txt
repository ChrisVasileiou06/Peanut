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
    ./Src/Core/Defines.h
    ./Src/Core/Updatable.h
    ./Src/Core/Data.h
    ./Src/Utils/Math.h
    ./Src/Utils/Types.h
    ./Src/Events/EventInterface.h
    ./Src/Events/Event.h
)

set(SOURCES
    ./Src/Main.cc
    ./Src/Core/App.cc
    ./Src/Core/Data.cc
    ./Src/Events/EventInterface.cc
)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Build type" FORCE)
endif()

add_executable(Peanut ${HEADERS} ${SOURCES})

target_link_libraries(Peanut PUBLIC Pch)