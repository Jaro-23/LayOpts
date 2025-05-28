cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(LayOpts_CLI VERSION 0.1)

add_subdirectory(Projects/LayOpts)

add_executable(${PROJECT_NAME} Projects/Interfaces/main.cpp)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
    LayOpts
)
