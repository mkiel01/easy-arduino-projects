int green = 13;
int yellow = 12;
int red = 11;
int buttonState = 0;

void setup(){
    pinMode(red, OUTPUT);
    pinMode(yellow, OUTPUT);
    pinMode(green, OUTPUT);
    pinMode(8, INPUT);
    
}

void loop()
{
  // read the state of the pushbutton value
  buttonState = digitalRead(8);
  // check if pushbutton is pressed.  if it is, the
  // buttonState is HIGH
  if (buttonState == HIGH) {
    // turn LED on
    digitalWrite(green, HIGH);
  } else {
    // turn LED off
    digitalWrite(green, LOW);
  }
  delay(10); // Delay a little bit to improve simulation performance
}
