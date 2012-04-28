#include "sun.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
Sun :: Sun(){
  xdir = -4;
  ydir = 0;
  
  sunimage.load("sun.png");
  
  sunimage = sunimage.scaled(60,60,Qt::IgnoreAspectRatio,Qt::FastTransformation);
 
  sun = sunimage.rect();
  sun.setRect(50,250,60,60);

}
Sun :: ~Sun(){


}
 void Sun:: autoMove(){

sun.translate(xdir,ydir);
if(sun.left() <= 0)
xdir = 4;
if(sun.right() >= 300)
xdir = -4;



}
QRect Sun::getsun()
{
  return sun;
}

QImage & Sun::getsunImage()
{
  return sunimage;
}

