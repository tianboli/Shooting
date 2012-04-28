#ifndef BULLET_H
#define BULLET_H

#include <QImage>
#include <QRect>

class Bullet
{

  public:
    Bullet();
    ~Bullet();

  public:
    void resetState(int,int);
    void autoMove();
    void clear();	
    QRect getRect();
    QImage & getImage();

  private:
    QImage image;
    QRect rect;
	int xdir,ydir;
};

#endif
