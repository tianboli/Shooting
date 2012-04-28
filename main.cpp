#include "controller.h"
#include <QDesktopWidget>
#include <QApplication>
#include <QString>
#include <QTextStream>
#include <QLabel>
#include <QLayout>
 #include <QBoxLayout>
 #include <QHBoxLayout>


void center(QWidget &widget, QString qStr)
{
  int x, y;
  int sWidth;
  int sHeight;

  int WIDTH = 300;
  int HEIGHT = 400;
 
  
  QDesktopWidget *desktop = QApplication::desktop();
  
  
  sWidth = desktop->width();
  sHeight = desktop->height();


  x = (sWidth - WIDTH) / 2;
  y = (sHeight - HEIGHT) / 2;

  widget.setGeometry(x, y, WIDTH, HEIGHT);
  widget.setFixedSize(WIDTH, HEIGHT);
  
}


int main(int argc, char *argv[])
{

	
  QApplication app(argc, argv);  
  
  Controller window;
  QString qStr = QString::number(window.restbullets()-1);
  
  window.setWindowTitle("Shooting");
  window.show();
  center(window,qStr);

  return app.exec();
}


