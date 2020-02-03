//New Message

void newMessage(char * incomingTopic, char * payload, byte qos, bool retained)
{
  
 if(!strcmp(fabric_stat,incomingTopic))
  {
    if(!strcmp("buy",payload)){
      fabrikServo.writeMicroseconds(0);         //fabrik
      delay(2000);
      fabrikServo.write(90);
      boxServo.write(90);
      bottleServo.write(90);
    }
  }


    
    if(!strcmp(box_stat,incomingTopic))
  {
    if(!strcmp("buy",payload))
    {
      digitalWrite(masjid,HIGH);
      boxServo.writeMicroseconds(0);        //box
      delay(2000);
      boxServo.write(90);
      bottleServo.write(90);
      fabrikServo.write(90);
    }
  }


  
    if(!strcmp(bottle_stat,incomingTopic))
  {
    if(!strcmp("buy",payload))
    {
      bottleServo.writeMicroseconds(0);     //bottle
      delay(2000);
      bottleServo.write(90);
      boxServo.write(90);
      fabrikServo.write(90);
    }
  }

  
}
 
