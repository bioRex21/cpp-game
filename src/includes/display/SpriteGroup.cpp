#include "SpriteGroup.h"

SpriteGroup::SpriteGroup()
{
}

SpriteGroup::~SpriteGroup()
{
}

void SpriteGroup::add(char const *imageName, float x, float y)
{
  Sprite *newSprite = new Sprite();
  newSprite->init(imageName, 2);
  newSprite->x = x;
  newSprite->y = y;
  newSprite->scale = 0.01;
  sprites.push_back(newSprite);
}

void SpriteGroup::update()
{
  for (std::size_t i = 0; i < sprites.size(); ++i)
  {
    if (sprites[i]->scale < 1.0f) {
      sprites[i]->scale += 0.01f;
    }

    if( sprites[i]->scale >= 1.0f) {
      sprites[i]->scale = 0.01f;
    }
    sprites[i]->render();
  }
}

int SpriteGroup::size()
{
  return sprites.size();
}
