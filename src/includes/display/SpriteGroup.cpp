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
  newSprite->init(imageName);
  newSprite->x = x;
  newSprite->y = y;
  sprites.push_back(newSprite);
}

void SpriteGroup::update()
{
  for (std::size_t i = 0; i < sprites.size(); ++i)
  {
    if (sprites[i]->life > 0) {
        sprites[i]->render();
        //sprites[i]->x+= 10;
        advanceSprite(sprites[i]);
       // checkKillConditions(i);

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

void SpriteGroup::advanceSprite(Sprite *sprite) {
       if (sprite->direction == "right") {
        sprite->x+= 10;
       } else if (sprite->direction == "left") {
        sprite->x-= 10;
    } else if (sprite->direction == "up") {
        sprite->y-= 10;
    } else if (sprite->direction == "down") {
        sprite->y+= 10;
    } else {
           sprite->x+= 10;
           //sprite->y+= 1;
       }

}
