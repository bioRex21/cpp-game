#include "BoundBox.h"

/**
 * @brief Construct a new Bound Box:: Bound Box object.
 * The origin of the bounding box is top left
 *
 * @param x
 * @param y
 * @param width
 * @param height
 */
BoundBox::BoundBox(float x, float y, float width, float height)
{
  // multiply by 0.5 to use top-left and bottom-right of the sprite instead of its center coordinates.
  this->x0 = x - (width * 0.5f);
  this->y0 = y - (height * 0.5f);
  this->x1 = x + (width * 0.5f);
  this->y1 = y + (height * 0.5f);
  this->originalWidth = width;
  this->originalHeight = height;
}

BoundBox::~BoundBox()
{

}

void BoundBox::update(float newX, float newY, float newScale) {
  this->width = originalWidth * newScale;
  this->height = originalHeight * newScale;

  this->x0 = newX - (width * 0.5f);
  this->y0 = newY - (height * 0.5f);
  this->x1 = newX + (width * 0.5f);
  this->y1 = newY + (height * 0.5f);
}

bool BoundBox :: intersects(BoundBox *collider) {

  bool first = this->x0 <= collider->x1;
  bool second = this->x1 >= collider->x0;
  bool third = this->y0 <= collider->y1;
  bool fourth = this->y1 >= collider->y0;

  return (this->x0 <= collider->x1 && this->x1 >= collider->x0) &&
         (this->y0 <= collider->y1 && this->y1 >= collider->y0);

}
