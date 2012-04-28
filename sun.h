#ifndef SunS_H
#define SunS_H
#include "planets.h"
#include <QImage>
#include <QRect>

class Sun : public Planets
{
  public:
    Sun();
    ~Sun();

  public:
    //void resetState(int,int);
    void autoMove();
	
    QRect getsun();
	
	QImage & getsunImage();
	
  private:
    QImage sunimage;
    QRect sun;
	int xdir,ydir;
};

#endif
