#include "shark.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
Shark :: Shark(){
  xdir = 1;
  ydir = 0;
  fishimage.load("fish.jpg");
  sharkimage.load("shark.PNG");
  backgroundimage.load("wave1.png");
  fishimage = fishimage.scaled(100,100,Qt::IgnoreAspectRatio,Qt::FastTransformation);
  sharkimage = sharkimage.scaled(150,150,Qt::IgnoreAspectRatio,Qt::FastTransformation);
  backgroundimage = backgroundimage.scaled(400,500,Qt::IgnoreAspectRatio,Qt::FastTransformation);
  background = backgroundimage.rect();
  background.setRect(-20,-100,400,500);
  fish = fishimage.rect();
  fish.setRect(50,50,80,80);
fish2 = fishimage.rect();
  fish2.setRect(10,200,80,80);

  shark = sharkimage.rect();
  shark.setRect(100,100,200,100);

}
Shark :: ~Shark(){


}
 void Shark:: autoMove(){
fish.translate(xdir, ydir);
fish2.translate(xdir, ydir);

shark.translate(-xdir,ydir);
if(shark.left() >= 300)
shark.moveTo(0,50);
if(fish.left()>=300)
fish.moveTo(0, 200);
if(fish2.left()>=300)
fish2.moveTo(0, 150);

}

QRect Shark::getfish()
{
  return fish;
}
QRect Shark::getfish2()
{
  return fish2;
}

QImage & Shark::getfishImage()
{
  return fishimage;
}
QImage & Shark::getfish2Image()
{
  return fishimage;
}

QRect Shark::getshark()
{
  return shark;
}

QImage & Shark::getsharkImage()
{
  return sharkimage;
}
QRect Shark::getbackground()
{
  return background;
}

QImage & Shark::getbackgroundImage()
{
  return backgroundimage;
}
