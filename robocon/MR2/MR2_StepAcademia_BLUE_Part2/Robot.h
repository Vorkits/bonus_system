#include "Datchik.h"
#include "Platform.h"

#ifndef ROBOT_H
#define ROBOT_H

enum DIRECTION
{
  FORWARD,
  BACK 
};

class Robot
{
    double spdLeft, spdRight;
    DIRECTION Dir;
    Platform *platform;
    Datchik *L1;
    Datchik *R1;
    Datchik *L2;
    Datchik *R2;

#define L1_Line L1->Pressed()
#define R1_Line R1->Pressed()
#define L2_Line L2->Pressed()
#define R2_Line R2->Pressed()

  public:
    Robot(Platform *platform, Datchik *L1, Datchik *R1, Datchik *L2, Datchik *R2);
    void Balance(double spd, double percent, DIRECTION dir);
    bool CrossCheck();
    DIRECTION DirReverse(DIRECTION dir);
    void AngleTurn(bool left, double spd, int timer, int timer2);
    void DelayBalance(DIRECTION dir, double spd, double percent, int timer);
    void IgnoreCross(int count, double spd, double percent, int counter);
    void ScannerCheck();
    void MotorCheck(int spd, bool left);
    void Update(int timer = 1);
    DIRECTION getDir(){return Dir;}    
};
#endif
