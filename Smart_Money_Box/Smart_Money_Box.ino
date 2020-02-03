#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3,POSITIVE);

const int IR1 = 5; //10
const int IR2 = 6; //20
const int IR3 = 7; //50

int IR1stat = 0;
int IR2stat = 0;
int IR3stat = 0;

int x;
int y;
int z;

int button = 8;

void setup() {
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("10     20      50");
  pinMode(IR1,INPUT);
  pinMode(IR2,INPUT);
  pinMode(IR3,INPUT);

}

void loop() {
  IR1stat = digitalRead(IR1);
  IR2stat = digitalRead(IR2);
  IR3stat = digitalRead(IR3);

  if(IR1stat == 1){
    x++;
    lcd.setCursor(0,0);
    lcd.print(x);
  }else{
    lcd.setCursor(0,0);
    lcd.print(x);
  }
  if(IR2stat == 1){
    y++;
    lcd.setCursor(0,0);
    lcd.print(y);
  }else{
    lcd.setCursor(0,0);
    lcd.print(y);
  }
  if(IR3stat ==1){
    z++;
    lcd.setCursor(0,0);
    lcd.print(z);
  }else{
    lcd.setCursor(0,0);
    lcd.print(z);
  }

  

}
