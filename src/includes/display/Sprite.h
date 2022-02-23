#ifndef SPRITE_H
#define SPRITE_H

#pragma once

#include <shaders/BasicShader.h>

class Sprite
{
public:
BasicShader *ourShader;
    Sprite();
    ~Sprite();
    void init(char const *image1, int version);
    void render(int t);
    void destroy();



   

private:

};

#endif
