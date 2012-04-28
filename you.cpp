#include "you.h"
#include <iostream>
#include <Qt>
You::You()
{
  image.load("you.png");
   image = image.scaled(30,30,Qt::IgnoreAspectRatio,Qt::FastTransformation);
  rect = image.rect();
  resetState();
}

You::~You()
{

}
void You::moveTop(int up)
{
  if (rect.top() >= 1)
    rect.moveTo(rect.left(), up);
}
void You::moveBottom(int down)
{
  if (rect.bottom() <=398)
    rect.moveTo(rect.left(),down);
}
void You::moveLeft(int left)
{
  if (rect.left() >= 1)
    rect.moveTo(left, rect.top());
}

void You::moveRight(int right)
{
  if (rect.right() <= 298)
    rect.moveTo(right, rect.top());
}

void You::resetState()
{
  rect.moveTo(120, 180);
}

QRect You::getRect()
{
  return rect;
}

QImage & You::getImage()
{
  return image;
}
