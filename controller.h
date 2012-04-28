#ifndef Controller_H
#define Controller_H
#include "star.h"
#include "lv1background.h"
#include "sun.h"
#include "addscore.h"
#include "shark.h"
#include "power.h"
#include "enemy.h"
#include "enemyshot.h"
#include "shotenemy.h"
#include "enemybullet.h"
#include "gates.h"
#include "you.h"
#include "bullet.h"
#include "planets.h"
#include <QWidget>
#include <QKeyEvent>

class Controller : public QWidget
{
  //Q_OBJECT

  public:
    Controller(QWidget *parent = 0);
    ~Controller();

  protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void keyPressEvent(QKeyEvent *event);

    void startGame();
    void pauseGame();
    void stopGame();
    void victory();
    void checkCollision();
    void checkCollisionlv2();
    void checkCollisionlv3();
    bool finished();
	void Level2();
void Level3();
public:
    int restbullets();
  private:
    int hp,score;
    int x,index;
    int timerId;
	Sun *sun;
	Bullet *bullet[10];
	Bullet *bulletlv2[100];
    Enemy *enemy;
    You *you;
	Star *star;
	Addscore *addscore;
    Shark *shark;
    Gates * gates[6];
	Planets *planets;
    Enemyshot *followenemy,*followenemy2,*followenemy3;
    ShotEnemy *shotenemy[2];
    EnemyBullet *ebullets[2];
	Lv1back *lv1back;
    Power *power;
    bool gameOver ;
    bool gameWon ;
    bool gameStarted ;
    bool paused ;
	bool lv2;
	bool lv3;
	bool move ;
bool move1 ;
    int count;
int counter;
};

#endif
