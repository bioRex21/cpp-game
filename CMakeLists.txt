cmake_minimum_required(VERSION 3.0.0)
project(my_ccp_game VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(OpenGL REQUIRED COMPONENTS OpenGL)

set(UTILS "src/includes/MyClass.cpp" "src/includes/MyClass.h" "src/includes/vertexUtils/VertexUtils.cpp" "src/includes/vertexUtils/VertexUtils.h" "src/includes/vertexUtils/Constants.h" src/includes/timeUtils/WonkyTimer.cpp src/includes/timeUtils/WonkyTimer.h)
set(LOADERS "src/includes/loaders/TextureLoader.cpp" "src/includes/loaders/TextureLoader.h")
set(DISPLAY "src/includes/display/Sprite.cpp" "src/includes/display/Sprite.h" "src/includes/display/SpriteGroup.cpp" "src/includes/display/SpriteGroup.h" "src/includes/display/ColorQuad.cpp" "src/includes/display/ColorQuad.h")
set(DISPLAY2  "src/includes/display/ColorTriangle.cpp" "src/includes/display/ColorTriangle.h")
set(SHADERS "src/includes/shaders/BasicShader.cpp" "src/includes/shaders/BasicShader.h")
set(GAME "src/includes/creators/SpriteSpawner.cpp" "src/includes/creators/SpriteSpawner.h")
set(GEOM "src/includes/geom/BoundBox.cpp" "src/includes/geom/BoundBox.h" "src/includes/geom/Rectangle.cpp" "src/includes/geom/Rectangle.h" src/includes/containers/GameLevel.cpp src/includes/containers/GameLevel.h)


add_executable(my_ccp_game src/main.cpp ${UTILS} ${LOADERS} ${DISPLAY} ${DISPLAY2} ${SHADERS} ${GEOM} ${GAME} src/includes/glad/glad.c)
target_link_libraries(my_ccp_game OpenGL::GL)
target_link_libraries(my_ccp_game glfw)
include_directories (src/includes)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
