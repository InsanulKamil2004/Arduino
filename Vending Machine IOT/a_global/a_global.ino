//Global Variables
#define CUSTOM_SETTINGS
#define INCLUDE_IOT_SHIELD
#define INCLUDE_TERMINAL_SHIELD
#include <OneSheeld.h>
#include <EEPROM.h>
//LCD
#include <LiquidCrystal.h> // includes the LiquidCrystal Library 
LiquidCrystal lcd(45, 46, 47, 48, 49, 50); // Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7) 
//Servo
#include <Servo.h>
Servo fabrikServo;
Servo boxServo;
Servo bottleServo;
int pos;
//button
int buttonfabric = 35;
int buttonbox = 36;
int buttonbottle = 37;
int initbutton = 51;
int buttonPressed;
//led
int ledfabric = 13;
int ledbox = 14;
int ledbottle = 15; 
//pir
int pirSensor = 8;
int val;
//ir sensor
int irsepuluhsen = 30;
int irduapuluhsen = 31;
int irlimapuluhsen = 32;
float x = 0;
float y = 0;
float z = 0;
float h = 0;
int i,j,k;
char float_str[8];
char line0[21];
//buzzer
int buzzer = 15;

//required variables for the publishing function 
char statChar[10];
/* broker instance security details */
const char * host_name = "broker.hivemq.com";
//switch
//...
//switch pin
//...
/* The topics*/
//pir
const char * pir_stat = "pir/stat";
const char * fabric_stat = "fabric/stat";
const char * box_stat = "box/stat";
const char * bottle_stat = "bottle/stat";
const char * status_stat = "status_stat";
/* Define functions prototypes */
void connectionStatus(byte statusCode);
void error(byte errorCode);
