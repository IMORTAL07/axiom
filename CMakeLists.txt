cmake_minimum_required(VERSION 3.20)

project(AxiomEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(axiom STATIC
    engine/core/Engine.cpp
)

target_include_directories(axiom
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)
