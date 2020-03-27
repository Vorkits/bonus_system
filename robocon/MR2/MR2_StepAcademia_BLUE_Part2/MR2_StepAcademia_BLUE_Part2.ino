#include "Objects.h"

DIRECTION dir = FORWARD;
volatile int flag = 1;
int counter = 1000;
double percent = 0.65;
int spd = 100;
int spdSlow = 70;
bool cil = false;
void setup()
{
  FlexiTimer2::set(1, isr);
  FlexiTimer2::start();
  Serial.begin(9600);
  
  robot.DelayBalance(FORWARD, spd, percent, 1500);
}

void loop()
{
  robot.Balance(spd, percent, FORWARD);
  return;
  if (flag == 1 && robot.CrossCheck())
  {
    platform->Stop();
    delay(150);
    robot.AngleTurn(false, spdSlow, 300, 100);
    platform->Stop();
    delay(150);
    robot.DelayBalance(FORWARD, spdSlow, percent, 1000);
    robot.IgnoreCross(3, spd, percent, 100);
    robot.IgnoreCross(1, spdSlow, percent, 0);
    platform->Stop();
    delay(150);
    robot.AngleTurn(false, spdSlow, 300, 100);   
    platform->Stop();
    delay(150);
    while(1)
      robot.Balance(spd, percent, FORWARD);
    platform->Stop();
    delay(150);
    
    
    while(!SEEOBS)
      robot.Balance(spdSlow,percent,dir);
    platform->Stop();
    delay(150);
    pnevmo1->Move();
    delay(500);
    robot.DelayBalance(BACK, spdSlow, percent, 500);
    robot.Balance(spdSlow, percent, BACK);
    robot.IgnoreCross(1, spd, percent, 100);
    robot.AngleTurn(false, spdSlow, 300, 100);   
    platform->Stop();
    delay(150);
    robot.AngleTurn(false, spdSlow, 300, 100);
    dir = FORWARD;   
    platform->Stop();
    delay(150);
    while(!SEECIRCLE)
      robot.Balance(20,0.75,FORWARD);    
    platform->Stop();
    delay(150);
    pnevmo1->Move();
    delay(500);
    armMotor->Go(150);
    flag++;
  }
//  else if (flag == 2 && robot.CrossCheck())
//  {
//    platform->Stop();
//    delay(500);
//    dir = FORWARD;
//    spd = 20;
//    flag++;
//  }
//  else if (flag == 3)
//  {
//    if (SEECIRCLE)
//    {
//      platform->Stop();
//      pnevmo->Move();
//      delay(1000);
//      stepper->moveTo(POS2);
//      delay(300);
//      flag++;
//      spd = 40;
//      dir = BACK;
//    }
//  }
//  else if (flag == 4 && robot.CrossCheck())
//  {
//    robot.CrossBalance(spd * 0.45, 0.75, 0, 5, 2);
//    robot.AngleTurn(true, 23 , 300, 130);
//    dir = LEFT;
//    robot.DelayBalance(dir, spd, 0.25, 800);
//    flag++;
//
//  }
//  else if (flag == 5 && robot.CrossCheck())
//  {
//    platform->Stop();
//    delay(500);
//    robot.AngleTurn(true, 25 , 300, 130);
//    robot.DelayBalance(dir, spd, 0.24, 800);
//    spd *= 0.80;
//    flag++;
//  }
//  else if (flag == 6 && robot.CrossCheck())
//  {
//    while (L2_Line && R2_Line)
//      robot.Balance(spd, 0.25, dir);
//    platform->Stop();
//    delay(500);
//    dir = RIGHT;
//    robot.DelayBalance(dir, spd, 0.30, 1000);
//    pnevmo->Move();
//    spd = 60;
//    flag++;
//  }
//  else if (flag == 7)
//  {
//    stepper->moveTo(POS1);
//    robot.IgnoreCross(2, spd, percent, 100);
//    spd = 40;
//    flag++;
//  }
//  else if (flag == 8 && robot.CrossCheck())
//  {
//    spd = 20;
//    platform->Stop();
//    delay(500);
//    dir = FORWARD;
//    while (!SEECIRCLE)
//    {
//      robot.Balance(spd, percent, dir);
//      if (SEEOBS)
//      {
//        platform->Stop();
//        delay(500);
//        dir = BACK;
//        while (1)
//        {
//          while (!robot.CrossCheck())
//            robot.Balance(spd, percent, dir);
//          platform->Stop();
//          delay(500);
//          spd = 30;
//          dir = RIGHT;
//          robot.DelayBalance(dir, spd, percent, 1000);
//          while (!robot.CrossCheck())
//            robot.Balance(spd, percent, dir);
//          dir = FORWARD;
//          while (!SEECIRCLE)
//            robot.Balance(spd, percent, dir);
//          spd = 20;
//
//          cil = true;
//          break;
//        }
//      }
//    }
//    platform->Stop();
//    delay(500);
//    pnevmo->Move();
//    delay(500);
//    stepper->moveTo(POS3);
//    flag++;
//    dir = BACK;
//
//  }
//  else if (flag == 9 && robot.CrossCheck())
//  {
//    platform->Stop();
//    delay(500);
//    dir = LEFT;
//    spd = 40;
//    robot.DelayBalance(dir, spd, percent, 300);
//    int linesCount = cil ? 3 : 2;
//    robot.IgnoreCross(linesCount, spd, percent, 100);
//    flag++;
//  }
//  else if (flag == 10 && robot.CrossCheck())
//  {
//    platform->Stop();
//    delay(500);
//    spd = 25;
//    dir = FORWARD;
//    while (!SEEOBS)
//      robot.Balance(spd, percent, dir);
//    delay(50);
//    platform->Stop();
//    pnevmo->Move();
//    delay(500);
//    dir = BACK;
//    while (!robot.CrossCheck())
//      robot.Balance(spd, percent, dir);
//    platform->Stop();
//    while (1);
//  }
}
