#ifndef OBJECTS_H
#define OBJECTS_H

#include <Datchik.h>
#include <FlexiTimer2.h>
#include <CytronMotor.h>
#include <Pnevmo.h>
#include "Platform.h"
#include "Robot.h"

/*******Platform**********/
#define DIR1 23
#define DIR2 22
#define DIR3 25
#define DIR4 24
#define PWM1 3
#define PWM2 2
#define PWM3 5
#define PWM4 4
CytronMotor *motor1 = new CytronMotor(DIR1, PWM1, false);
CytronMotor *motor2 = new CytronMotor(DIR2, PWM2, false);
CytronMotor *motor3 = new CytronMotor(DIR3, PWM3, false);
CytronMotor *motor4 = new CytronMotor(DIR4, PWM4, false);
CytronMotor *armMotor = new CytronMotor(6, 26);
Platform *platform = new Platform(motor1, motor2, motor3, motor4);
/*******Platform*******/



/*******Pnevmo*********/
#define PNEVMO1_PIN 38
#define PNEVMO2_PIN 29

#define STATE1 false
#define STATE2 false

Pnevmo *pnevmo1 = new Pnevmo(PNEVMO1_PIN, STATE1);
Pnevmo *pnevmo2 = new Pnevmo(PNEVMO2_PIN, STATE2);
/*******Pnevmo*********/



/********************ArmMotor******************/

/*****************************************************/

/***********************Datchiks**********************/

#define L1_PIN 32
#define R1_PIN 30
#define L2_PIN 28
#define R2_PIN 34
#define ARM_SC_PIN 40
#define OBS_SC_PIN 42
#define DSTATE true

Datchik *L1 = new Datchik(L1_PIN, DSTATE);
Datchik *R1 = new Datchik(R1_PIN, DSTATE);
Datchik *L2 = new Datchik(L2_PIN, DSTATE);
Datchik *R2 = new Datchik(R2_PIN, DSTATE);
Datchik *ArmSc = new Datchik(ARM_SC_PIN, false);
Datchik *ObsSc = new Datchik(OBS_SC_PIN, false);
#define SEECIRCLE ArmSc->Pressed()
#define SEEOBS ObsSc->Pressed()
/*****************************************************/

/**********************Robot**************************/
Robot robot(platform, L1, R1, L2, R2);
/*****************************************************/
#endif
