//Void Setup

void setup() 
{
  lcd.begin(16,2);
  lcd.print("test");
 
  Connect();

  pinMode(buttonfabric,INPUT_PULLUP);
  pinMode(buttonbox,INPUT_PULLUP);
  pinMode(buttonbottle,INPUT_PULLUP);
  pinMode(initbutton,INPUT_PULLUP);
  pinMode(pirSensor,INPUT);
  pinMode(irsepuluhsen,INPUT);
  pinMode(irduapuluhsen,INPUT);
  pinMode(irlimapuluhsen,INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(ledfabric,OUTPUT);
  pinMode(ledbox,OUTPUT);
  pinMode(ledbottle,OUTPUT);

  fabrikServo.attach(2);
  boxServo.attach(3);
  bottleServo.attach(4);

  
}
