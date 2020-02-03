/*
DRABOT BOT
Author: Dafizal Derawi
Date: 25 March 2017
Task: Line Following Robot 

Copyright (C) 2017 Dafizal Derawi, 
Copyright (C) 2017 Drabot

Training Department, Drabot (www.drabot.com)
Drabot (www.facebook.com/drabot.robotics)
 */



// 1) External library
// ===================


// 2) Define
// =========

// motor
#define Right_Dir    12 // Pin 12 on Arduino is connected to IN3 on L298 Motor Driver
#define Right_Speed  10 // Pin 10 (PWM) on Arduino is connected to ENB on L298 Motor Driver

#define Left_Dir    13 // Pin 7 on Arduino is connected to IN1 on L298 Motor Driver
#define Left_Speed  11 // Pin 6 (PWM) on Arduino is connected to ENA on L298 Motor Driver

// IR sensors
#define IR_Left A0          // IR left module is connected to A0 pin on Arduino
#define IR_Middle_Left A1   // IR middle left module is connected to A1 pin on Arduino
#define IR_Middle_Right A2  // IR middle right module is connected to A2 pin on Arduino
#define IR_Right A3         // IR right module is connected to A3 pin on Arduino


// 3) Global Variables
// ===================

// Nominal motor speed
// Adjust your nominal speed here based on experiment. 
// Normally, each motor has different speed because different motor has different efficiency.
int nom_Rspeed = 100; // Nominal right motor speed
int nom_Lspeed = 100+10; // Nominal left motor speed

int IR_L = 0;
int IR_ML = 0;
int IR_MR = 0;
int IR_R = 0;

int sensor_4 = 0;
int sensor_3 = 0;
int sensor_2 = 0;
int sensor_1 = 0;

int LimitBlackLine = 150;

int a; 

int pos = 0;    // variable to store the servo position
int servo = 9;
int angle;
int pwm;

// 4) Extra
// ========


// 5) Void Setup (Initialization)
// ==============================
// the setup function runs once when you press reset or power the board 

void setup() {
  // put your setup code here, to run once:

  pinMode(Right_Dir, OUTPUT);  //Initialize pin 12 as an DIGITAL OUTPUT pin
  pinMode(Left_Dir, OUTPUT); //Initialize pin 7 as an DIGITAL OUTPUT pin

  Serial.begin(9600); // Setup serial communication
  pinMode(servo, OUTPUT); // set servo pin (pin 9) as an OUTPUT pin

  Rotate_Servo_to_60();
  delay(5000);
  // wait for 10 seconds before start
  Stop();
  delay(5000);
  

}


// 6) Void Loop (Main Algorithm)
// =============================

void loop() {

  Read_Analog_IR();  
  Output_IR();  
  linefollowing();
  
}
