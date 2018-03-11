#define RF 8 //right forward
#define RB 9 //right backward
#define LF 10 //left forward
#define LB 11 //left backward

 char x;
void setup() {
  
    pinMode (RF,OUTPUT);
    pinMode (RB,OUTPUT);
    pinMode (LF,OUTPUT);
    pinMode (LB,OUTPUT);

    serial.begin(9600);

   
}

void loop() {
  
  if (serial.available() )
  {
    x=serial.read();
    switch (x)
      {
        case 'f': void forward();  break;
        case 'b': void backward(); break;
        case 'l': void left();     break;
        case 'r': void right();    break;
        case 's': void stop_car();  break;
        default : void stop_car();  
      }
    
    
    
  }



}


//motion functions

void forward()
{
  digitalWrite (RF,HIGH);
  digitalWrite (RB,LOW);
  digitalWrite (LF,HIGH);
  digitalWrite (LB,LOW);
}


void backward()
{
  digitalWrite (RF,LOW);
  digitalWrite (RB,HIGH);
  digitalWrite (LF,LOW);
  digitalWrite (LB,HIGH);
}


void right() //turn right
{
  digitalWrite (RF,LOW);
  digitalWrite (RB,HIGH);
  digitalWrite (LF,HIGH);
  digitalWrite (LB,LOW);
}


void left() //turn left
{
  digitalWrite (RF,HIGH);
  digitalWrite (RB,LOW);
  digitalWrite (LF,LOW);
  digitalWrite (LB,HIGH);
}


void stop_car()
{
  digitalWrite (RF,LOW);
  digitalWrite (RB,LOW);
  digitalWrite (LF,LOW);
  digitalWrite (LB,LOW);
}




























