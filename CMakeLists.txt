cmake_minimum_required(VERSION 3.0.0)
project(hello_my_cmake VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(OpenGL REQUIRED COMPONENTS OpenGL)

add_executable(hello_my_cmake src/main.cpp src/includes/MyClass.cpp src/includes/MyClass.h src/includes/glad/glad.c)
target_link_libraries(hello_my_cmake OpenGL::GL)
target_link_libraries(hello_my_cmake glfw)
include_directories (src/includes)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
