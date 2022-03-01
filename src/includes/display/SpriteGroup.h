#ifndef SPRITEGROUP_H
#define SPRITEGROUP_H

#pragma once

#include <vector>
#include <display/Sprite.h>

class SpriteGroup
{
public:
    SpriteGroup();
    ~SpriteGroup();

    void add(char const *imageName, float x, float y);
    void update();
    int size();

private:
    std::vector<Sprite*> sprites;
};

#endif
