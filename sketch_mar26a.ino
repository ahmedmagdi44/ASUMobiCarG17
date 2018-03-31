#include <SoftwareSerial.h>

SoftwareSerial mySerial(0,1);
int in1=11;
int in2=10;
int in3=9;
int in4=8;
char C;
  void motor(int one,int two,int three,int four)
{


  digitalWrite(in1,one);
  digitalWrite(in2,two);
  digitalWrite(in3,three);
  digitalWrite(in4,four);

  
}
void setup() {
pinMode(in1,OUTPUT); 
pinMode(in2,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT); 

Serial.begin(9600);
mySerial.begin(9600);
}

void loop() {
  if(mySerial.available()){
C = mySerial.read();
    Serial.println(C);
    delay(500);}
    switch(C){
      case 'S':

        motor(LOW,LOW,LOW,LOW);  
        break;
      case 'F':
        /*speed_l += 1;
        speed_r += 1;*/  
        motor(HIGH,LOW,HIGH,LOW);
        break;
      case 'B':
        /*speed_l += 1;
        speed_r += 1;*/
        motor(LOW,HIGH,LOW,HIGH);
        //delay(10);
        break;
      case 'R':
        /*speed_l += 1;
        speed_r += 1;*/
        motor(HIGH,LOW,LOW,HIGH);
        //delay(10);
        break;
      case 'L':
        /*speed_l += 1;
        speed_r += 1;*/
        motor(LOW,HIGH,HIGH,LOW);
        //delay(10);

        break;
    }
  }

 

  
