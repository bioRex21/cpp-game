#include "SpriteGroup.h"
#include "vertexUtils/Constants.h"
SpriteGroup::SpriteGroup()
{
}

SpriteGroup::~SpriteGroup()
{
}

bool SpriteGroup::collidesWith(Sprite *sprite) {
    bool collides = false;
    for (std::size_t i = 0; i < sprites.size(); ++i) {
        if (sprites[i]->life > 0 && sprites[i]->overlaps(sprite)) {
            sprites[i]->takeHit();
            collides = true;
        }
    }

    return collides;
}

void SpriteGroup::add(Sprite *sprite) {
    sprites.push_back(sprite);
}

void SpriteGroup::createAndAdd(char const *imageName, float x, float y)
{
  Sprite *newSprite = new Sprite();
  newSprite->init(imageName, 2);
  newSprite->x = x;
  newSprite->y = y;
  ///newSprite->scale = 0.01;
  sprites.push_back(newSprite);
}

void SpriteGroup::update()
{
  for (std::size_t i = 0; i < sprites.size(); ++i)
  {
    if (sprites[i]->life > 0) {
        sprites[i]->render();
        sprites[i]->x+= 10;
        advanceSprite(sprites[i]);
        checkKillConditions(i);

    }

    //checkOutOfBounds(sprites[])
  }
  //TODO: Add condition to destroy when aoutside of bounds Constants::Width , height
}

void SpriteGroup::killAt(int index){
    sprites[index]->destroy();
    sprites.erase(sprites.begin()+index);
}

int SpriteGroup::size()
{
  return sprites.size();
}

void SpriteGroup::checkKillConditions(int index) {
    Sprite *sprite = sprites[index];
    if(sprite->x >= (Constants::WIDTH) || sprite->life <= 0) {
        killAt(index);
    }
}

void SpriteGroup::advanceSprite(Sprite *&pSprite) {

}
