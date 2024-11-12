cmake_minimum_required(VERSION 3.20)

project(opencv_test VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

link_libraries(${OpenCV_LIBS})

# file(GLOB src *.cpp)

# add_executable(${PROJECT_NAME} ${src})

# target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

add_executable(image image.cpp)
add_executable(video video.cpp)
add_executable(mat Mat.cpp)
