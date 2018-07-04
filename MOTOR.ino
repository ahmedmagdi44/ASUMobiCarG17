//bluetooth defintions
#include <SoftwareSerial.h>
#define rxPin 0
#define txPin 1
SoftwareSerial rf(rxPin,txPin);
char state ;


//motor def

 int in1 = 11;
 int in2 = 10; 

 int in3 = 9;
 int in4 = 8; 



void FWD(void){

digitalWrite(in1, HIGH); 
digitalWrite(in2, LOW);

digitalWrite(in3, HIGH); 
digitalWrite(in4, LOW);

  }

  
void Back(void){

digitalWrite(in1, LOW); 
digitalWrite(in2, HIGH);

digitalWrite(in3, LOW); 
digitalWrite(in4, HIGH);

  }
  
void Stop(void){
 
digitalWrite(in1, LOW); 
digitalWrite(in2, LOW);

digitalWrite(in3, LOW); 
digitalWrite(in4, LOW);

  }

  void Right(void){
    

digitalWrite(in1, LOW); 
digitalWrite(in2, LOW);

digitalWrite(in3, HIGH); 
digitalWrite(in4, LOW);

    }
  void Left(void){
    

digitalWrite(in1, HIGH); 
digitalWrite(in2, LOW);

digitalWrite(in3, LOW); 
digitalWrite(in4, LOW);

    }



void setup() {
  // put your setup code here, to run once:
rf.begin(9600);
Serial.begin(9600); 

pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);

pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
 Serial.println("STart   ");
if(rf.available()){
  state=rf.read();
  Serial.println("STAT IS :   ");
  Serial.println(state);
  }
  
if(state=='S'){Stop();}
else if(state=='F'){FWD();}
else if(state=='B'){Back();}
else if(state=='R'){Right();}
else if(state=='L'){Left();}

}
