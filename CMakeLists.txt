cmake_minimum_required(VERSION 3.12)
project(Client)


set(CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/include)


#Adding GLFW and Dependecies
add_subdirectory(${PROJECT_SOURCE_DIR}/deps/glfw-3.2.1)
include_directories(${PROJECT_SOURCE_DIR}/deps/glfw-3.2.1/include)




add_executable(Client ClientMain.cpp)
add_executable(Outreach OutreachMain.cpp)
add_executable(Server ServerMain.cpp)



target_link_libraries(Client glfw ${GLFW_LIBRARIES})
target_link_libraries(Outreach glfw ${GLFW_LIBRARIES})
