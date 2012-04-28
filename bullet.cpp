#include "bullet.h"

Bullet :: Bullet(){
  xdir = 0;
  ydir = -2;
  image.load("bullet.png");
  image = image.scaled(20,20,Qt::IgnoreAspectRatio,Qt::FastTransformation);
  rect = image.rect();
  rect.setRect(-100,-100,20,20);
}
Bullet :: ~Bullet(){


}
 void Bullet:: autoMove(){
rect.translate(xdir, ydir);
}
void Bullet ::clear(){
rect.setRect(-200,-200,20,20);

}
 void Bullet :: resetState(int x, int y){
	rect.moveTo(x,y);

}

QRect Bullet::getRect()
{
  return rect;
}

QImage & Bullet::getImage()
{
  return image;
}
