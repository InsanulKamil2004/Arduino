//Void Setup

void setup() 
{
  Connect();

  pinMode(buzzer, OUTPUT);
    
  pinMode(trigPin, OUTPUT);   
  pinMode(echoPin, INPUT); 

  pinMode(trigPin1, OUTPUT);   
  pinMode(echoPin1, INPUT); 

  myservo.attach(6);
  myservo.write(0);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  pinMode(rainSensor,INPUT);


}
