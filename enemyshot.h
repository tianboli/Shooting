#ifndef ENEMYSHOOT_H
#define ENEMYSHOOT_H
#include <QImage>
#include <QRect>
#include "enemy.h"
class Enemyshot : public Enemy
{

  public:
    Enemyshot();
    ~Enemyshot();

  public:
    void resetState();
    void moveBottom(int);
    void moveTop(int);
    void moveLeft(int);
    void moveRight(int);
    void autoMove(int,int);
   
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
