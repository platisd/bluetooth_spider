// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  digitalWrite(3, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(4, LOW);    // turn the LED off by making the voltage LOW


}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(3, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(4, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(3, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(4, HIGH);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
  digitalWrite(3, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(4, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
}

