#include "power.h"
#include <iostream>
#include <QSize>
Power::Power()
{

  xdir = -2;
  ydir = -2;
 
  image.load("add.png");
  image = image.scaled(40,40,Qt::IgnoreAspectRatio,Qt::FastTransformation);
  rect = image.rect();
  
 

}

Power::~Power() {
 // std::cout << ("All Powers deleted\n");

}

void Power :: clear(){
rect.setRect(rand()%300,rand()%400,40,40);


}
void Power::autoMove()
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

void Power::resetState() 
{
  
  rect.moveTo(rand()%300, rand()%400);
}

void Power::moveBottom(int bottom)
{

  rect.moveBottom(bottom);
}

void Power::moveTop(int top)
{

  rect.moveTop(top);
}

void Power::moveLeft(int left)
{
 
  rect.moveLeft(left);
}

void Power::moveRight(int right)
{

  rect.moveRight(right);
}

void Power::setXDir(int x)
{
  xdir = x;
}

void Power::setYDir(int y)
{
  ydir = y;
}

int Power::getXDir()
{
  return xdir;
}

int Power::getYDir()
{
  return ydir;
}

QRect Power::getRect()
{
  return rect;
}


QImage & Power::getImage()
{
  return image;
}
