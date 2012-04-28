#ifndef StarS_H
#define StarS_H
#include "planets.h"
#include <QImage>
#include <QRect>

class Star : public Planets
{
  public:
    Star();
    ~Star();

  public:
    //void resetState(int,int);
    void autoMove();
	
    QRect getstar();
	
	QImage & getstarImage();
	
  private:
    QImage starimage;
    QRect star;
	int xdir,ydir;
};

#endif
