#include <CytronMotor.h>
#include <AccelStepper.h>
#include <Pnevmo.h>
#include <GamePad.h>
#include "Platform.h"

/**********************Platform********************/
#define DIR1 22
#define DIR2 24
#define DIR3 26
#define DIR4 32
#define PWM1 2
#define PWM2 3
#define PWM3 4
#define PWM4 5

CytronMotor *motor1 = new CytronMotor(DIR1,PWM1);
CytronMotor *motor2 = new CytronMotor(DIR2,PWM2);
CytronMotor *motor3 = new CytronMotor(DIR3,PWM3);
CytronMotor *motor4 = new CytronMotor(DIR4,PWM4, false);

Platform platform(motor1,motor2,motor3,motor4);
/**************************************************/

/*******USB Control*******/
USB Usb;
USBHub Hub(&Usb);
HIDUniversal Hid(&Usb);
GamePad JoyEvents;
JoystickReportParser Joy(&JoyEvents);
/*******USB Control*******/

/*************************Pnevmo**********************/
#define PNEVMO1_PIN 34
#define PNEVMO2_PIN 36
#define PNEVMO3_PIN 38
#define PNEVMO4_PIN 40

#define STATE1 true
#define STATE2 true
#define STATE3 true
#define STATE4 true

Pnevmo *pnevmo1 = new Pnevmo(PNEVMO1_PIN, STATE1);
Pnevmo *pnevmo2 = new Pnevmo(PNEVMO2_PIN, STATE2);
Pnevmo *pnevmo3 = new Pnevmo(PNEVMO3_PIN, STATE3);
Pnevmo *pnevmo4 = new Pnevmo(PNEVMO4_PIN, STATE4);
/*****************************************************/
