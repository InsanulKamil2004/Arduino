//Rotate servo motor to 90 deg
void Rotate_Servo_to_60(){
  
  for (pos = 0; pos <= 60; pos=pos+5) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
   servoPulse(servo, pos);            // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position. Increse this value to get slow response.
  }
  
}


//Rotate servo motor from 0 deg to 180 deg
void Rotate_Servo_0_to_180(){
  
  for (pos = 0; pos <= 180; pos++) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
   servoPulse(servo, pos);            // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position. Increse this value to get slow response.
  }
  
}


// Rotate servo motor from 180 deg to 0 deg
void Rotate_Servo_180_to_0(){
   
   for (pos = 180; pos >= 0; pos--) { // goes from 180 degrees to 0 degrees
    servoPulse(servo, pos);               // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position. Increse this value to get slow response.
  }
  
}


void servoPulse (int servo, int angle)
{
 pwm = (angle*11) + 500;      // Convert angle to microseconds
 digitalWrite(servo, HIGH);
 delayMicroseconds(pwm);
 digitalWrite(servo, LOW);
 delay(50);                   // Refresh cycle of servo
}
