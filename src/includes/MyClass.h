#ifndef MYCLASS_H
#define MYCLASS_H
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>
class MyClass {
 private:
 public:
  MyClass();
  ~MyClass();

  GLFWwindow *myWindow;
  void init();
  void framebuffer_size_callback(GLFWwindow *window, int width, int height);
  void createWindow();
};

#endif
