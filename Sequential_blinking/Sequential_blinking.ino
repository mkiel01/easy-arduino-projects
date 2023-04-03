
/* A simple program to sequentially turn on and turn off 3 LEDs */ 

int LED1 = 11;

void setup() {
   pinMode(LED1, OUTPUT);
   
}


void loop() {
  digitalWrite(LED1, HIGH);    // turn on LED1 
  delay(3000);                  // wait for 200ms
                  // wait for 300ms before running program all over again

}
