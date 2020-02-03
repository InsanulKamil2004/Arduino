//Loop

void loop()
{
 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("      Push    ");
  lcd.setCursor(0,1);
  lcd.print("button to proceed");

  
  while(true){
    if(digitalRead(initbutton)== LOW){
      break;
    }
  }
  while(h<1.00){
  i= digitalRead(irsepuluhsen);
  j= digitalRead(irduapuluhsen);
  k= digitalRead(irlimapuluhsen);  
  if(i == 0){
    x=x+0.10;
    delay(1000);
  }
  if(j == 0){
    y=y+0.20;
    delay(1000);
  }
  if(k == 0){
    z=z+0.50;
    delay(1000);
  }
  h=x+y+z;
  char float_str[8];
  char line0[21];
  dtostrf(h,4,2,float_str);

  lcd.setCursor(0,0);
  lcd.print("Coin Inserted = ");
  lcd.setCursor(0,1);
  sprintf(line0, float_str);
  lcd.print(float_str);
  lcd.clear();
   if(h>0.90){
    break;
   }
  }
  
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("money sufficent");
    lcd.setCursor(0,1);
    lcd.print("Select your item");
   
    
while (true) {
    if (digitalRead(buttonfabric) == LOW) {
      buttonPressed = 1;
      break;
    }
    if (digitalRead(buttonbox) == LOW) {
      buttonPressed = 2;
      break;
    }
    if (digitalRead(buttonbottle) == LOW) {
      buttonPressed = 3;
      break;
      }
    }
  
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("Please wait....");
  switch (buttonPressed) {                                 
    case 1:   
    //air
    {
      fabrikServo.writeMicroseconds(0);
      delay(2000);
      fabrikServo.write(90);
      boxServo.write(90);
      bottleServo.write(90);
      break;
    }
    case 2:    {                                          //box
      boxServo.writeMicroseconds(0);
      delay(2000);
      boxServo.write(90);
      bottleServo.write(90);
      fabrikServo.write(90);
      break;
    }
    case 3:      {                                      //bottle
      bottleServo.writeMicroseconds(0);
      delay(2000);
      bottleServo.write(90);
      boxServo.write(90);
      fabrikServo.write(90);
      break;
    }
  }
  delay(10);
  lcd.clear(); // Clears the display
  lcd.setCursor(0,0);
  lcd.print("Item delivered!"); // Prints on the LCD
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Thank You!!");
  lcd.setCursor(0,1);
  lcd.print("Please come again!!");
  delay(3000);
  h=0;
  i=0;
  j=0;
  k=0;
  x,y,z=0;
}
