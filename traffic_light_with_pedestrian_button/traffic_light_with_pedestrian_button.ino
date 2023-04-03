

const int btnPedestrian =  10;     

const int red        = 2;      
const int oreange      = 3;
const int green      = 4;
     

void setup() {
  pinMode(red, OUTPUT);   
  pinMode(oreange, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(btnPedestrian, INPUT); 
  Serial.begin(9600);
}
void loop(){
 
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    Serial.print("GREEN");
    greenLight ();
    
    digitalWrite(green, LOW);
    digitalWrite(oreange, HIGH);
    Serial.print("\nOREANGE");
    
    delay(5000);
    
    digitalWrite(oreange, LOW);
    digitalWrite(red, HIGH);
    Serial.print("RED");
    delay(25000);
    
}
void greenLight(){
  for (int i = 1; i < 31; i++){
    int state = digitalRead(btnPedestrian);
    
    if (state == 0) {
      Serial.print(i);
      delay(1000);
      Serial.print(", ");
    }
    else if (state  == 1){
      Serial.print("PEDESTRIAN CROSSING");
      delay (5000);
      return;

    }
  }
}
  
    
