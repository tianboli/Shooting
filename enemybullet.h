#ifndef EnemyBullet_H
#define EnemyBullet_H

#include <QImage>
#include <QRect>
#include "bullet.h"
class EnemyBullet : public Bullet
{

  public:
    EnemyBullet();
    ~EnemyBullet();

  public:
    void resetState(int,int);
    void autoMove();
    void clear();	
    QRect getRect();
    QImage & getImage();
    void getxandy(int,int);
	int getxofu();
	int getyofu();
  private:
    
    QImage image;
    QRect rect;
	
	int xdir,ydir;
	int xofu,yofu;
};

#endif
