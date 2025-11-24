cmake_minimum_required(VERSION 3.29)
project(PowerConverterSimulator)

set(CMAKE_CXX_STANDARD 11)

include_directories(
        ${PROJECT_SOURCE_DIR}/include
)

add_subdirectory(src)
add_subdirectory(plugins)

enable_testing()
add_subdirectory(tests)

#add_subdirectory(gui)
