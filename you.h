#ifndef YOU_H
#define YOU_H

#include <QImage>
#include <QRect>

class You
{

  public:
    You();
    ~You();

  public:
    void resetState();
    void moveLeft(int);
    void moveRight(int);
	void moveTop(int);
	void moveBottom(int);
	
    QRect getRect();
    QImage & getImage();

  private:
    QImage image;
    QRect rect;

};

#endif
