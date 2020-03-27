#include <AbstractMotor.h>

#ifndef Platform_h
#define Platform_h
class Platform
{
    AbstractMotor *motor1;
    AbstractMotor *motor2;
    AbstractMotor *motor3;
    AbstractMotor *motor4;
  public:
    Platform(AbstractMotor *motor1, AbstractMotor *motor2, AbstractMotor *motor3, AbstractMotor *motor4);
    void Forward(int spd);
    void Forward(int spd1, int spd2);
    void Forward(int spd1, int spd2, int spd3, int spd4);
    void Back(int spd);
    void Back(int spd1, int spd2);
    void Back(int spd1, int spd2, int spd3, int spd4);
    void Left(int spd);
    void Left(int spd1, int spd2);
    void Left(int spd1, int spd2, int spd3, int spd4);
    void Right(int spd);
    void Right(int spd1, int spd2);
    void Right(int spd1, int spd2, int spd3, int spd4);
    void TurnLeft(int spd);
    void TurnLeft(int spd1, int spd2, int spd3, int spd4);
    void TurnRight(int spd);
    void TurnRight(int spd1, int spd2, int spd3, int spd4);
    void Go(int spd1, int spd2, int spd3, int spd4);
    void Stop();
};
#endif
