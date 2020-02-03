#include "dht.h"
#define SENSOR_PIN A0 // Analog Pin sensor is connected to
dht DHT;


#include <DS3231.h>
const int chipSelect = 50;
DS3231  rtc(SDA, SCL);

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3,POSITIVE);//cek lib//rary

const int trigPin = 9;
const int echoPin = 10;
long duration;
int distanceCm, distanceInch;

const int buzzer = 8;

void setup() {

 digitalWrite(buzzer,OUTPUT);
 rtc.begin();
 rtc.setDOW(FRIDAY);     // Set Day-of-Week to SUNDAY
 rtc.setTime(05, 30, 00);     // Set the time to 12:00:00 (24hr format)
 rtc.setDate(30,2,2019);   // Set the date to January 1st, 2014 

 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);

 lcd.begin(16,2);
 delay(2000);
 
}

void loop() {

 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 distanceCm= duration*0.034/2;
 distanceInch = duration*0.0133/2;

 
  
 DHT.read11(SENSOR_PIN);
  
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("**");
 lcd.print(rtc.getDateStr());
 lcd.print("**");
 lcd.setCursor(3,1);
 lcd.print(rtc.getTimeStr());
 delay(8000);
 
 lcd.clear();
 lcd.setCursor(2,0);
 lcd.print("**Suhu= ");
 lcd.print(DHT.temperature);
 lcd.print("**");
 lcd.setCursor(0,1);
 lcd.print("Kelembapan=");
 lcd.print(DHT.humidity);
 delay(8000);
 
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Sea Water Level");
 lcd.setCursor(0,1);
 lcd.print("Distance:");
 lcd.print(distanceCm);
 lcd.print("m");
 delay(8000);
 lcd.clear();

 
 if(distanceCm<5) // bagitau berapa cm nak bagi amaran untuk bunyi
 {
 tone(buzzer, 1000);
 lcd.print("Amaran banjir");
 delay(8000);
 }
 else
 {
 noTone;
 lcd.clear();
 }
 
 lcd.clear();
 
}
