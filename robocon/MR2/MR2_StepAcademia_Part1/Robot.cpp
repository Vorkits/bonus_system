#include "Robot.h"

Robot::Robot(Platform *platform, Datchik *L1, Datchik *R1, Datchik *L2, Datchik *R2)
{
  this->platform = platform;
  this->L1 = L1;
  this->R1 = R1;
  this->L2 = L2;
  this->R2 = R2;
  this->Dir = 0;
}
void Robot::Balance(double spd, double percent, DIRECTION dir)
{
  int max_spd = spd;
  int min_spd = spd * percent;
  this->Dir = dir;
  if (dir == FORWARD)
  {
    if (!L1_Line && !R1_Line)
      platform->Forward(max_spd);
    else if (L1_Line && !R1_Line)
      platform->Forward(min_spd, max_spd);
    else if (!L1_Line && R1_Line)
      platform->Forward(max_spd, min_spd);
  }
  else if (dir == BACK)
  {
    if (!L1_Line && !R1_Line)
      platform->Back(max_spd);
    else if (L1_Line && !R1_Line)
      platform->Back(min_spd, max_spd);
    else if (!L1_Line && R1_Line)
      platform->Forward(max_spd, min_spd);
  }
}

bool Robot::CrossCheck()
{
  return (R2_Line || L2_Line);
}

DIRECTION Robot::DirReverse(DIRECTION dir)
{
  if (dir == BACK)
    return FORWARD;
  else if (dir == FORWARD)
    return BACK;
}

void Robot::AngleTurn(bool left, double spd, int timer, int timer2)
{
  if (left)
    platform->TurnLeft(spd);
  else
    platform->TurnRight(spd);
  delay(timer);

  bool flag = false;
  while (1)
  {
    if (!left)
    {
      platform->TurnRight(spd);
      if (R1_Line)
        flag = true;
    }
    else
    {
      platform->TurnLeft(spd);
      if (L1_Line)
        flag = true;
    }

    if (flag == true)
    {
      platform->Stop();
      delay(timer);
      flag = false;

      if (left)
        platform->TurnRight(30);
      else
        platform->TurnLeft(30);
      delay(timer2);
      break;
    }
  }
}

void Robot::DelayBalance(DIRECTION dir, double spd, double percent, int timer)
{
  while (timer > 0)
  {
    Balance(spd, percent, dir);
    timer--;
    delay(1);
  }
}

void Robot::IgnoreCross(int count, double spd, double percent, int counter)
{
  while (count > 0)
  {
    Balance(spd, percent, Dir);
    if (CrossCheck())
    {
      DelayBalance(Dir, spd, percent, counter);
      count--;
    }
  }
}

void Robot::ScannerCheck()
{
  Serial.print("L1: ");
  Serial.print(L1_Line);
  Serial.print("\tR1: ");
  Serial.print(R1_Line);
  Serial.print("\tL2: ");
  Serial.print(L2_Line);
  Serial.print("\tR2: ");
  Serial.println(R2_Line);
}

void Robot::MotorCheck(int spd, bool left)
{
  if (left)
    platform->Forward(spd, 0);
  else
    platform->Forward(0, spd);
}

void Robot::Update(int timer)
{
  L1->Update(timer);
  R1->Update(timer);
  L2->Update(timer);
  R2->Update(timer);
}
