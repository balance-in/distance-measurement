cmake_minimum_required(VERSION 3.20.0)

set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 11)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
    message("Setting default build type to Release")
endif()

project(my_project_name VERSION 0.0.1 LANGUAGES C CXX)

set(OpenCV_DIR D:\\opencv-4.4.0\\build_mingw64\\install)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(./src)

add_subdirectory(./test)

add_subdirectory(./example)
