/*
This code is published in public domain.
Any part of it or whole code can be edited/removed/modified, but reproducing and publishing it can be done only by providing proper credit to the resource (make-i-stan).

The Sketch is a simple 7-Segment-LED driver using Arduino UNO with direct addressing all LED segments of all displays at the same time (see Fritzing for detail).
Each LED display has an enable terminal, so each time only one LED dispalys and a number is shown at one display only, keeping others off.
Since it is targeted for beginners, direct addressing is avoided at each terminal like the previous version, and multiplexing logic is employed.
Additional feature of this code is to make use of displaying digits on 7-Segment-LED display. So we will add a buzzer and timing mechanism to make Alarm Clock out of it.
In this way, a number displaying circuit can be turned into clock and an alarm eventually.

Specially prepared for Arduino Nights at Make-i-stan (Pakistan's first and only Makerspace).
For more details, visit www.Make-i-stan.co or www.Facebook.com/Makeistan or www.Twitter.com/Makeistan
*/

//                                                                                           g  f  G  a  b
//                                                                                           |  |  |  |  |
const int a=2;                                                                               //////a//////
const int b=3;                                                                               //         //
//                                                                                           f           b
const int c=4;                                                                               //         //
const int d=5;                                                                               //////g//////
const int e=6;                                                                               //         //
//                                                                                           e           c
const int f=7;                                                                               //         //
const int g=8;                                                                               //////d////// (h)
//                                                                                           |  |  |  |  |
//                                                                                           e  d  G  c  h

/*
Follow this configuration for making connections in common cathode LED 7-segment displays
'a' through 'g' are 7 segment display LEDs while 'h' is an LED as a point on display.
'G' is used for provide Ground which I am using as Enable here, thus LED will lit only iff I turn G off.
'h' don't needs to be get connected since there is no room for a point in Clock display
*/

const int buzzer = 9;

const int m1 = 10;
const int m2 = 11;
const int s1 = 12;
const int s2 = 13;

int mm=60;
int ss=60;

unsigned long timer=0;

void setup()
{
  Serial.begin(9600);
  
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
  
  pinMode(buzzer,OUTPUT);
  
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(s1,OUTPUT);
  pinMode(s2,OUTPUT);
}

/*
      displayNumber(i/10,1);
      displayNumber(i%10,2);
      displayNumber(j/10,3);
      displayNumber(j%10,4);
*/

void loop()
{
  for (int i=60;i>=0;i--)
  {
    for (int j=60;j>=0;j--)
    {
      displayTime(i,j);
    }
    Alarm();
  }
}

void displayTime(int mm, int ss)
{
  timer = millis();
  while((millis()- timer) <=1000)
  {
      displayNumber(mm/10,1);
      displayNumber(mm%10,2);
      displayNumber(ss/10,3);
      displayNumber(ss%10,4);
  } 
}
void displayNumber(int number, int serial)
{
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
  
  digitalWrite(m1,HIGH);
  digitalWrite(m2,HIGH);
  digitalWrite(s1,HIGH);
  digitalWrite(s2,HIGH);
  
  if (number==0)
  {
    
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(f,HIGH);
    //digitalWrite(g,HIGH);
  }
  
  if (number==1)
  {
//    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
//    digitalWrite(d,HIGH);
//    digitalWrite(e,HIGH);
//    digitalWrite(f,HIGH);
//    digitalWrite(g,HIGH);
  }
  
  if (number==2)
  {
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
//    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e,HIGH);
//    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);
  }
  
  if (number==3)
  {
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
//    digitalWrite(e,HIGH);
//    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);
  }
  
  if (number==4)
  {
//    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
//    digitalWrite(d,HIGH);
//    digitalWrite(e,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);
  }
  
  if (number==5)
  {
    digitalWrite(a,HIGH);
//    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
//    digitalWrite(e,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);
  }
  
  if (number==6)
  {
    digitalWrite(a,HIGH);
//    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);
  }
  
  if (number==7)
  {
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
//    digitalWrite(d,HIGH);
//    digitalWrite(e,HIGH);
//    digitalWrite(f,HIGH);
//    digitalWrite(g,HIGH);
  }
  
  if (number==8)
  {
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);
  }
  
  if (number==9)
  {
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
//    digitalWrite(e,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);
  }
  
  if (serial==1)
  {
    digitalWrite(m1,LOW);
  }
  if (serial==2)
  {
    digitalWrite(m2,LOW);
  }
  if (serial==3)
  {
    digitalWrite(s1,LOW);
  }
  if (serial==4)
  {
    digitalWrite(s2,LOW);
  }

}

void Alarm()
{
  for (int i=0;i<1000;i++)
    tone(buzzer,i+1000,(i*i)+1000);
  for (int i=1000;i>0;i--)
    tone(buzzer,i+1000,(i*i)+1000);  
  for (int i=0;i<100;i++)
    tone(buzzer,i+1000,(i*i)+1000);
  for (int i=100;i>0;i--)
    tone(buzzer,i+1000,(i*i)+1000);
  for (int i=0;i<5000;i++)
    tone(buzzer,i+1000,(i*i)+1000);
  for (int i=5000;i>0;i--)
    tone(buzzer,i+1000,(i*i)+1000);
  for (int i=0;i<1500;i++)
    tone(buzzer,i+1000,(i*i)+1000);
  for (int i=1500;i>0;i--)
    tone(buzzer,i+1000,(i*i)+1000);
  for (int i=0;i<15000;i++)
    tone(buzzer,i+1000,(i*i)+1000);
  for (int i=15000;i>0;i--)
    tone(buzzer,i+1000,(i*i)+1000);
}
