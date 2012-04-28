#include "addscore.h"
#include <iostream>
#include <QSize>
Addscore::Addscore()
{

  xdir = -2;
  ydir = -2;
 
  image.load("up.png");
  image = image.scaled(40,40,Qt::IgnoreAspectRatio,Qt::FastTransformation);
  rect = image.rect();
  
 

}

Addscore::~Addscore() {
 // std::cout << ("All Addscores deleted\n");

}

void Addscore :: clear(){
rect.setRect(0,0,0,0);


}
void Addscore::autoMove()
{

 rect.translate(xdir, ydir);

  if (rect.left() <= 0) {
    xdir = 2;
  }

  if (rect.right() >= 300) {
    xdir = -2;
  }

  if (rect.top() <= 0) {
    ydir = 2;
  }
	if(rect.bottom() >=400)
	ydir=-2;

}

void Addscore::resetState() 
{
  
  rect.moveTo(69, 69);
}

void Addscore::moveBottom(int bottom)
{

  rect.moveBottom(bottom);
}

void Addscore::moveTop(int top)
{

  rect.moveTop(top);
}

void Addscore::moveLeft(int left)
{
 
  rect.moveLeft(left);
}

void Addscore::moveRight(int right)
{

  rect.moveRight(right);
}

void Addscore::setXDir(int x)
{
  xdir = x;
}

void Addscore::setYDir(int y)
{
  ydir = y;
}

int Addscore::getXDir()
{
  return xdir;
}

int Addscore::getYDir()
{
  return ydir;
}

QRect Addscore::getRect()
{
  return rect;
}


QImage & Addscore::getImage()
{
  return image;
}
