/* Bluetooth enhanced spider robot
 *
 * The spider moves forward or backward by sending a HIGH signal on either of the
 * motor pins.
 * If the same value is sent to both the pins, then the motor stops.
 * In order to turn, we move the pistons connected to each servo. That elevates
 * the equivalent side of the spider, resulting in a rotational movement.
 * Since the ATtiny85 based Adafruit Trinket is used, the standard 
 * Arduino Servo library can't be used, but the Adafruit one made for this chip.
 * Download it from:  https://github.com/adafruit/Adafruit_SoftServo
 * Check essential info at: https://learn.adafruit.com/trinket-gemma-servo-control/
 * 
 * For more details and schematics of the whole project:
 * https://platis.solutions/blog/2014/11/15/diy-bluetooth-enhanced-spider-robot/
 * 
 * Published under CC-license by Dimitris Platis
 * https://platis.solutions
 */

#include <SoftwareSerial.h>
#include <Adafruit_SoftServo.h> 

#define SERVO1PIN 1
#define SERVO2PIN 2 
#define MOTOR1PIN 3
#define MOTOR2PIN 4

SoftwareSerial mySerial(0,1); // RX, TX -- note that TX pin 1 is never used for transmitting, but for controlling a servo
Adafruit_SoftServo myServo1, myServo2;  //left and right servo, depends on your setup
long previousMillis = 0;      // will be used for refreshing the servos. Necessary for the ATtiny85 chip
const int interval = 20;     

void setup()  
{
  mySerial.begin(9600);
  myServo1.attach(SERVO1PIN);   
  myServo1.write(0);           
  myServo2.attach(SERVO2PIN);  
  myServo2.write(0);          
  delay(15);                    
  refreshServosNow();  //we need to refresh the servos
  pinMode(MOTOR1PIN, OUTPUT);
  pinMode(MOTOR2PIN, OUTPUT);
  digitalWrite(MOTOR1PIN,LOW);   
  digitalWrite(MOTOR2PIN,LOW);   
}

void loop()
{
  if (mySerial.available()){
    char inChar = mySerial.read();
    switch (inChar) {
    case 'l': //turn counter-clockwise
      motorGoFront();
      servosTurnLeft();
      break;
    case 'r': //turn clock-wise
      motorGoFront(); 
      servosTurnRight();
      break;
    case 'f': //go ahead
      motorGoFront();
      servosIdle();
      break;
    case 'b': //go back
      motorGoBack();
      servosIdle();
      break;
    default: //if you receive something that you don't know, just stop
      motorStop();
      servosIdle();
    }
  }
  refreshServos(millis());

}

//refreshes the servos as soon as called
void refreshServosNow(){
  myServo1.refresh();
  myServo2.refresh();
}

//refreshes the servos every 20 milliseconds
void refreshServos(long currentMillis){
  if(currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;   
    refreshServosNow();
  }
}

void motorGoFront(){
  digitalWrite(MOTOR1PIN,LOW);   
  digitalWrite(MOTOR2PIN,HIGH);    
}

void motorGoBack(){
  digitalWrite(MOTOR1PIN,HIGH);   
  digitalWrite(MOTOR2PIN,LOW);   
}

void motorStop(){ //this could also be achieved by giving HIGH to both
  digitalWrite(MOTOR1PIN,LOW);   
  digitalWrite(MOTOR2PIN,LOW);  
}

void servosTurnLeft(){
  myServo1.write(180);
  myServo2.write(0);
  refreshServosNow();
  delay(20);
}

void servosTurnRight(){
  myServo1.write(0);
  myServo2.write(180);
  refreshServosNow();
  delay(20);  
}

void servosIdle(){
  myServo1.write(0);
  myServo2.write(0);
  refreshServosNow();
  delay(20);
}






