void Stop() 
{
  analogWrite(Left_Speed,0);
  analogWrite(Right_Speed,0);
}

void Forward()
{
  Left_Forward(); // CCW
  Right_Forward(); // CW
}

void Reverse() 
{
  Left_Reverse(); // CW
  Right_Reverse(); // CCW
}

void Turn_Left() 
{
  Left_Reverse(); // CW
  Right_Forward(); // CW 
}

void Turn_Right() 
{
  Left_Forward(); // CCW
  Right_Reverse(); // CCW
}

void Turn_Left_Slight() 
{
  Left_Forward();
  Right_Forward();
}

void Turn_Right_Slight() 
{
  Left_Forward();
  Right_Forward();
}

void Reverse_Left_Slight() 
{
  Left_Reverse();
  Right_Reverse();
}

void Reverse_Right_Slight() 
{
  Left_Reverse();
  Right_Reverse();
}


//======================================

void Left_Forward() // CCW
{
  digitalWrite(Left_Dir, HIGH);
}

void Left_Reverse() // CW
{
  digitalWrite(Left_Dir, LOW);
}

void Right_Forward() //CW
{
  digitalWrite(Right_Dir, LOW);
}

void Right_Reverse() // CCW
{
  digitalWrite(Right_Dir, HIGH);
}

//=======================================

void Go(int a, int b) // a for left motor's speed & b for right motor's speed
{
  analogWrite(Left_Speed, a);
  analogWrite(Right_Speed, b);
}
