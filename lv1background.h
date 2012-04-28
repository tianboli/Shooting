#ifndef LV1_H
#define LV1_H

#include <QImage>
#include <QRect>

class Lv1back
{

  public:
    Lv1back();
    ~Lv1back();

  public:
    void resetState();

    QRect getsunRect(),getbackRect();
    QImage & getsunImage(),&getbackImage();
   
    void clear();
  private:
    QImage sunimage,backimage;
    QRect sunrect,backrect; 
    

};

#endif
