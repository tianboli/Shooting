#ifndef SHOTENMY_H
#define SHOTENMY_H
#include <QImage>
#include <QRect>
#include "enemy.h"
class ShotEnemy : public Enemy
{

  public:
    ShotEnemy();
    ~ShotEnemy();

  public:
    void resetState(int,int);
    void moveBottom(int);
    void moveTop(int);
    void moveLeft(int);
    void moveRight(int);
    void autoMove();
    
    void setXDir(int);
    void setYDir(int);
    int getXDir();
    int getYDir();
    QRect getenemy();
    QImage & getenemyImage();
    void  setdestried();
    void clear();
  private:
    int angle;
    int speed;
    int xdir;
    int ydir;
    bool destroied;
    QImage enemyimage;
    QRect enemyrect; 
    

};

#endif
