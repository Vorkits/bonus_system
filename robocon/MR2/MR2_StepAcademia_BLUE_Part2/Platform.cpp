#include "Platform.h"

Platform::Platform(AbstractMotor *left1, AbstractMotor *left2,AbstractMotor *right1, AbstractMotor *right2)
{
  this->left1 = left1;
  this->right1 = right1;
  this->left2 = left2;
  this->right2 = right2;
}
void Platform::Forward(int spd)
{
  left1->Forward(spd);
  left2->Forward(spd);
  right1->Forward(spd * 1.05);
  right2->Forward(spd * 1.05);
}
void Platform::Forward(int spd1, int spd2)
{
  left1->Forward(spd1);
  left2->Forward(spd1);
  right1->Forward(spd2 * 1.05);
  right2->Forward(spd2 * 1.05);
}
void Platform::Back(int spd)
{
  left1->Back(spd);
  left2->Back(spd);
  right1->Back(spd * 1.05);
  right2->Back(spd * 1.05);
}
void Platform::Back(int spd1, int spd2)
{
  left1->Back(spd1);
  left2->Back(spd1);
  right1->Back(spd2 * 1.05);
  right2->Back(spd2 * 1.05);
}
void Platform::TurnLeft(int spd)
{
  left1->Back(spd);
  right1->Forward(spd * 1.05);
  left2->Back(spd);
  right2->Forward(spd * 1.05);
}
void Platform::TurnLeft(int spd1, int spd2)
{
  left1->Back(spd1);
  right1->Forward(spd2 * 1.05);
  left2->Back(spd1);
  right2->Forward(spd2 * 1.05);
}
void Platform::TurnRight(int spd)
{
  left1->Forward(spd);
  right1->Back(spd * 1.05);
  left2->Forward(spd);
  right2->Back(spd * 1.05);
}
void Platform::TurnRight(int spd1, int spd2)
{
  left1->Forward(spd1);
  right1->Back(spd2 * 1.05);
  left2->Forward(spd1);
  right2->Back(spd2 * 1.05);
}
void Platform::Stop()
{
  left1->Stop();
  right1->Stop();
  left2->Stop();
  right2->Stop();
}
