
#define LM1 6 // left motor M1a
#define LM2 5 // left motor M2a
#define RM1 10 // right motor M2a
#define RM2 9 // right motor M2b
const int dataIN = 2; //IR sensor INPUT

unsigned long prevmillis; // To store time
unsigned long duration; // To store time difference

int rpm,n=0, counter=0; // RPM value
float distance=0;

boolean currentstate; // Current state of IR input scan
boolean prevstate; // State of IR sensor in previous scan

void setup()
{
         
  prevmillis = 0;
  prevstate = LOW;  
  Serial.begin(9600);
  
}

void loop()
{
  analogWrite(LM1, 150);
digitalWrite(LM2, LOW);
analogWrite(RM1, 150);
digitalWrite(RM2, LOW);
delay(2000);
  pinMode(dataIN,INPUT);
  while(n<12)
  {
            analogWrite(LM2, 200);
          digitalWrite(LM1, LOW);
          analogWrite(RM1, 200);
          digitalWrite(RM2, LOW);
 // RPM Measurement
  currentstate = digitalRead(dataIN); // Read IR sensor state
 if( prevstate != currentstate) // If there is change in input
   {
     if( currentstate == HIGH ) // If input only changes from LOW to HIGH
       {
        counter++;
        distance=3.14*n;
        Serial.println(counter);
        if(counter==13)
        {
         duration = ( millis() - prevmillis ); // Time difference between revolution in microsecond
         rpm = (60000/duration); // rpm = (1/ time millis)*1000*60;
         prevmillis = millis(); // store time for next revolution calculation
        // Serial.println(rpm);
         counter=0;
       }
       n++;
      /* if(n==19)
       {
          analogWrite(LM1, 0);
          digitalWrite(LM2, LOW);
          analogWrite(RM1, 0);
          digitalWrite(RM2, LOW);
       }
      // Serial.println(n);*/
       }
   }
  prevstate = currentstate; // store this scan (prev scan) data for next scan
  }
  n=0;
//  if(distance >= 670){
// analogWrite(LM1, 0);
//digitalWrite(LM2, LOW);
//analogWrite(RM1, 0);
//digitalWrite(RM2, LOW);
//  }
  }
  
  // SERIAL Display
  //if( ( millis()-prevmillis ) >= 1000 )
   // {
      // Serial.println(rpm);  
   // }

