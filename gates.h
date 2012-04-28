#ifndef GATES_H
#define GATES_H

#include <QImage>
#include <QRect>

class Gates
{

  public:
    Gates(int, int);
    ~Gates();

  public:
    void resetState();
    bool isDestroyed();
    void setDestroyed(bool);
    QRect getRect();
    void setRect(QRect);
    QImage & getImage();

  private:
    QImage image;
    QRect rect;
    int position;
    bool destroyed;

};

#endif
