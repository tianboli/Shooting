
#include "controller.h"
#include <QPainter>
#include <QApplication>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <QString>
#include <sstream>
#include <iostream>
#include <string>
#include <sstream>

//using namespace std;
Controller::Controller(QWidget *parent)
    : QWidget(parent)
{
sun = new Sun();
star = new Star();
addscore = new Addscore();
 shark = new Shark();
 move = FALSE;
 move1 = FALSE;
power = new Power();
  count = 10;
counter = 100;
	lv2 = FALSE;
lv3 = FALSE;
hp = 100;
  x = 0;
score=0;
  index=0;
  gameOver = FALSE;
  gameWon = FALSE;
  paused = FALSE;
  gameStarted = FALSE;
for(int i =0; i < 100; i++)
  bulletlv2[i] = new Bullet();
for(int i =0; i < 10; i++)
  bullet[i] = new Bullet();
for(int i =0; i < 2; i++)
  ebullets[i] = new EnemyBullet();
  enemy = new Enemy();
planets = new Planets();
  you = new You();
followenemy3= new Enemyshot();
followenemy2 = new Enemyshot();
 followenemy = new Enemyshot();
lv1back = new Lv1back();
for(int i = 0; i< 2;i ++)
  shotenemy[i] = new ShotEnemy();
  int k = 0;
  
    for (int j=0; j<6; j++) {
      
      gates[k] = new Gates(j*40+30, 50);
      k++; 
  }
}

Controller::~Controller() {
 delete you;
 delete enemy;
 for (int i=0; i<6; i++) {
   delete gates[i];
 }
}
int Controller :: restbullets(){

return count;
}
bool Controller :: finished(){

return true;
}

void Controller::paintEvent(QPaintEvent *event)
{
  QPainter painter(this);

  if (gameOver) {
    QFont font("Courier", 15, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.width("Over");

    painter.setFont(font);
    int h = height();
    int w = width();

    painter.translate(QPoint(w/2, h/2));
    painter.drawText(-textWidth/2, 0, "Over");	
	gameOver = FALSE;
  }
else if(gameWon && lv2 && !gameStarted) {
    QFont font("Courier", 15, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.width("Victory, Go to Next Level");

    painter.setFont(font);
    int h = height();
    int w = width();

    painter.translate(QPoint(w/2, h/2));
    painter.drawText(-textWidth/2, 0, "Victory, Go to Next Level");
  }
else if(gameWon && lv3 && !gameStarted) {
    QFont font("Courier", 15, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.width("Victory, Go to Next Level");

    painter.setFont(font);
    int h = height();
    int w = width();

    painter.translate(QPoint(w/2, h/2));
    painter.drawText(-textWidth/2, 0, "Victory, Go to Next Level");
  }
 else if(lv2 && gameStarted)
{

painter.drawImage(planets->getblack(), 
        planets->getblackImage());
painter.drawImage(sun->getsun(), 
        sun->getsunImage());
//add Hp display on the screen
QFont font("Courier", 15, QFont::DemiBold);
    QFontMetrics fm(font);
int textWidth = fm.width("HP: ");
painter.translate(QPoint(0, 10));
 painter.drawText(30-textWidth/2, 0, "HP: ");
QString qstr = QString :: number(hp);
int textWidth2 = fm.width(qstr);
 painter.translate(QPoint(0, 10));
painter.drawText(30-textWidth/2,0, qstr);
//add score display on the screen

int textWidth3 = fm.width("Score: ");
painter.translate(QPoint(0, 10));
 painter.drawText(90-textWidth3/2, -20, "Score: ");
QString qstr2 = QString :: number(score);
int textWidth4 = fm.width(qstr2);
 painter.translate(QPoint(0, 10));
painter.drawText(90-textWidth3/2,-20, qstr2);

//add bullets number on the screen

int textWidth5 = fm.width("Bullets: ");
painter.translate(QPoint(0, 10));
 painter.drawText(150-textWidth5/2, -40, "Bullets: ");
QString qstr3 = QString :: number(counter);
int textWidth6 = fm.width(qstr3);
 painter.translate(QPoint(0, 10));
painter.drawText(150-textWidth5/2,-40, qstr3);

//Move the planets in the background;
 painter.drawImage(planets->getjupiter(), 
        planets->getjupiterImage());
 painter.drawImage(planets->getearth(), 
        planets->getearthImage());
    painter.drawImage(you->getRect(), 
        you->getImage());


//Initiate the following enemy , shooting enemy, bullets
painter.drawImage(followenemy->getenemy(),followenemy->getenemyImage());
painter.drawImage(shotenemy[0]->getenemy(),shotenemy[0]->getenemyImage());
painter.drawImage(shotenemy[1]->getenemy(),shotenemy[1]->getenemyImage());

painter.drawImage(ebullets[0]->getRect(),ebullets[0]->getImage());
painter.drawImage(ebullets[1]->getRect(),ebullets[1]->getImage());

for(int i =0; i < 100; i ++){
painter.drawImage(bulletlv2[i]->getRect(),bulletlv2[i]->getImage());

}
}


//lv33333333333333333333333

else if(lv3 && gameStarted){

painter.drawImage(shark->getbackground(), 
        shark->getbackgroundImage());
//add Hp display on the screen
QFont font("Courier", 15, QFont::DemiBold);
    QFontMetrics fm(font);
int textWidth = fm.width("HP: ");
painter.translate(QPoint(0, 10));
 painter.drawText(30-textWidth/2, 0, "HP: ");
QString qstr = QString :: number(hp);
int textWidth2 = fm.width(qstr);
 painter.translate(QPoint(0, 10));
painter.drawText(30-textWidth/2,0, qstr);
//add score display on the screen

int textWidth3 = fm.width("Score: ");
painter.translate(QPoint(0, 10));
 painter.drawText(90-textWidth3/2, -20, "Score: ");
QString qstr2 = QString :: number(score);
int textWidth4 = fm.width(qstr2);
 painter.translate(QPoint(0, 10));
painter.drawText(90-textWidth3/2,-20, qstr2);

//add bullets number on the screen

int textWidth5 = fm.width("Bullets: ");
painter.translate(QPoint(0, 10));
 painter.drawText(150-textWidth5/2, -40, "Bullets: ");
QString qstr3 = QString :: number(counter);
int textWidth6 = fm.width(qstr3);
 painter.translate(QPoint(0, 10));
painter.drawText(150-textWidth5/2,-40, qstr3);

//Move the planets in the background;


 painter.drawImage(shark->getshark(), 
        shark->getsharkImage());
 painter.drawImage(shark->getfish(), 
        shark->getfishImage());
 painter.drawImage(shark->getfish2(), 
        shark->getfish2Image());
 
painter.drawImage(star->getstar(), 
        star->getstarImage());
painter.drawImage(sun->getsun(), 
        sun->getsunImage());
for(int i =0; i < 100; i ++)
painter.drawImage(bulletlv2[i]->getRect(),bulletlv2[i]->getImage());
    painter.drawImage(you->getRect(), 
        you->getImage());


//Initiate the following enemy , shooting enemy, bullets
painter.drawImage(followenemy->getenemy(),followenemy->getenemyImage());
painter.drawImage(followenemy2->getenemy(),followenemy2->getenemyImage());
painter.drawImage(followenemy3->getenemy(),followenemy3->getenemyImage());
painter.drawImage(shotenemy[0]->getenemy(),shotenemy[0]->getenemyImage());
painter.drawImage(shotenemy[1]->getenemy(),shotenemy[1]->getenemyImage());

painter.drawImage(ebullets[0]->getRect(),ebullets[0]->getImage());
painter.drawImage(ebullets[1]->getRect(),ebullets[1]->getImage());



//Initiate the power items:
painter.drawImage(power->getRect(),power->getImage());

painter.drawImage(addscore->getRect(),addscore->getImage());

}



  else if(!lv2 && !lv3 && gameStarted) {
painter.drawImage(lv1back->getbackRect(),lv1back->getbackImage());
painter.drawImage(lv1back->getsunRect(),lv1back->getsunImage());
    painter.drawImage(enemy->getRect(), 
        enemy->getImage());
   painter.drawImage(enemy->getRect2(), 
        enemy->getImage());
painter.drawImage(enemy->getRect3(), 
        enemy->getImage());
painter.drawImage(enemy->getRect4(), 
        enemy->getImage());
painter.drawImage(enemy->getRect5(), 
        enemy->getImage());
painter.drawImage(enemy->getRect6(), 
        enemy->getImage());
for(int i =0; i < 10; i ++)
painter.drawImage(bullet[i]->getRect(),bullet[i]->getImage());
    painter.drawImage(you->getRect(), 
        you->getImage());

	for(int i = 0; i< 6; i ++)
          painter.drawImage(gates[i]->getRect(), 
              gates[i]->getImage());

//Draw the rest number of the bullets
/*
QFont font("Courier", 15, QFont::DemiBold);
    QFontMetrics fm(font);
int textWidth = fm.width("bullets: ");
painter.translate(QPoint(width()/5, height()/5));
 painter.drawText(-textWidth/2, 0, "bullets: ");
QString qstr = QString :: number(count);
int textWidth2 = fm.width(qstr);
 painter.translate(QPoint(width()/10-10, height()/5-80));
painter.drawText(-textWidth2/2,0, qstr);
*/
QFont font("Courier", 15, QFont::DemiBold);
    QFontMetrics fm(font);
int textWidth5 = fm.width("Bullets: ");
painter.translate(QPoint(0, 10));
 painter.drawText(60-textWidth5/2, 0, "Bullets: ");
QString qstr3 = QString :: number(count);
int textWidth6 = fm.width(qstr3);
 painter.translate(QPoint(0, 10));
painter.drawText(60-textWidth5/2,0, qstr3);
  }
else if(!lv2 && !lv3 && !gameStarted){
QFont font("Courier",8, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.width("Press space to start, P to pause, S to launch");

    painter.setFont(font);
    int h = height();
    int w = width();

    painter.translate(QPoint(w/2, h/2));
    painter.drawText(-textWidth/2, 0, "Press space to start, P to pause, S to launch");

}
}

void Controller::timerEvent(QTimerEvent *event)
{
if(lv2){

planets->autoMove();
followenemy->autoMove(you->getRect().x(),you->getRect().y());
shotenemy[0]->autoMove();
shotenemy[1]->autoMove();
//launch bullets from enemies;
if(shotenemy[0]->getenemy().x() == 90 
|| shotenemy[0]->getenemy().x() == 250 ){
ebullets[0]->resetState(shotenemy[0]->getenemy().x(),shotenemy[0]->getenemy().y());
ebullets[0]->getxandy(you->getRect().x(),you->getRect().y());
move = TRUE;
}
if(move)
ebullets[0]->autoMove();

if(shotenemy[1]->getenemy().x() == 90
|| shotenemy[1]->getenemy().x() == 250 ){
ebullets[1]->resetState(shotenemy[1]->getenemy().left(),shotenemy[1]->getenemy().top());
ebullets[1]->getxandy(you->getRect().x(),you->getRect().y());
move1= TRUE;
}
if(move1)
ebullets[1]->autoMove();


//launch bullets from you
for(int i = 0; i < 100; i++){
  bulletlv2[i]->autoMove();
   if((bulletlv2[i]->getRect()).intersects(shotenemy[0]->getenemy())){
score +=20;
shotenemy[0]->clear();
}
if((bulletlv2[i]->getRect()).intersects(shotenemy[1]->getenemy())){
score +=20;
shotenemy[1]->clear();
}
 if((bulletlv2[i]->getRect()).intersects(followenemy->getenemy())){
score +=50;
followenemy->clear();
}
}

checkCollisionlv2();
}




//lv333333333333333333333333333333333333333333


else if(lv3){
power->autoMove();
addscore->autoMove();
shark->autoMove();
star->autoMove();
sun->autoMove();
followenemy->autoMove(you->getRect().x(),you->getRect().y());
followenemy2->autoMove(you->getRect().x(),you->getRect().y());
followenemy3->autoMove(you->getRect().x(),you->getRect().y());
shotenemy[0]->autoMove();
shotenemy[1]->autoMove();
//launch bullets from enemies;
if(shotenemy[0]->getenemy().x() == 90 
|| shotenemy[0]->getenemy().x() == 250 ){
ebullets[0]->resetState(shotenemy[0]->getenemy().x(),shotenemy[0]->getenemy().y());
ebullets[0]->getxandy(you->getRect().x(),you->getRect().y());
move = TRUE;
}
if(move)
ebullets[0]->autoMove();

if(shotenemy[1]->getenemy().x() == 90
|| shotenemy[1]->getenemy().x() == 250 ){
ebullets[1]->resetState(shotenemy[1]->getenemy().left(),shotenemy[1]->getenemy().top());
ebullets[1]->getxandy(you->getRect().x(),you->getRect().y());
move1= TRUE;
}
if(move1)
ebullets[1]->autoMove();


//launch bullets from you
for(int i = 0; i < 100; i++){
  bulletlv2[i]->autoMove();
   if((bulletlv2[i]->getRect()).intersects(shotenemy[0]->getenemy())){
score +=20;
shotenemy[0]->clear();
}
if((bulletlv2[i]->getRect()).intersects(shotenemy[1]->getenemy())){
score +=20;
shotenemy[1]->clear();
}
 if((bulletlv2[i]->getRect()).intersects(followenemy->getenemy())){
score +=50;
followenemy->clear();
}
if((bulletlv2[i]->getRect()).intersects(followenemy2->getenemy())){
score +=50;
followenemy2->clear();
}
if((bulletlv2[i]->getRect()).intersects(followenemy3->getenemy())){
score +=50;
followenemy3->clear();
}
}
checkCollisionlv3();
}

else if(!lv2 && !lv3) {
  enemy->autoMove();
  for(int i = 0; i < 10; i++)
  bullet[i]->autoMove();
  checkCollision();
}
  repaint();
 
}



void Controller::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Left:
       {  
         int x = you->getRect().x();
       for(int i = 0;i < 4; i++)
          you->moveLeft(x--);
        break;
       }
	case Qt :: Key_S:
	{
	
	if(!lv2 && !lv3){
	bullet[index]->resetState(you->getRect().x(),you->getRect().y());
	index++;
	count--;
}
else{
bulletlv2[index]->resetState(you->getRect().x(),you->getRect().y());
index++;
counter--;
}
}
break;
	case Qt::Key_Down:
        { 
          int y = you->getRect().y();
           for(int i = 0;i <4; i ++)
            you->moveBottom(y++);
        }
        break;
	 case Qt::Key_Up:
        { 
          int y = you->getRect().y();
          for(int i = 0; i< 4; i++)
            you->moveTop(y--);
        }
        break;
    case Qt::Key_Right:
        { 
          int x = you->getRect().x();
           for(int i = 0; i<4; i++)

            you->moveRight(x++);
        }
        break;
    case Qt::Key_P:
        { 
          pauseGame();
        }
        break;
    case Qt::Key_Space:
        {
	
          startGame();
        }
        break;
    case Qt::Key_Escape:
        {
          qApp->exit();
        }
        break;
case Qt::Key_Q:
{
	Level2();

}
break;
 case Qt::Key_A:
        {
          Level3();
        }
        break;
    default:
        QWidget::keyPressEvent(event);
    }
}

void Controller::startGame()
{ 
  if (!gameStarted && !lv2 &&!lv3) {
    enemy->resetState();
    you->resetState();
    gameOver = FALSE; 
    gameWon = FALSE; 
    gameStarted = TRUE;
    timerId = startTimer(10);  
  }
else if(!gameStarted &&lv2 && !lv3) {
    
 you->resetState();
 followenemy->resetState();
shotenemy[0]->resetState(200,200);
shotenemy[1]->resetState(100,50);
for(int i = 0; i < 100; i ++)
bulletlv2[i]->resetState(800,800);
gameStarted = TRUE;
 timerId = startTimer(10);  

}else if(!gameStarted &&lv3) {
    power ->resetState();
	addscore->resetState();
 you->resetState();
 followenemy->resetState();
 followenemy2->resetState();
 followenemy3->resetState();
 
shotenemy[0]->resetState(200,200);
shotenemy[1]->resetState(100,50);
gameStarted = TRUE;
 timerId = startTimer(10);  

}

}
void Controller::pauseGame()
{
  if (paused) {
    timerId = startTimer(10);
    paused = FALSE;
  } else {
    paused = TRUE;
    killTimer(timerId); 
   }
}

void Controller::stopGame()
{
  killTimer(timerId);    
  gameOver = TRUE;      
  gameStarted = FALSE;
  lv2 = FALSE;
	lv3 = FALSE;
	gameWon = FALSE;
}

void Controller::victory()
{
  killTimer(timerId);
  gameWon = TRUE;  
  gameStarted = FALSE;
gameOver = FALSE;
}
void Controller :: Level2(){
killTimer(timerId);
for(int i = 0; i < 10; i++)
	bullet[i]->clear();
gameWon = TRUE;
gameStarted = FALSE;
gameOver = FALSE;
lv2 = TRUE;
lv3 = FALSE;
}
void Controller :: Level3(){
killTimer(timerId);
gameOver = FALSE;
gameWon = TRUE;
gameStarted = FALSE;
lv3 = TRUE;
lv2 = FALSE;

}

void Controller :: checkCollisionlv3(){
if((you->getRect()).intersects(power->getRect())){
hp+=20;
power->resetState();
}
if((you->getRect()).intersects(addscore->getRect())){
score+=20;
addscore->resetState();
}
if(hp <=0||counter==0){
stopGame();
lv3 =FALSE;
}
if((ebullets[0]->getRect()).intersects(you->getRect())){
hp-=20;
ebullets[0]->clear();
}
if((ebullets[1]->getRect()).intersects(you->getRect())){
 hp-=20;
ebullets[1]->clear();
}
if((you->getRect()).intersects(followenemy->getenemy())){
hp-=50;
followenemy->clear();
}
if((you->getRect()).intersects(followenemy2->getenemy())){
hp-=50;
followenemy2->clear();
}
if((you->getRect()).intersects(followenemy3->getenemy())){
hp-=50;
followenemy3->clear();
}

}


void Controller::checkCollisionlv2()
{
if(hp <=0)
stopGame();
if((ebullets[0]->getRect()).intersects(you->getRect())){
hp-=20;
ebullets[0]->clear();
}

if(ebullets[0]->getRect().x() == ebullets[0]->getxofu()
&&ebullets[0]->getRect().y() == ebullets[0]->getyofu() )
ebullets[0]->clear();

if((ebullets[1]->getRect()).intersects(you->getRect())){
 hp-=20;
ebullets[1]->clear();
}
if(ebullets[1]->getRect().x() == ebullets[1]->getxofu()
&&ebullets[1]->getRect().y() == ebullets[1]->getyofu() )
ebullets[1]->clear();
if((you->getRect()).intersects(followenemy->getenemy())){
hp-=50;
followenemy->clear();
}
if(lv2 &&( score > 100))
Level3();

}
void Controller::checkCollision()
{

  if (you->getRect().left()==0 ||you->getRect().right()==300 )
   stopGame(); 

 
    if (you->getRect().top()<=50) {
	
	enemy->clear();
if(!lv2)
	Level2();

}
	if(index >0){
    if((bullet[index-1]->getRect()).intersects(enemy->getRect())||(bullet[index-1]->getRect()).intersects(enemy->getRect2())||
	(bullet[index-1]->getRect()).intersects(enemy->getRect3())||(bullet[index-1]->getRect()).intersects(enemy->getRect4())||
	(bullet[index-1]->getRect()).intersects(enemy->getRect5())||(bullet[index-1]->getRect()).intersects(enemy->getRect6()) ){
	enemy->clear();
	Level2();
}

}
  if ((enemy->getRect()).intersects(you->getRect()) ||(enemy->getRect2()).intersects(you->getRect())
||(enemy->getRect3()).intersects(you->getRect())||(enemy->getRect4()).intersects(you->getRect())||(enemy->getRect5()).intersects(you->getRect())||(enemy->getRect6()).intersects(you->getRect()) )
	stopGame();

    
}
