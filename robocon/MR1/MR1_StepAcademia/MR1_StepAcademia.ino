#include "Objects.h"

/*********Commands*******/
#define SPDRATE 10
#define SPDSTART 200 
#define SPDMAX 250
#define SPDMIN 50
int spd  = SPDSTART;
/************************/

void setup()
{
  Usb.Init();

  delay(200);
  Hid.SetReportParser(0, &Joy);
  delay(500);
}

void loop()
{
  Usb.Task();

  if (JoyEvents.HAT_Released(R1))
    spd = spd >= SPDMAX ? spd : spd + SPDRATE;
  if (JoyEvents.HAT_Released(L1))
    spd = spd <= SPDMIN ? spd : spd - SPDRATE;

  if (JoyEvents.EventHappened() && JoyEvents.Event() == BUTTON_RELEASED)
  {
    if (JoyEvents.CurrentButton() != X && JoyEvents.CurrentButton() != Y && JoyEvents.CurrentButton() != B && JoyEvents.CurrentButton() != A)
      platform.Stop();
  }

  if (JoyEvents.X_Released())
    pnevmo1->Move();
  if (JoyEvents.Y_Released())
    pnevmo2->Move();
  if (JoyEvents.B_Released())
    pnevmo3->Move();
  if (JoyEvents.A_Released())
    pnevmo4->Move();

  if (JoyEvents.Joystick_Changed())
  {
    double X = map(JoyEvents.X_Pos(), 0, 255, -255, 255);
    double Y = map(JoyEvents.Y_Pos(), 0, 255, 255, -255);
    double X1 = map(JoyEvents.X1_Pos(), 0, 255, -255, 255);
    MotorJoyControl(platform, X, Y, X1, spd, 4);
  }
}
