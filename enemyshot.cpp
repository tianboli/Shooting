#include "enemyshot.h"
#include <iostream>
#include <QSize>
Enemyshot::Enemyshot()
{

  xdir = 1;
  ydir = 1;
 
  enemyimage.load("followenemy.png");
  enemyimage = enemyimage.scaled(40,40,Qt::IgnoreAspectRatio,Qt::FastTransformation);
  enemyrect = enemyimage.rect();
  resetState();
  destroied = FALSE;

}

Enemyshot::~Enemyshot() {
 // std::cout << ("All Enemyshots deleted\n");

}

void Enemyshot :: clear(){
enemyrect.setRect(rand()%300,rand()%400,40,40);


}
void Enemyshot::autoMove(int x,int y)
{
enemyrect.translate(xdir, ydir);

  if (enemyrect.left()< x) {
    xdir = 1;
  }

  if (enemyrect.left()>x) {
    xdir = -1;
  }

  if (enemyrect.top()>y) {
    ydir = -1;
  }
	if(enemyrect.top()<y)
	ydir=1;


 
}

void Enemyshot::resetState() 
{
  
  enemyrect.moveTo(rand()%200, rand()%200);
}

void Enemyshot::moveBottom(int bottom)
{

  enemyrect.moveBottom(bottom);
}

void Enemyshot::moveTop(int top)
{

  enemyrect.moveTop(top);
}

void Enemyshot::moveLeft(int left)
{
 
  enemyrect.moveLeft(left);
}

void Enemyshot::moveRight(int right)
{

  enemyrect.moveRight(right);
}
void Enemyshot :: setdestried(){
/*
if(rect==NULL||rect2==NULL||rect3==NULL||rect4==NULL||rect5==NULL||rect6==NULL)
return true;
else 
*/
destroied = TRUE;
}
void Enemyshot::setXDir(int x)
{
  xdir = x;
}

void Enemyshot::setYDir(int y)
{
  ydir = y;
}

int Enemyshot::getXDir()
{
  return xdir;
}

int Enemyshot::getYDir()
{
  return ydir;
}

QRect Enemyshot::getenemy()
{
  return enemyrect;
}


QImage & Enemyshot::getenemyImage()
{
  return enemyimage;
}
