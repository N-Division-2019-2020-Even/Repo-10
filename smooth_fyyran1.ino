#include <Servo.h>

Servo servo;

void setup()
{
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  servo.attach(8);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);

}

void loop()
{
  int i;
  for(i=4;i<=7;i++)
  {
  	digitalWrite(i, LOW);
  	delay(500);
  	digitalWrite(i, HIGH);
  	delay(500);
  }
  
  int pos=0;
  int button1,button2,button3,button4;
  button1=digitalRead(9);
  button2=digitalRead(10);
  button3=digitalRead(11);
  button4=digitalRead(12);
  
  servo.write(pos);
  
  if(button1==1)
  {
    pos=45;
  }
  else if(button2==1)
  {
    pos=90;
  }
  else if(button3==1)
  {
    pos=135;
  }
  else if(button4==1)
  {
    pos=180;
  }
  
  if(button1==1 || button2==1 || button3==1 || button4==1)
  {
    for(int i=0;i<3;i++)
  	{
      	servo.write(pos);
  		delay(1000);
    	servo.write(0);
    	delay(1000);
  	}
  }
}