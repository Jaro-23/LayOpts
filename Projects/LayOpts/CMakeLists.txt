cmake_minimum_required(VERSION 3.10)

project(LayOpts VERSION 0.1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find the libraries
find_package(LLVM REQUIRED CONFIG)
find_package(Clang REQUIRED CONFIG)
find_package(zstd REQUIRED)

# Include the libraries
include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})
include_directories(${CLANG_INCLUDE_DIRS})
add_definitions(${CLANG_DEFINITIONS})

file(GLOB_RECURSE SOURCES "${PROJECT_SOURCE_DIR}/*.cpp")
add_library(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC
    ${PROJECT_SOURCE_DIR}/Parsers/headers
    ${PROJECT_SOURCE_DIR}/Types/headers
    ${LLVM_INCLUDE_DIRS}
    ${CLANG_INCLUDE_DIRS}
)

# Link against libraries
llvm_map_components_to_libnames(llvm_libs
    core
    irreader
    support
    option
    bitreader
    remarks
    targetparser
)
target_link_libraries(${PROJECT_NAME}
    PRIVATE
    ${llvm_libs}
    clangAST
    clangASTMatchers
    clangBasic
    clangFrontend
    clangSerialization
    clangTooling
    clangDriver
    clangLex
)
