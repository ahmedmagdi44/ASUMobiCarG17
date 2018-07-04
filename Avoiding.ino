

#include <NewPing.h>

#define TRIGGER_PIN  12 // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     13  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

int distance;
int duration;
NewPing sonar1(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

int enA = 9;
int enB = 10;
 int in1 = 3;  
 int in2 = 2; 

 int in3 = 4;
 int in4 = 5; 



  void Right(int a){
analogWrite(enA,a);

analogWrite( enB ,a );

digitalWrite(in1, HIGH); 
digitalWrite(in2, LOW);

digitalWrite(in3, HIGH); 
digitalWrite(in4, LOW);

  }

void Left (int a){
    

analogWrite( enA , a);

analogWrite( enB ,a);
digitalWrite(in1, LOW); 
digitalWrite(in2, HIGH);

digitalWrite(in3, LOW); 
digitalWrite(in4, HIGH);

}
  void FWD (int a){
    analogWrite( enA , a);

analogWrite( enB , a);

digitalWrite(in1, HIGH); 
digitalWrite(in2, LOW);

digitalWrite(in3, LOW); 
digitalWrite(in4, HIGH);

    }

    void Stop(){

analogWrite(enA,0);

analogWrite( enB , 0 );

digitalWrite(in1, LOW); 
digitalWrite(in2, LOW);

digitalWrite(in3, LOW); 
digitalWrite(in4, LOW);
      
      }

void Back (int a){

 analogWrite( enA , a);

analogWrite( enB , a);

digitalWrite(in1, LOW); 
digitalWrite(in2, HIGH);
digitalWrite(in3, HIGH); 
digitalWrite(in4, LOW);

  }



void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); 


pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
pinMode(enB, OUTPUT);
pinMode(enA, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 FWD(80);
  delay(50);    
  duration=sonar1.ping();
  distance=duration/US_ROUNDTRIP_CM;             
  Serial.print("Ping: ");
  Serial.print(distance);
  Serial.println("cm");
  
  if ( distance>0 && distance<20 )
     {Stop();
     delay(1000);
     Right(255);
     delay (500);
     
     } 
}
