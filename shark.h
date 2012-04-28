#ifndef SharkS_H
#define sharkS_H
#include "planets.h"
#include <QImage>
#include <QRect>

class Shark : public Planets
{
  public:
    Shark();
    ~Shark();

  public:
    //void resetState(int,int);
    void autoMove();
	
    QRect getshark(),getfish(),getbackground(),getfish2();
	
    QImage & getfishImage(),&getfish2Image();
	QImage & getsharkImage();
	QImage & getbackgroundImage();
  private:
    QImage sharkimage,backgroundimage,fishimage;
    QRect background,shark,fish,fish2;
	int xdir,ydir;
};

#endif
