#include "planets.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
Planets :: Planets(){
  xdir = 0;
  ydir = 2;
  earthimage.load("earth.png");
  jupiterimage.load("jupiter.png");
  blackimage.load("space.png");
  earthimage = earthimage.scaled(100,100,Qt::IgnoreAspectRatio,Qt::FastTransformation);
  jupiterimage = jupiterimage.scaled(150,150,Qt::IgnoreAspectRatio,Qt::FastTransformation);
  blackimage = blackimage.scaled(500,700,Qt::IgnoreAspectRatio,Qt::FastTransformation);
  black = blackimage.rect();
  black.setRect(-20,-100,500,700);
  earth = earthimage.rect();
  earth.setRect(50,50,100,100);
  jupiter = jupiterimage.rect();
  jupiter.setRect(200,300,150,150);

}
Planets :: ~Planets(){


}
 void Planets:: autoMove(){
earth.translate(xdir, ydir);
jupiter.translate(xdir,ydir);
if(jupiter.bottom() >= 400)
jupiter.moveTo(200,0);
if(earth.bottom()>=400)
earth.moveTo(50, 0);
}
/*
 void Planets :: resetState(int x, int y){
	earth.moveTo(x,y);

}
*/
QRect Planets::getearth()
{
  return earth;
}

QImage & Planets::getearthImage()
{
  return earthimage;
}

QRect Planets::getjupiter()
{
  return jupiter;
}

QImage & Planets::getjupiterImage()
{
  return jupiterimage;
}
QRect Planets::getblack()
{
  return black;
}

QImage & Planets::getblackImage()
{
  return blackimage;
}
