#include "gates.h"
#include <iostream>
#include <Qt>
Gates::Gates(int x, int y) 
{
  image.load("1111.png");
  destroyed = FALSE;
   image = image.scaled(10,10,Qt::IgnoreAspectRatio,Qt::FastTransformation);
  rect = image.rect();
  
  rect.translate(x, y);
  
}

Gates::~Gates() {

}

QRect Gates::getRect()
{
  return rect;
}
void Gates::setRect(QRect rct)
{
  rect = rct;
}

QImage & Gates::getImage()
{
  return image;
}

bool Gates::isDestroyed()
{
  return destroyed;
}

void Gates::setDestroyed(bool destr)
{
  destroyed = destr;
}
