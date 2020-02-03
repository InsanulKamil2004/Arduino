// Check Rain Sensor

void CheckRainSensor(){
  rainStat = analogRead(rainSensor);
  if(rainStat < 500){
    tone(buzzer,600);
    delay(3000);
     tone(buzzer,400);
    delay(3000);
    noTone(buzzer);
  }else{
    noTone(buzzer);
  }
}
