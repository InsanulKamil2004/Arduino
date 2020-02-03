void linefollowing(){


  if (sensor_4 == 0 && sensor_3 == 0 && sensor_2 == 0 && sensor_1 == 1){ //0001

      Turn_Right();
      Go(80, 80-50);

      a = 1;

  }

  else if (sensor_4 == 0 && sensor_3 == 0 && sensor_2 == 1 && sensor_1 == 1){ //0011

      Turn_Right();
      Go(80, 80);

      a = 1;

  }

  else if (sensor_4 == 1 && sensor_3 == 0 && sensor_2 == 0 && sensor_1 == 0){ //1000

      Turn_Left();
      Go(80-50, 80);

      a = 2;

  }

  else if (sensor_4 == 1 && sensor_3 == 1 && sensor_2 == 0 && sensor_1 == 0){ //1100

      Turn_Left();
      Go(80, 80);

      a = 2;
  }

  else if (sensor_4 == 0 && sensor_3 == 0 && sensor_2 == 0 && sensor_1 == 0){ //0000

    //Added in Tutorial 8
    //Stop();
    if(a==1){
     // while(sensor_1 != HIGH){
        Turn_Right();
         Go(80+10, 80);
      //}
    }
    else if (a==2){
      //while(sensor_4 != HIGH){
        Turn_Left();
        Go(80, 10+50);
      //}
    }
//    else if (a==0){
//      Stop();
//    }
    
    a=0;
    
  }
  else{
    Forward();
    Go(65,60);
  }
}
