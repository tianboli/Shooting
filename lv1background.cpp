#include "lv1background.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Lv1back :: Lv1back(){
sunimage.load("sun.png");
backimage.load("wave.png");
sunimage = sunimage.scaled(100,100,Qt::IgnoreAspectRatio,Qt::FastTransformation);
 backimage = backimage.scaled(300,400,Qt::IgnoreAspectRatio,Qt::FastTransformation);
backrect = backimage.rect();
backrect.setRect(-20,-100,500,700);

sunrect = sunimage.rect();
sunrect.setRect(150,200,100,100);
}


Lv1back :: ~Lv1back(){

}

void Lv1back :: resetState(){


}

 QRect Lv1back :: getsunRect(){
	return sunrect;


}
 QRect Lv1back :: getbackRect(){
	return backrect;

}


 QImage &Lv1back :: getsunImage(){
	return sunimage;
}

 QImage &Lv1back :: getbackImage(){
	return backimage;
}


