﻿cmake_minimum_required(VERSION 3.16)
project(FFTLib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include subdirectories
add_subdirectory(src)
add_subdirectory(tests)

# Enable testing
include(CTest)