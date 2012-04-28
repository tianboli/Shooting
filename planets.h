#ifndef PLANETS_H
#define PLANETS_H

#include <QImage>
#include <QRect>

class Planets
{

  public:
    Planets();
    ~Planets();

  public:
    //void resetState(int,int);
    void autoMove();
	
    QRect getearth(),getjupiter(),getblack();
	
    QImage & getearthImage();
	QImage & getjupiterImage();
	QImage & getblackImage();
  private:
    QImage blackimage,jupiterimage,earthimage;
    QRect black,earth,jupiter;
	int xdir,ydir;
};

#endif
