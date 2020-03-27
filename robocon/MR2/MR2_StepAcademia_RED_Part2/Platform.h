#include <AbstractMotor.h>


#ifndef PLATFORM_H
#define PLATFORM_H
class Platform
{
  private:
    AbstractMotor *left1;
    AbstractMotor *right1;
    AbstractMotor *left2;
    AbstractMotor *right2;
    
  public:
    Platform(AbstractMotor *left1, AbstractMotor *left2,AbstractMotor *right1, AbstractMotor *right2);
    void Forward(int spd);
    void Forward(int spd1,int spd2);
    void Back(int spd);
    void Back(int spd1,int spd2);
    void TurnLeft(int spd);
    void TurnLeft(int spd1, int spd2);
    void TurnRight(int spd);
    void TurnRight(int spd1, int spd2);
    void Stop();
};
#endif
