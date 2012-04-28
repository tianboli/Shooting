#ifndef Power_H
#define Power_H

#include <QImage>
#include <QRect>

class Power
{

  public:
    Power();
    ~Power();

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
    QRect getRect();
    QImage & getImage();
   
    void clear();
  private:
    int angle;
    int speed;
    int xdir;
    int ydir;
    bool stuck;
    QImage image;
    QRect rect; 
    

};

#endif
