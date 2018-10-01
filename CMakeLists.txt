cmake_minimum_required(VERSION 3.12)
project(Client)


set(CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/include)


#Adding GLFW and Dependecies
add_subdirectory(${PROJECT_SOURCE_DIR}/deps/glfw-3.2.1)
include_directories(${PROJECT_SOURCE_DIR}/deps/glfw-3.2.1/include)

#All source files should be included here - Lunacats Dev
set(SOURCE_FILES main.cpp)





add_executable(Client ${SOURCE_FILES})


target_link_libraries(Client glfw ${GLFW_LIBRARIES})
