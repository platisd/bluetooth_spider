#include <SoftwareSerial.h>
#include <Adafruit_SoftServo.h>  // SoftwareServo (works on non PWM pins)

#define SERVO1PIN 1   // Servo control line (orange) on Trinket Pin #0
#define SERVO2PIN 2   // Servo control line (orange) on Trinket Pin #1

SoftwareSerial mySerial(0,1); // RX, TX
Adafruit_SoftServo myServo1, myServo2;  //create TWO servo objects
long previousMillis = 0;        // will store last time LED was updated
const int interval = 20;           // interval at which to blink (milliseconds)
//String inputString = "";         // a string to hold incoming data
//boolean stringComplete = false;  // whether the string is complete


void setup()  
{
  mySerial.begin(9600);
  myServo1.attach(SERVO1PIN);   // Attach the servo to pin 0 on Trinket
  myServo1.write(0);           // Tell servo to go to position per quirk
  myServo2.attach(SERVO2PIN);   // Attach the servo to pin 1 on Trinket
  myServo2.write(0);           // Tell servo to go to position per quirk
  delay(15);                    // Wait 15ms for the servo to reach the position
  refreshServosNow();
}

void loop()
{
  if (mySerial.available()){
    char inChar = mySerial.read();
    switch (inChar) {
    case 'l':
      myServo1.write(180);
      myServo2.write(0);
      refreshServosNow();
      delay(20);
      break;
    case 'r':
       myServo1.write(0);
        myServo2.write(180);
        refreshServosNow();
        delay(20);      
        break;
    default:
      myServo1.write(0);
      myServo2.write(0);
      refreshServosNow();
      delay(20);
    }
  }
  refreshServos(millis());

}

void refreshServosNow(){
  myServo1.refresh();
  myServo2.refresh();
}

void refreshServos(long currentMillis){
  if(currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;   
    myServo1.refresh();
    myServo2.refresh();
  }
}



