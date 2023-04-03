#define STEP_PIN_1         54
#define DIR_PIN_1          55
#define ENABLE_PIN_1       38
#define MIN_PIN_1          3
#define MAX_PIN_1          2

#define STEP_PIN_2         60
#define DIR_PIN_2          61
#define ENABLE_PIN_2       56
#define MIN_PIN_2          14
#define MAX_PIN_2          15

#define SDPOWER            -1
#define SDSS               53


#define PS_ON_PIN          12
#define KILL_PIN           -1

// ADJUST PINS ACCORDING TO ELECTRONICS 

void setup() {
  
  pinMode(STEP_PIN_1  , OUTPUT);
  pinMode(DIR_PIN_1    , OUTPUT);
  pinMode(ENABLE_PIN_1    , OUTPUT);
  
  pinMode(STEP_PIN_2  , OUTPUT);
  pinMode(DIR_PIN_2    , OUTPUT);
  pinMode(ENABLE_PIN_2    , OUTPUT);
  
  digitalWrite(ENABLE_PIN_1    , LOW);
  digitalWrite(ENABLE_PIN_2    , LOW);

  digitalWrite(DIR_PIN_1    , HIGH);
  digitalWrite(DIR_PIN_2   , LOW);   // DIRECTION OF ROTATION (change if I assumed wrong)
  
  zsyp_setup(); // ZSYP MODE
}


void loop () 
{
  //kryncidelko(); // RUN FOR PURE ROTATIONAL MOTION

}

void kryncidelko()
{
  digitalWrite(STEP_PIN_1    , HIGH);
  digitalWrite(STEP_PIN_2    , HIGH);  
  delay(1);
  digitalWrite(STEP_PIN_1    , LOW);
  digitalWrite(STEP_PIN_2    , LOW);
  
}


void zsyp_setup()
{
    int leaning_time_1 = 2000; 
    int leaning_time_2 = 2000; // TIME SPENT OF OPENING VALVE (furry logics) ADJUST 

    int max_time = max(leaning_time_1,leaning_time_2);
    int start_time = millis();

    do
    {
      if (millis() - start_time < leaning_time_1)
        digitalWrite(STEP_PIN_1    , HIGH);
        delay(1);
        digitalWrite(STEP_PIN_1    , LOW);
        
      if (millis() - start_time < leaning_time_2)
        digitalWrite(STEP_PIN_2    , HIGH);
        delay(1);
    digitalWrite(STEP_PIN_2    , LOW);
    } while( millis() - start_time < max_time);

    
}
