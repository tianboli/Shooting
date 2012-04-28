#include "shotenemy.h"
#include <iostream>
#include <QSize>
ShotEnemy::ShotEnemy()
{

  xdir = -1;
  ydir = 0;
 
  enemyimage.load("ufo.png");
  enemyimage = enemyimage.scaled(30,30,Qt::IgnoreAspectRatio,Qt::FastTransformation);
  enemyrect = enemyimage.rect();
  
  destroied = FALSE;

}

ShotEnemy::~ShotEnemy() {
 // std::cout << ("All ShotEnemys deleted\n");

}

void ShotEnemy :: clear(){
enemyrect.setSize(QSize(0,0));


}
void ShotEnemy::autoMove()
{
enemyrect.translate(xdir, ydir);

  if (enemyrect.left()==0) {
    xdir = 1;
  }
	if (enemyrect.right()==300) {
    xdir = -1;
  }


}

void ShotEnemy::resetState(int x, int y) 
{
  
  enemyrect.moveTo(x, y);
}

void ShotEnemy::moveBottom(int bottom)
{

  enemyrect.moveBottom(bottom);
}

void ShotEnemy::moveTop(int top)
{

  enemyrect.moveTop(top);
}

void ShotEnemy::moveLeft(int left)
{
 
  enemyrect.moveLeft(left);
}

void ShotEnemy::moveRight(int right)
{

  enemyrect.moveRight(right);
}
void ShotEnemy :: setdestried(){
/*
if(rect==NULL||rect2==NULL||rect3==NULL||rect4==NULL||rect5==NULL||rect6==NULL)
return true;
else 
*/
destroied = TRUE;
}
void ShotEnemy::setXDir(int x)
{
  xdir = x;
}

void ShotEnemy::setYDir(int y)
{
  ydir = y;
}

int ShotEnemy::getXDir()
{
  return xdir;
}

int ShotEnemy::getYDir()
{
  return ydir;
}

QRect ShotEnemy::getenemy()
{
  return enemyrect;
}


QImage & ShotEnemy::getenemyImage()
{
  return enemyimage;
}
