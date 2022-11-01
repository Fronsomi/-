long x = 0;

 #include <ESP8266WiFi.h>
 WiFiServer server(80);

#include <VarSpeedServo.h>

VarSpeedServo myServo0;

VarSpeedServo myServo3;

VarSpeedServo myServo6;

VarSpeedServo myServo9;

VarSpeedServo myServo12;


void setup() {
     Serial.begin(9600);
   WiFi.begin("WiFi_102_2.4G", "102kvant102");
  while (WiFi.status() != WL_CONNECTED){
   delay(500);
     Serial.print(".");
   }
 server.begin();
   Serial.println(WiFi.localIP());

  myServo0.attach(0);

  myServo3.attach(3);

  myServo6.attach(6);

  myServo9.attach(9);

  myServo12.attach(12);


}

void loop() {
       WiFiClient client = server.available();
      String lineal = client. readStringUntil('r');
      if(lineal.indexOf("ID=1")>0){
        x = 1;
     }
      if(lineal.indexOf("ID=2")>0){
        x = 2;
     }
      if(lineal.indexOf("ID=3")>0){
        x = 3;
     }
      if(lineal.indexOf("ID=4")>0){
        x = 4;
     }
      if(lineal.indexOf("ID=5")>0){
        x = 5;
     }
    if (x == 1) {
      myServo0.attach(0);
       myServo0.slowmove(90,255);
    }
    if (x == 2) {
      myServo3.attach(3);
       myServo3.slowmove(90,255);
    }
    if (x == 3) {
      myServo6.attach(6);
       myServo6.slowmove(90,255);
    }
    if (x == 4) {
      myServo9.attach(9);
       myServo9.slowmove(90,255);
    }
    if (x == 5) {
      myServo12.attach(12);
       myServo12.slowmove(90,255);
    }
    client.println("<!DOCTYPE html> <html lang=ru> <head> <meta charset=UTF-8> <title>ArduBlock</title> <meta name=viewport content=width=200> </head> <body data-attr=ru>");
     client.println(" <p>Motor</p> ");
     client.println(" <a href='./?ID=1' style='padding:10px 15px;mergin:10px;border:1px solid #777;color:#777;text-decoration:none;'>L</a> ");
     client.println(" <a href='./?ID=2' style='padding:10px 15px;mergin:10px;border:1px solid #777;color:#777;text-decoration:none;'>R</a> ");
     client.println(" <p>Motor</p> ");
     client.println(" <a href='./?ID=3' style='padding:10px 15px;mergin:10px;border:1px solid #777;color:#777;text-decoration:none;'>T</a> ");
     client.println(" <a href='./?ID=4' style='padding:10px 15px;mergin:10px;border:1px solid #777;color:#777;text-decoration:none;'>B</a> ");
     client.println(" <p>Motor</p> ");
     client.println(" <a href='./?ID=5' style='padding:10px 15px;mergin:10px;border:1px solid #777;color:#777;text-decoration:none;'>S</a> ");

}
