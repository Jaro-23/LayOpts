cmake_minimum_required(VERSION 3.10)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(LayOpts_CLI VERSION 0.1)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/Bin/Lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/Bin/Lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/Bin/)

add_subdirectory(Projects/LayOpts)

add_executable(${PROJECT_NAME} Projects/Interfaces/main.cpp)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
    LayOpts
)

if (PROJECT_IS_TOP_LEVEL AND UNIX)
    # Create symlink to compile_commands.json for IDE to pick it up
    execute_process(
        COMMAND ${CMAKE_COMMAND} -E create_symlink
            ${CMAKE_BINARY_DIR}/compile_commands.json
            ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json
    )
endif()
