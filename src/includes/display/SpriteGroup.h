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
    std::string direction = "right";

    void add(Sprite *sprite);

private:
    std::vector<Sprite*> sprites;

    bool collidesWith(Sprite *sprite);

    void checkKillConditions(int index);
    void killAt(int index);

    void advanceSprite(Sprite *sprite);
};

#endif
