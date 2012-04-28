#include "star.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
Star :: Star(){
  xdir = -5;
  ydir = 5;
  
  starimage.load("star.png");
  
  starimage = starimage.scaled(150,150,Qt::IgnoreAspectRatio,Qt::FastTransformation);
 
  star = starimage.rect();
  star.setRect(200,50,60,60);

}
Star :: ~Star(){


}
 void Star:: autoMove(){

star.translate(xdir,ydir);
if(star.left() <= 150)
xdir = 5;
if(star.right() >= 300)
xdir = -5;
if(star.bottom() >=400)
ydir = -5;
if(star.top() <=0)
xdir = 5;


}
QRect Star::getstar()
{
  return star;
}

QImage & Star::getstarImage()
{
  return starimage;
}

