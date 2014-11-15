#include <SoftwareSerial.h>

SoftwareSerial mySerial(0,1); // RX, TX

void setup()  
{
  mySerial.begin(9600);
  pinMode(1,OUTPUT);
  pinMode(1,LOW);
}

void loop()
{
  if (mySerial.available()){
    char temp = mySerial.read();
    if (temp == '*'){
    digitalWrite(1,HIGH);
    delay(500);
    digitalWrite(1,LOW);
    delay(500);
    }
  }
}

