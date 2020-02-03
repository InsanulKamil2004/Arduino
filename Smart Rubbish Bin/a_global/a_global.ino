//HakCipta = Muhammad Insanul Kamil bin Syaidul Azam

//Global Variables

#define CUSTOM_SETTINGS
#define INCLUDE_IOT_SHIELD
#define INCLUDE_TERMINAL_SHIELD
#include <OneSheeld.h>

//led
int led1 = 20;
int led2 = 21;
int led3 = 22;
int led4 = 23;
//buzzer
int buzzer = 3;
//Rain Sensor
int rainSensor = A1;
int rainStat;
//servo
#include <Servo.h>
Servo myservo;
//ultrasonic
const int trigPin = 9;
const int echoPin = 10;
const int trigPin1 = 11;
const int echoPin1 = 12;
int distance;
long duration;
int distanceCm;
int distance1;
long duration1;
int distanceCm1;
//required variables for the publishing function 
char distanceChar[10];
char statChar[10];
/* broker instance security details */
const char * host_name = "broker.hivemq.com";
/* The topics*/
//ultrasonic
const char * ultrasonic_state = "ultrasonic/state";
const char * ultrasonic_distance = "ultrasonic/distance";
const char * ultrasonic_stat = "ultrasonic/stat";
/* Define functions prototypes */
void connectionStatus(byte statusCode);
void error(byte errorCode);
