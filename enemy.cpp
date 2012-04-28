#include "enemy.h"
#include <iostream>
#include <QSize>
Enemy::Enemy()
{

  xdir = 1;
  ydir = -1;
 xdir2 = -1;
  ydir2 = 1;
 xdir3 = 1;
  ydir3 = 1;
 xdir4 = -1;
  ydir4 = -1;
 xdir5 = -1;
  ydir5 = 1;
 xdir6 = 1;
  ydir6 = 1;
  image.load("enemy.png");
  image = image.scaled(30,30,Qt::IgnoreAspectRatio,Qt::FastTransformation);
  rect = image.rect();
  rect2 = image.rect();
  rect3 = image.rect();
  rect4 = image.rect();
  rect5 = image.rect();
  rect6 = image.rect();
  resetState();

}

Enemy::~Enemy() {
 // std::cout << ("All Enemys deleted\n");

}
void Enemy :: clear(){
rect.setRect(-100,-100,30,30);
rect2.setRect(-100,-100,30,30);
rect3.setRect(-100,-100,30,30);
rect4.setRect(-100,-100,30,30);
rect5.setRect(-100,-100,30,30);
rect6.setRect(-100,-100,30,30);

}
void Enemy::autoMove()
{
rect2.translate(xdir2, ydir2);

  if (rect2.left() == 0) {
    xdir2 = 1;
  }

  if (rect2.right() == 300) {
    xdir2 = -1;
  }

  if (rect2.top() == 0) {
    ydir2 = 1;
  }
	if(rect2.bottom() ==400)
	ydir2=-1;
rect3.translate(xdir3, ydir3);

  if (rect3.left() == 0) {
    xdir3 = 1;
  }

  if (rect3.right() == 300) {
    xdir3 = -1;
  }

  if (rect3.top() == 0) {
    ydir3 = 1;
  }
	if(rect3.bottom() ==400)
	ydir3=-1;
rect4.translate(xdir4, ydir4);

  if (rect4.left() == 0) {
    xdir4 = 1;
  }

  if (rect4.right() == 300) {
    xdir4 = -1;
  }

  if (rect4.top() == 0) {
    ydir4 = 1;
  }
	if(rect4.bottom() ==400)
	ydir4=-1;
rect5.translate(xdir5, ydir5);

  if (rect5.left() == 0) {
    xdir5 = 1;
  }

  if (rect5.right() == 300) {
    xdir5 = -1;
  }

  if (rect5.top() == 0) {
    ydir5 = 1;
  }
	if(rect5.bottom() ==400)
	ydir5=-1;
rect6.translate(xdir6, ydir6);

  if (rect6.left() == 0) {
    xdir6 = 1;
  }

  if (rect6.right() == 300) {
    xdir6 = -1;
  }

  if (rect6.top() == 0) {
    ydir6 = 1;
  }
	if(rect6.bottom() ==400)
	ydir6=-1;
  rect.translate(xdir, ydir);

  if (rect.left() == 0) {
    xdir = 1;
  }

  if (rect.right() == 300) {
    xdir = -1;
  }

  if (rect.top() == 0) {
    ydir = 1;
  }
	if(rect.bottom() ==400)
	ydir=-1;
}

void Enemy::resetState() 
{
  rect2.moveTo(100,100);
  rect3.moveTo(150,230);
  rect4.moveTo(50,20);
  rect5.moveTo(200,300); 
  rect6.moveTo(110, 250);
  rect.moveTo(50, 355);
}

void Enemy::moveBottom(int bottom)
{
rect2.moveBottom(bottom);
rect3.moveBottom(bottom);
  rect4.moveBottom(bottom);
  rect5.moveBottom(bottom);
rect6.moveBottom(bottom);
  rect.moveBottom(bottom);
}

void Enemy::moveTop(int top)
{
rect2.moveTop(top);
rect3.moveTop(top);
  rect4.moveTop(top);
  rect5.moveTop(top);
rect6.moveTop(top);
  rect.moveTop(top);
}

void Enemy::moveLeft(int left)
{
  rect2.moveLeft(left);
rect3.moveLeft(left);
  rect4.moveLeft(left);
  rect5.moveLeft(left);
rect6.moveLeft(left);
  rect.moveLeft(left);
}

void Enemy::moveRight(int right)
{
rect2.moveRight(right);
rect3.moveRight(right);
  rect4.moveRight(right);
  rect5.moveRight(right);
 rect6.moveRight(right);
  rect.moveRight(right);
}
bool Enemy :: destried(){
/*
if(rect==NULL||rect2==NULL||rect3==NULL||rect4==NULL||rect5==NULL||rect6==NULL)
return true;
else 
*/
return false;
}
void Enemy::setXDir(int x)
{
  xdir = x;
}

void Enemy::setYDir(int y)
{
  ydir = y;
}

int Enemy::getXDir()
{
  return xdir;
}

int Enemy::getYDir()
{
  return ydir;
}

QRect Enemy::getRect()
{
  return rect;
}

QRect Enemy::getRect2()
{
  return rect2;
}
QRect Enemy::getRect3()
{
  return rect3;
}
QRect Enemy::getRect4()
{
  return rect4;
}
QRect Enemy::getRect5()
{
  return rect5;
}
QRect Enemy::getRect6()
{
  return rect6;
}
QImage & Enemy::getImage()
{
  return image;
}
