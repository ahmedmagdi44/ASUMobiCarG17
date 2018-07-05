#include <SoftwareSerial.h>
#define rxPin 0
#define txPin 1
SoftwareSerial rf(rxPin,txPin);
char state ;
int IR=8;


#include <NewPing.h>

#define TRIGGER_PIN  12 // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     13  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

int distance;
int duration;
NewPing sonar1(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.




#define LS 7
#define RS 6
int lsensor;
int rsensor;


int enA = 9;
int enB = 10;
 int in1 = 3;  
 int in2 = 2; 

 int in3 = 5;
 int in4 = 4; 

void circle(){
FWD(110,150);
delay(3250); 
Stop();
delay(100000);
}

void infinity()
{
  FWD(110,150);
  delay(3000);
  FWD(150,110);
  delay(3000);
  Stop();
  delay(100000);
}
void square(){
  FWD(100,100);
  delay(1000);
  Stop();
  delay(1000);
  Right(100,100);
  delay(1900);
   Stop();
  delay(1000);
  FWD(100,100);
  delay(1000);
   Stop();
  delay(1000);
  Right(100,100);
  delay(1900);
   Stop();
  delay(1000);
  FWD(100,100);
  delay(1000);
   Stop();
  delay(1000);
  Right(100,100);
  delay(1900);
   Stop();
  delay(1000);
  FWD(100,100);
  delay(1000);
   Stop();
  delay(1000);
}

 

 void Left(int a , int b){
analogWrite(enA,a);

analogWrite( enB ,b );

digitalWrite(in1, HIGH); 
digitalWrite(in2, LOW);

digitalWrite(in3, HIGH); 
digitalWrite(in4, LOW);

  }


void Right (int a , int b){
    

analogWrite( enA , a);

analogWrite( enB ,b);
digitalWrite(in1, LOW); 
digitalWrite(in2, HIGH);

digitalWrite(in3, LOW); 
digitalWrite(in4, HIGH);

}
  void FWD (int a , int b){
    analogWrite( enA , a);

analogWrite( enB , b);

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

void Back (int a , int b){

 analogWrite( enA , a);

analogWrite( enB , b);

digitalWrite(in1, LOW); 
digitalWrite(in2, HIGH);
digitalWrite(in3, HIGH); 
digitalWrite(in4, LOW);

  }

  void avoid (void)
{
  FWD(70,70);
  delay(50);    
  duration=sonar1.ping();
  distance=duration/US_ROUNDTRIP_CM;             
  Serial.print("Ping: ");
  Serial.print(distance);
  Serial.println("cm");
  
  if ( distance>0 && distance<20 )
     {Stop();
     delay(1000);
     Right(255,255);
     delay (500);
     
     } 
}


void tracking () {
lsensor=digitalRead(LS);
rsensor=digitalRead(RS);

if((lsensor==LOW)&&(rsensor==LOW))
{ FWD(60,60); }
else if ((lsensor==LOW)&&(rsensor==HIGH))
{ Right (60,60); }
else if ((lsensor==HIGH)&&(rsensor==LOW))
{ Left(80,80); }
else((lsensor==HIGH)&&(rsensor==HIGH)) ;
{ FWD(60,60) ; }
}



void setup() {
  // put your setup code here, to run once:
rf.begin(9600);
Serial.begin(9600); 

pinMode(LS,INPUT);
pinMode(RS,INPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
pinMode(enB, OUTPUT);
pinMode(enA, OUTPUT);
pinMode(IR, INPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
 
if(rf.available()){
  state=rf.read();
  Serial.println("STAT IS :   ");
  
  Serial.println(state);
  }
  
if(state=='S'){Stop();}
else if(state=='F'){FWD(100,100);}
else if(state=='B'){Back(100,100);}
else if(state=='R'){Right(100,100);}
else if(state=='L'){Left(100,100);}
else if(state=='W') {avoid();}
else if(state=='U') {tracking();}
else if(state=='K') {infinity();}

}
      


/
