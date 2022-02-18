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
    void init();
    void render();
    void destroy();



   

private:

};

#endif
