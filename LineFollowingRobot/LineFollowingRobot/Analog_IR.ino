void Read_Analog_IR() {

  IR_L = analogRead(IR_Left);
  IR_ML = analogRead(IR_Middle_Left);
  IR_MR = analogRead(IR_Middle_Right);
  IR_R = analogRead(IR_Right);

  if(IR_L >= LimitBlackLine){
    sensor_4 = 1;
  }
  else if(IR_L < LimitBlackLine){
    sensor_4 = 0;
  }
  
  if(IR_ML >= LimitBlackLine){
    sensor_3 = 1;
  }
  else if(IR_ML < LimitBlackLine){
    sensor_3 = 0;
  }

  if(IR_MR >= LimitBlackLine){
    sensor_2 = 1;
  }
  else if(IR_MR < LimitBlackLine){
    sensor_2 = 0;
  }

  if(IR_R >= LimitBlackLine){
    sensor_1 = 1;
  }
  else if(IR_R < LimitBlackLine){
    sensor_1 = 0;
  }

}

void Output_IR() {

  Serial.print(IR_L);
  Serial.print("\t");
  Serial.print(IR_ML);
  Serial.print("\t");
  Serial.print(IR_MR);
  Serial.print("\t");
  Serial.print(IR_R);

  Serial.println();

}
