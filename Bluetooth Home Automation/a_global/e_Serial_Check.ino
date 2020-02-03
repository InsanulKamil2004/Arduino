
void serialCheck(){
if(Serial.available() > 0)
 state = Serial.read();
}
