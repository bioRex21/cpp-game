#ifndef COLORQUAD_H
#define COLORQUAD_H

#pragma once


#include <glm/glm.hpp>
#include <shaders/BasicShader.h>

class ColorQuad
{
public:
   

     float x = 0;
    float y = 0;
    int t = 0;

    unsigned int VBO;
    unsigned int VAO; // it will save the GL states config
    unsigned int EBO;

    BasicShader *ourShader;
     ColorQuad();
    ~ColorQuad();
    void init();
    void render();
    void destroy();

private:
// Camera stuff
glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 1.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

float fov = 45.0f;
};

#endif
