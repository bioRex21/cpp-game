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

    void createAndAdd(char const *imageName, float x, float y);
    void update();
    int size();

private:
    std::vector<Sprite*> sprites;

    void add(Sprite *sprite);

    bool collidesWith(Sprite *sprite);
};

#endif
