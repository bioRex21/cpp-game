#ifndef SPRITE_H
#define SPRITE_H

#pragma once

#include <shaders/BasicShader.h>

class Sprite
{
public:
    unsigned int texture1;
    unsigned int VBO;
    unsigned int VAO; // it will save the GL states config
    unsigned int EBO;

    BasicShader *ourShader;
    Sprite();
    ~Sprite();
    void init(char const *image1, int version);
    void render(int t);
    void destroy();

private:
};

#endif
