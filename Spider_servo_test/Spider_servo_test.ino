#include <Adafruit_SoftServo.h>  // SoftwareServo (works on non PWM pins)


Adafruit_SoftServo myServo1, myServo2;  //create TWO servo objects

#define SERVO1PIN 1   // Servo control line (orange) on Trinket Pin #0
#define SERVO2PIN 2   // Servo control line (orange) on Trinket Pin #1


void setup() 
{ 
  myServo1.attach(SERVO1PIN);   // Attach the servo to pin 0 on Trinket
  myServo1.write(0);           // Tell servo to go to position per quirk
  myServo2.attach(SERVO2PIN);   // Attach the servo to pin 1 on Trinket
  myServo2.write(0);           // Tell servo to go to position per quirk
  delay(15);                    // Wait 15ms for the servo to reach the position
  refreshServos();
} 


void loop() 
{ 
  for(int pos = 0; pos < 180; pos += 3)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myServo1.write(pos);           // Tell servo to go to position per quirk
    myServo2.write(180-pos);           // Tell servo to go to position per quirk    
    delay(15);                       // waits 15ms for the servo to reach the position 
    refreshServos();
  } 
  for(int pos = 180; pos>=1; pos-=3)     // goes from 180 degrees to 0 degrees 
  {                                
    myServo1.write(pos);           // Tell servo to go to position per quirk
    myServo2.write(180-pos);           // Tell servo to go to position per quirk    
    delay(15);                        // waits 15ms for the servo to reach the position 
    refreshServos();

  } 
}

void refreshServos(){
  myServo1.refresh();
  myServo2.refresh();
}


