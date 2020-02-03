//Connect

void Connect()
 { 
  
  OneSheeld.begin();
  IOT.disconnect();
  IOT.resetConnectionParametersToDefaults();
  IOT.connect(host_name);
  IOT.setOnNewMessage(&newMessage);
  IOT.setOnConnectionStatusChange(&connectionStatus);
  IOT.setOnError(&error);
  delay(3000);
  Subscribe();
  Publish(); 
  
 }
