
void Suis(){
 if (state == '0') {
 digitalWrite(lampuRuangTamu, LOW); // Turn LED OFF
 Serial.println("OFF"); // Send back, to the phone, the String "LED: ON"
 stateled = 0;
 }
 else if (state == '1') {
 digitalWrite(lampuRuangTamu, HIGH);
 stateled = 0;
 } 
 else if(state == '2'){
 digitalWrite(lampubiliktidur,LOW);
 statelampubiliktidur = 2;
 }
 else if(state == '3'){
 digitalWrite(lampubiliktidur,HIGH);
 statelampubiliktidur =2;
 }
 else if(state == '4'){
 digitalWrite(kipas,LOW);
 statekipas = 4;
 }
 else if(state == '5'){
 digitalWrite(kipas,HIGH);
 statekipas =4;
 }
 else if(state == '6'){
 digitalWrite(lamputandas,HIGH);
 statelamputandas =6;
 }
 else if(state == '7'){
 digitalWrite(lamputandas,LOW);
 statelamputandas =6;
 }
 else if(state == '8'){
 for(pos=0;pos<180;pos++)
 {
  servo2.write(pos);
  servo3.write(pos);
 }
 statepintupagar =8;
 }else if(state == '9'){
  for(pos=180;pos>0;pos--)
 {
  servo2.write(pos);
  servo3.write(pos);
 }
 statepintupagar =8;
 }
 int sensorValue = analogRead(rainPin);
 if(sensorValue < 500){
   servo.write(90);
   Serial.print("Ampaian telah ditarik ke dalam kerana hujan");
 }
 else {
   servo.write(0);
   Serial.print("Kerana belum hujan, baju masih dijemur");
  }
 delay(500);
}
