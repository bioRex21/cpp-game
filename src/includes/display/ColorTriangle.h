#ifndef COLORTRIANGLE_H
#define COLORTRIANGLE_H

#pragma once

#include <glm/glm.hpp>
#include <shaders/BasicShader.h>

class ColorTriangle
{
public:
    ColorTriangle();
    ~ColorTriangle();


      float x = 0;
    float y = 0;
    int t = 0;

    unsigned int VBO;
    unsigned int VAO; // it will save the GL states config
    unsigned int EBO;

    BasicShader *ourShader;
    void init();
    void render();
    void destroy();
private:

};

#endif
