#ifndef Enemy_H
#define Enemy_H

#include <QImage>
#include <QRect>

class Enemy
{

  public:
    Enemy();
    ~Enemy();

  public:
    void resetState();
    void moveBottom(int);
    void moveTop(int);
    void moveLeft(int);
    void moveRight(int);
    void autoMove();
    void autoMove2();
    void setXDir(int);
    void setYDir(int);
    int getXDir();
    int getYDir();
    QRect getRect(),getRect2(),getRect3(),getRect4(),getRect5(),getRect6();
    QImage & getImage();
    bool destried();
    void clear();
  private:
    int angle;
    int speed;
    int xdir,xdir2,xdir3,xdir4,xdir5,xdir6;
    int ydir,ydir2,ydir3,ydir4,ydir5,ydir6;
    bool stuck;
    QImage image;
    QRect rect,rect2,rect3,rect4,rect5,rect6; 
    

};

#endif
