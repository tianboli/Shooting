#include "enemybullet.h"

EnemyBullet :: EnemyBullet(){
  
  ydir = 0;
  image.load("bomb.png");
  image = image.scaled(20,20,Qt::IgnoreAspectRatio,Qt::FastTransformation);
  rect = image.rect();
  rect.setRect(-20,-20,20,20);
  xdir = 0;
  
}
EnemyBullet :: ~EnemyBullet(){


}
void EnemyBullet :: getxandy(int x, int y){

xofu = x;
yofu = y;

}
 void EnemyBullet:: autoMove(){

if(xofu > rect.x())
	xdir = 2;
	else 
	xdir = -2;
	if(yofu >rect.y())
	ydir = 2;
	else 
	ydir = -2;
rect.translate(xdir, ydir);
}

 void EnemyBullet :: resetState(int x, int y){
	rect.moveTo(x,y);
	
}
void EnemyBullet :: clear(){
	rect.setRect(0,0,0,0);

}

int EnemyBullet :: getxofu(){
	return xofu;

}

int EnemyBullet :: getyofu(){
	return yofu;

}
QRect EnemyBullet::getRect()
{
  return rect;
}

QImage & EnemyBullet::getImage()
{
  return image;
}
