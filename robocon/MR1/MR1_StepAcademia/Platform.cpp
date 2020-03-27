#include "Platform.h"

Platform::Platform(AbstractMotor *motor1, AbstractMotor *motor2, AbstractMotor *motor3, AbstractMotor *motor4)
{
  this->motor1 = motor1;
  this->motor2 = motor2;
  this->motor3 = motor3;
  this->motor4 = motor4;
}
void Platform::Forward(int spd)
{
  motor1->Forward(spd);
  motor2->Back(spd);
  motor3->Forward(spd);
  motor4->Back(spd);
}
void Platform::Forward(int spd1, int spd2)
{
  motor1->Forward(spd1);
  motor2->Back(spd2);
  motor3->Forward(spd1);
  motor4->Back(spd2);
}
void Platform::Forward(int spd1, int spd2, int spd3, int spd4)
{
  motor1->Forward(spd1);
  motor2->Back(spd2);
  motor3->Forward(spd3);
  motor4->Back(spd4);
}
void Platform::Back(int spd)
{
  motor1->Back(spd);
  motor2->Forward(spd);
  motor3->Back(spd);
  motor4->Forward(spd);
}
void Platform::Back(int spd1, int spd2)
{
  motor1->Back(spd1);
  motor2->Forward(spd2);
  motor3->Back(spd1);
  motor4->Forward(spd2);
}
void Platform::Back(int spd1, int spd2, int spd3, int spd4)
{
  motor1->Back(spd1);
  motor2->Forward(spd2);
  motor3->Back(spd3);
  motor4->Forward(spd4);
}
void Platform::Left(int spd)
{
  motor1->Back(spd);
  motor2->Back(spd);
  motor3->Forward(spd);
  motor4->Forward(spd);
}
void Platform::Left(int spd1, int spd2)
{
  motor1->Back(spd2);
  motor2->Back(spd2);
  motor3->Forward(spd1);
  motor4->Forward(spd1);
}
void Platform::Left(int spd1, int spd2, int spd3, int spd4)
{
  motor1->Back(spd1);
  motor2->Back(spd2);
  motor3->Forward(spd3);
  motor4->Forward(spd4);
}
void Platform::Right(int spd)
{
  motor1->Forward(spd);
  motor2->Forward(spd);
  motor3->Back(spd);
  motor4->Back(spd);
}
void Platform::Right(int spd1, int spd2)
{
  motor1->Forward(spd1);
  motor2->Forward(spd1);
  motor3->Back(spd2);
  motor4->Back(spd2);
}
void Platform::Right(int spd1, int spd2, int spd3, int spd4)
{
  motor1->Forward(spd1);
  motor2->Forward(spd2);
  motor3->Back(spd3);
  motor4->Back(spd4);
}
void Platform::TurnLeft(int spd)
{
  motor1->Back(spd);
  motor2->Back(spd);
  motor3->Back(spd);
  motor4->Back(spd);
}
void Platform::TurnLeft(int spd1, int spd2, int spd3, int spd4)
{
  motor1->Back(spd1);
  motor2->Back(spd2);
  motor3->Back(spd3);
  motor4->Back(spd4);
}
void Platform::TurnRight(int spd)
{
  motor1->Forward(spd);
  motor2->Forward(spd);
  motor3->Forward(spd);
  motor4->Forward(spd);
}
void Platform::TurnRight(int spd1, int spd2, int spd3, int spd4)
{
  motor1->Forward(spd1);
  motor2->Forward(spd2);
  motor3->Forward(spd3);
  motor4->Forward(spd4);
}

void Platform::Go(int spd1, int spd2, int spd3, int spd4)
{
  motor1->Go(spd1);
  motor2->Go(spd2);
  motor3->Go(spd3);
  motor4->Go(spd4);
}

void Platform::Stop()
{
  motor1->Stop();
  motor2->Stop();
  motor3->Stop();
  motor4->Stop();
}
