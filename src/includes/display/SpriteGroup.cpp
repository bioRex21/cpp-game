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
  sprites.push_back(newSprite);
}

void SpriteGroup::update()
{
  for (std::size_t i = 0; i < sprites.size(); ++i)
  {

    sprites[i]->render();
  }
}

int SpriteGroup::size()
{
  return sprites.size();
}
