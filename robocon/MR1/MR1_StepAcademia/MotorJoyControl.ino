#include "Platform.h"

bool Between(int value, int min, int max);
template<typename T>
void Swap(T &value1, T &value2);

void MotorJoyControl(Platform &platform, double X, double Y, double X1, double spdMax, int dir) //Ставить значение -255 до 255
{
  if (Between(X, -10, 10) && Between(Y, -10, 10))
  {
    int spd = map(X1, -255, 255, -spdMax, spdMax);
    if (spd < 0)
      platform.TurnLeft(abs(spd));
    else
      platform.TurnRight(spd);
    return;
  }

  // Конвертирование значений для смены направления
  switch (dir)
  {
    case 2:
      X = map(X, -255, 255, 255, -255);
      Swap(X, Y);
      break;
    case 3:
      X = map(X, -255, 255, 255, -255);
      Y = map(Y, -255, 255, 255, -255);
      break;
    case 4:
      Y = map(Y, -255, 255, 255, -255);
      Swap(X, Y);
      break;
  }

  // Подсчет значений
  double hyp = sqrt(X * X + Y * Y);
  double spd1 = map(hyp, 0, 295, 0, spdMax);
  double spd2;

  // Определение направления джойстика
  int temp;
  if (Between(X, -255, 0) && Between(Y, 0, 255))    // Левый верхний угол
    temp = 0;
  if (Between(X, 1, 255) && Between(Y, -255, 1))    // Правый нижний угол
    temp = 1;
  if (Between(X, 1, 255) && Between(Y, 0, 255))     // Правый верхний угол
    temp = 2;
  if (Between(X, -255, 0) && Between(Y, -255, 1))   // Левый нижний угол
    temp = 3;

  // Выявление скорости для моторов
  double SPD1;
  double SPD2;
  double SPD3;
  double SPD4;
  switch (temp)
  {
    case 0:
      spd2 = map(X + Y, -255, 255, -spdMax, spdMax);
      SPD1 = spd1;
      SPD2 = spd2;
      SPD3 = -spd2;
      SPD4 = -spd1;
      break;
    case 1:
      spd2 = map(X + Y, -255, 255, -spdMax, spdMax);
      SPD1 = -spd1;
      SPD2 = spd2;
      SPD3 = -spd2;
      SPD4 = spd1;
      break;
    case 2:
      spd2 = map(X - Y, -255, 255, -spdMax, spdMax);
      SPD1 = -spd2;
      SPD2 = spd1;
      SPD3 = -spd1;
      SPD4 = spd2;
      break;
    case 3://Вправо
      spd2 = map(X - Y, -255, 255, -spdMax, spdMax);
      SPD1 = -spd2;
      SPD2 = -spd1;
      SPD3 = spd1;
      SPD4 = spd2;
      break;
  }

  int side; // Сторона
  if (SPD1 < 0 && SPD3 < 0 && SPD2 > 0 && SPD4 > 0)
    side = 1; // Вперед

  if (SPD1 > 0 && SPD3 > 0 && SPD2 < 0 && SPD4 < 0)
    side = 2; // Назад

  if (SPD1 < 0 && SPD2 < 0 && SPD3 > 0 && SPD4 > 0)
    side = 3; // Вправо

  if (SPD1 > 0 && SPD2 > 0 && SPD3 < 0 && SPD4 < 0)
    side = 4; // Влево

  
  if (X1 < 0) 
  {
    double percent = 1 - (X1 / -255);
    switch (side)
    {
      case 1:
        SPD2 *= percent;
        SPD4 *= percent;
        break;
      case 2:
        SPD1 *= percent;
        SPD3 *= percent;
        break;
      case 3:
        SPD3 *= percent;
        SPD4 *= percent;
        break;
      case 4:
        SPD1 *= percent;
        SPD2 *= percent;
        break;
    }
  }
  if (X1 > 0)
  {
    double percent = 1 - (X1 / 255);
    switch (side)
    {
      case 1:
        SPD1 *= percent;
        SPD3 *= percent;
        break;
      case 2:
        SPD2 *= percent;
        SPD4 *= percent;
        break;
      case 3:
        SPD1 *= percent;
        SPD2 *= percent;
        break;
      case 4:
        SPD3 *= percent;
        SPD4 *= percent;
        break;
    }
  }

  platform.Go(SPD1, SPD2, SPD3, SPD4);
}

bool Between(int value, int min, int max)
{
  if (value <= max && value >= min)
    return true;
  return false;
}

template<typename T>
void Swap(T &value1, T &value2)
{
  T temp = value1;
  value1 = value2;
  value2 = temp;
}
