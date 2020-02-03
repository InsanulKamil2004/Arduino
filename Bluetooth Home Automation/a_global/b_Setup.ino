//Void Setup

void setup() {
  
 pinMode(lampuRuangTamu, OUTPUT);
 pinMode(lampubiliktidur, OUTPUT);
 pinMode(lamputandas, OUTPUT);
 pinMode(kipas, OUTPUT);
 servo.attach(10);
 servo.write(0);
 servo2.attach(11);
 servo2.write(0); 
 servo3.attach(3);
 servo3.write(0);
 
 digitalWrite(lampubiliktidur, LOW);
 digitalWrite(lampuRuangTamu, LOW);
 digitalWrite(kipas, LOW);
 digitalWrite(lamputandas, LOW);
 
 pinMode(rainPin, INPUT);
 Serial.begin(9600); // Default communication rate of the Bluetooth module
}
