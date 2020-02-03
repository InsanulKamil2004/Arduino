#define CUSTOM_SETTINGS
#define INCLUDE_IOT_SHIELD
#define INCLUDE_TERMINAL_SHIELD
#include <OneSheeld.h>

//ir sensor
const int ir1= 14;
const int ir2= 15;
const int ir3= 16;
int ir1input;
int ir2input;
int ir3input;
//servo
#include <Servo.h>
Servo myservo;
//lcd
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
//rtc
#include <DS3231.h>
DS3231  rtc(SDA, SCL);
int masa;
int tarikh;
//dht
#include <dht.h>
#define SENSOR_PIN  A1
dht DHT;
int temp;
int hum;
//ultrasonic
const int trigPin = 9;
const int echoPin = 10;
int distance;
long duration;
int distanceCm;
//rain sensor
int rainPin = A0;
int Raining;
int Sunny;
//required variables for the publishing function 
char tempChar[4];
char humChar[4];
char distanceChar[4];
char statChar[10];
char timeChar[10];
char dateChar[10];
char ir1Char[3];
char ir2Char[3];
char ir3Char{3};
//required variables fot the smart parking system
int y=0; 
const int place[]={4,3,2};
byte val[6];
const int in    =7;
const int out   =6;
int count=0;
int valin=0;
int valout=0;
int pos = 0; 
int cnt;
//switch pin
int pusatPentadbiran=30;
int sekolah=31;
int masjid=32;
int stadium=33;
int nodelampu=34;
int nodemotor=35;
//millis(); requirement
int interval=1000;//berapa lama nak delay
unsigned long previousMillis=0;//// Tracks the time since last event fired
 
/* broker instance security details */
const char * host_name = "broker.hivemq.com";

/* The topics*/
//rtc
const char * rtc_state = "rtc/state";
const char * rtc_time = "rtc/time";
const char * rtc_date = "rtc/date";
//dht
const char * sensor_state = "sensor/state";
const char * sensor_operate_temp = "sensor/operate/temp";
const char * sensor_operate_hum = "sensor/operate/hum";
//ultrasonic
const char * ultrasonic_state = "ultrasonic/state";
const char * ultrasonic_distance = "ultrasonic/distance";
//rain sensor
const char * rainsensor_state = "rainsensor/state";
const char * rainsensor_stat = "rainsensor/stat";
//switch
const char * lampu_stat = "lampu/stat";
const char * lampu_pusat_pentadbiran = "lampu/pusat/pentadbiran";
const char * lampu_sekolah = "lampu/sekolah";
const char * lampu_masjid = "lampu/masjid";
const char * lampu_stadium = "lampu/stadium";
const char * lampu_node = "lampu/node";
const char * motor_node = "motor/node";
//irsensor
const char * ir1_stat = "ir1/stat";
const char * ir2_stat = "ir2/stat";
const char * ir3_stat = "ir3/stat";
/* Define functions prototypes */
void connectionStatus(byte statusCode);
void error(byte errorCode);


 
void setup() 
{
  Connect();
  
  DeclareIrSensor();

  pinMode(pusatPentadbiran,OUTPUT);
  pinMode(sekolah,OUTPUT);
  pinMode(masjid,OUTPUT);
  pinMode(stadium,OUTPUT);
  pinMode(nodelampu,OUTPUT);
  pinMode(nodemotor,OUTPUT);


  rtc.begin();
  
  pinMode(trigPin, OUTPUT);   
  pinMode(echoPin, INPUT); 

  pinMode(rainPin,INPUT);
  delay(3000);
  InitializeSmartParkingSystem();

  Subscribe();
  Publish(); 
}

void Connect()
 { 
  
  OneSheeld.begin();
  IOT.disconnect();
  IOT.resetConnectionParametersToDefaults();
  IOT.connect(host_name);
  IOT.setOnNewMessage(&newMessage);
  IOT.setOnConnectionStatusChange(&connectionStatus);
  IOT.setOnError(&error);
  delay(3000);
  Subscribe();
  Publish(); 
  
 }
 
void Subscribe()
{
  IOT.subscribe(lampu_pusat_pentadbiran);
    IOT.subscribe(lampu_sekolah);
      IOT.subscribe(lampu_masjid);
        IOT.subscribe(lampu_node);
          IOT.subscribe(lampu_stadium);
            IOT.subscribe(motor_node);
}
void Publish()
{
  
  IOT.publish(lampu_stat,"ready",QOS_0);
  IOT.publish(sensor_state,"ready",QOS_0);
  IOT.publish(ultrasonic_state,"ready",QOS_0);
  IOT.publish(rainsensor_state,"ready",QOS_0);
  IOT.publish(rtc_state,"ready",QOS_0);
}
void InitializeSmartParkingSystem()
{
  for(int i=0;i<3;i++)
     {pinMode(place[i], INPUT);}  
     
  pinMode(in, INPUT);
  pinMode(out, INPUT);
  
  myservo.attach(5); 
  
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Kami Mesti Win!!");
  
  myservo.write(0);
  
  for (pos = 0; pos <= 40; pos += 1) { 
    myservo.write(pos);              
    delay(30);                       
  }
  delay(1000);
  for (pos = 40; pos >= 0; pos -= 1) { 
    myservo.write(pos);             
    delay(30);                       
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  count=0;
}
void SmartParkingSystem() 
{
 //******************************************************* 
  lcd.setCursor(0, 0);
  lcd.print("P-L:");
  lcd.setCursor(0, 1);
  for( y=0;y<3;y++)
     {      
      val[y]=digitalRead(place[y]);
      if(val[y]==1){lcd.print(y+1);}            
      }
       
      lcd.print("       ");        
  valin=digitalRead(in);
  valout=digitalRead(out);
 
  if(count>=3){count=3;myservo.write(0);delay(1000);myservo.detach();
              lcd.setCursor(5, 1);
              lcd.print("       full");}
  
 //******************************************************** 
  if(valout==LOW){
    
 
    for (pos = 0; pos <= 40; pos += 1) { myservo.write(pos);delay(30);}
    
        while(valout==LOW){valout=digitalRead(out);}
        count++;
               
        if(count<4){ }
        
    delay(1000);     
    for (pos = 40; pos >= 0; pos -= 1) { myservo.write(pos);delay(30);}
       }
//********************************************************       
  if(valin ==LOW){
    
  myservo.attach(5);   
  for (pos = 0; pos <= 40; pos += 1) { myservo.write(pos);delay(30);}
  
        while(valin ==LOW){valin=digitalRead(in);}
        count--;
        
        if(count<=0){count=0;}
        
  delay(1000);      
  for (pos = 40; pos >= 0; pos -= 1) { myservo.write(pos);delay(30);}        
        }
//********************************************************        
  lcd.setCursor(10, 1);
  lcd.print(" cnt:");
  lcd.print(count);  
  if(count>=3){
    lcd.setCursor(5, 1);lcd.print("       full   ");
    }
}
void DeclareIrSensor()
{
  pinMode(ir1,INPUT);
  pinMode(ir2,INPUT);
  pinMode(ir3,INPUT);
}
 
void loop()
{
  if(!IOT.isConnected())
  {
    Connect();
  }
  SmartParkingSystem();
  CheckUltrasonic();
  CheckDht();
  CheckRain();
}
 
void newMessage(char * incomingTopic, char * payload, byte qos, bool retained)
{
  if(!strcmp(lampu_pusat_pentadbiran,incomingTopic))
  {
    if(!strcmp("on",payload))
    {
      digitalWrite(pusatPentadbiran,HIGH);
    }
     else if(!strcmp("off",payload))
    {
      digitalWrite(pusatPentadbiran,LOW);
    }
  }

  if(!strcmp(lampu_sekolah,incomingTopic))
  {
    if(!strcmp("on",payload))
    {
      digitalWrite(sekolah,HIGH);
    }
     else if(!strcmp("off",payload))
    {
      digitalWrite(sekolah,LOW);
    }
  }

  if(!strcmp(lampu_masjid,incomingTopic))
  {
    if(!strcmp("on",payload))
    {
      digitalWrite(masjid,HIGH);
    }
     else if(!strcmp("off",payload))
    {
      digitalWrite(masjid,LOW);
    }
  }

  if(!strcmp(lampu_stadium,incomingTopic))
  {
    if(!strcmp("on",payload))
    {
      digitalWrite(stadium,HIGH);
    }
     else if(!strcmp("off",payload))
    {
      digitalWrite(stadium,LOW);
    }
  }

  
  if(!strcmp(lampu_node,incomingTopic))
  {
    if(!strcmp("on",payload))
    {
      digitalWrite(nodelampu,HIGH);
    }
     else if(!strcmp("off",payload))
    {
      digitalWrite(nodelampu,LOW);
    }
  }

  
  if(!strcmp(motor_node,incomingTopic))
  {
    if(!strcmp("on",payload))
    {
      digitalWrite(nodemotor,HIGH);
    }
     else if(!strcmp("off",payload))
    {
      digitalWrite(nodemotor,LOW);
    }
  }
}
 
void connectionStatus(byte statusCode)
{
  /* Check connection code and display. */
  switch(statusCode)
  {
    case CONNECTION_SUCCESSFUL: Terminal.println("CONNECTION_SUCCESSFUL");break;
    case CONNECTION_FAILED: Terminal.println("CONNECTION_FAILED");break;
    case CONNECTION_LOST: Terminal.println("CONNECTION_LOST");break;
    case CONNECTION_LOST_RECONNECTING: Terminal.println("CONNECTION_LOST_RECONNECTING");break;
    case NOT_CONNECTED_YET:  Terminal.println("NOT_CONNECTED_YET");break;
    case MISSING_HOST: Terminal.println("MISSING_HOST");break;
  }
}
 
void error(byte errorCode)
{
  /* Check error code and display. */
  switch(errorCode)
  {
    case CONNECTION_REFUSED                    : Terminal.println("CONNECTION_REFUSED");break;
    case ILLEGAL_MESSAGE_RECEIVED              : Terminal.println("ILLEGAL_MESSAGE_RECEIVED");break;
    case DROPPING_OUT_GOING_MESSAGE            : Terminal.println("DROPPING_OUT_GOING_MESSAGE");break;
    case ENCODER_NOT_READY                     : Terminal.println("ENCODER_NOT_READY");break;
    case INVALID_CONNACK_RECEIVED              : Terminal.println("INVALID_CONNACK_RECEIVED");break;
    case NO_CONNACK_RECEIVED                   : Terminal.println("NO_CONNACK_RECEIVED");break;
    case CONNACK_UNACCEPTABLEP_ROTOCOLVERSION  : Terminal.println("CONNACK_UNACCEPTABLEP_ROTOCOLVERSION");break;
    case CONNACK_IDENTIFIER_REJECTED           : Terminal.println("CONNACK_IDENTIFIER_REJECTED");break;
    case CONNACK_SERVER_UNAVAILABLE            : Terminal.println("CONNACK_SERVER_UNAVAILABLE");break;
    case CONNACK_AUTHENTICATION_FAILED         : Terminal.println("CONNACK_AUTHENTICATION_FAILED");break;
    case CONNACK_NOT_AUTHORIZED                : Terminal.println("CONNACK_NOT_AUTHORIZED");break;
    case CONNACK_RESERVED                      : Terminal.println("CONNACK_RESERVED");break;
  }
} 

 void CheckUltrasonic(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration*0.034/2;

  itoa(distanceCm,distanceChar,10);

  IOT.publish(ultrasonic_distance,distanceChar,QOS_0);
}
void CheckDht()
{

  DHT.read11(SENSOR_PIN);
 
  hum = (int)DHT.humidity;
  temp = (int)DHT.temperature;

  itoa(temp, tempChar, 10);
  itoa(hum, humChar, 10);

  IOT.publish(sensor_operate_temp,tempChar,QOS_0);
  IOT.publish(sensor_operate_hum,humChar,QOS_0);
}
void CheckRain()
{
  int sensorValue = analogRead(rainPin);
  if(sensorValue<600){
      IOT.publish(rainsensor_stat,"Raining",QOS_0);
  }
  else{
    IOT.publish(rainsensor_stat,"Sunny",QOS_0);
  }
}  

void CheckTime()
{
  masa = rtc.getTimeStr();
  tarikh = rtc.getDateStr();

  itoa(masa,timeChar,10);
  itoa(tarikh,dateChar,10);
  
  IOT.publish(rtc_time,timeChar,QOS_0);
  IOT.publish(rtc_date,dateChar,QOS_0);
}

void CheckIr()
{
  ir1input = digitalRead(ir1);
  ir2input = digitalRead(ir2);
  ir3input = digitalRead(ir3);

  if(ir1input == 1)
  {
   IOT.publish(ir1_stat,"Tong Sampah 1 penuh. Sila kutip",QOS_0);
  }else{
    IOT.publish(ir1_stat,"Tong Sampah 1 masih belum penuh.",QOS_0);
  }
  if(ir2input ==1){
   IOT.publish(ir2_stat,"Tong Sampah 2 penuh. Sila kutip",QOS_0);
  }else{
    IOT.publish(ir2_stat,"Tong Sampah 2 masih belum penuh",QOS_0);
  }
   if(ir3input ==1){
   IOT.publish(ir3_stat,"Tong Sampah 3 penuh. Sila kutip",QOS_0);
  }else{
    IOT.publish(ir3_stat,"Tong Sampah 3 masih belum penuh",QOS_0);
  } 
}

