#define LS 7
#define RS 6
int lsensor;
int rsensor;
int enA = 9;
int enB = 10;
 int in1 = 3;  
 int in2 = 2; 

 int in3 = 4;
 int in4 = 5; 

  void FWD(void){
analogWrite(enA,85);

analogWrite( enB , 85 );

digitalWrite(in1, HIGH); 
digitalWrite(in2, LOW);

digitalWrite(in3, HIGH); 
digitalWrite(in4, LOW);
  }

  
void Left (void){
    

analogWrite( enA , 85);

analogWrite( enB ,85);
digitalWrite(in1, LOW); 
digitalWrite(in2, HIGH);

digitalWrite(in3, HIGH); 
digitalWrite(in4, LOW);

    }
  void Right (void){
    analogWrite( enA , 85);

analogWrite( enB , 85);

digitalWrite(in1, HIGH); 
digitalWrite(in2, LOW);

digitalWrite(in3, LOW); 
digitalWrite(in4, HIGH);
  }
   
void setup() {
pinMode(LS,INPUT);
pinMode(RS,INPUT);

Serial.begin(9600);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);

pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
pinMode(enB, OUTPUT);
pinMode(enA, OUTPUT);
}

void loop() {
lsensor=digitalRead(LS);
rsensor=digitalRead(RS);

if((lsensor==LOW)&&(rsensor==LOW))
{ FWD(); }
else if ((lsensor==LOW)&&(rsensor==HIGH))
{ Right (); }
else if ((lsensor==HIGH)&&(rsensor==LOW))
{ Left(); }
}

