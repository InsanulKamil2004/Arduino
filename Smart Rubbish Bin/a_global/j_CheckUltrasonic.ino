//Check Ultrasonic

void Checkultrasonic(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration*0.034/2;
  
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distanceCm1 = duration1*0.034/2;
  
  itoa(distanceCm1,distanceChar,10);
  IOT.publish(ultrasonic_distance,distanceChar,QOS_0);
  
  if(distanceCm < 100){
    myservo.write(150);
    delay(5000);

    myservo.write(0);
  }
  
  if(distanceCm1 < 5){
    myservo.write(0);
    IOT.publish(ultrasonic_stat,"FULL",QOS_0);
  }
  if(distanceCm1 > 5){
    myservo.write(0);
    IOT.publish(ultrasonic_stat,"EMPTY",QOS_0);
  }
}
