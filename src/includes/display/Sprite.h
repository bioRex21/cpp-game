#ifndef SPRITE_H
#define SPRITE_H

#pragma once

#include <shaders/BasicShader.h>

class Sprite
{
public:
    float x = 0;
    float y = 0;
    int t = 0;

    unsigned int texture1;
    unsigned int VBO;
    unsigned int VAO; // it will save the GL states config
    unsigned int EBO;

    BasicShader *ourShader;
    Sprite();
    ~Sprite();
    void init(char const *image1, int version);
    void render();
    void destroy();

private:
};

#endif
