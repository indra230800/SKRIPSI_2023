#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>//jika error maka Downgrade "Arduinojson by Benoit Blanchon" to the version 5.13.2. di menu manage library
// Set these to run example. 
#define FIREBASE_HOST "arduinouyp.firebaseio.com" 
#define FIREBASE_AUTH "I4ypeV1hhiElxSk4JBwUB8qWP33Zcp5GsEm1v1oi" 
#define WIFI_SSID "ARDUINO" 
#define WIFI_PASSWORD "123456789" 
#include <Servo.h>
Servo myservo;
//int buzzer=D4;
String nilai;
int katup=D3;//servo


void setup() {//wemos d1 mini
myservo.attach(katup); 
myservo.write(3);
//pinMode(LED_BUILTIN,OUTPUT);
//digitalWrite(LED_BUILTIN, HIGH);
  // connect to wifi. 
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD); 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000); 
  }
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH); 
}

void loop() {
  nilai=Firebase.getString("kontrolpintu/kuncipintu");
  //Firebase.setString("kontrolpintu/kuncipintu",nilai);
  if (nilai.indexOf("0")>=0){     //tutup kunci
  //digitalWrite(LED_BUILTIN, LOW);
  myservo.write(3);
  
  }
  else if(nilai.indexOf("1")>=0){ //buka kunci
  //digitalWrite(LED_BUILTIN, HIGH);
  myservo.write(90);
  //Firebase.setString("kontrolpintu/kuncipintu","0");
  }
  
delay(1000);
}
