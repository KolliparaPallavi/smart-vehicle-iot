#include <SoftwareSerial.h>

#define speedPin A0
#define motorRed 5
#define motorBrown 6
#define directionWhite 3
#define directionBlack 4
#define alcoholPin 7
#define Input1 8

SoftwareSerial monitor(9,10);

int PWMvalue;

int speedLimit = 100;

void pin_ISR()
{   
   sendsms("");
}

void setup() 
{
  pinMode(directionWhite,INPUT);
  pinMode(directionBlack,INPUT);
  pinMode(Input1,INPUT);
  pinMode(speedPin,INPUT);
  pinMode(alcoholPin,INPUT);
  pinMode(motorRed,OUTPUT);
  pinMode(motorBrown,OUTPUT);
  analogWrite(motorRed,0);
  analogWrite(motorBrown,0);
  Serial.begin(9600);
  monitor.begin(9600);
  attachInterrupt(digitalPinToInterrupt(Input1), pin_ISR, RISING);
}

void loop() 
{
  int speedValue = analogRead(speedPin);
   int  pwmValue = map(speedValue,0,1023,0,255);
  //Serial.println(speedValue);
  //Serial.println(PWMvalue);
  if(Serial.available() > 0)
  {
    String data = Serial.readString();
    speedLimit = data.toInt();
    Serial.println(speedLimit);
  }

  if(pwmValue > speedLimit)
  {
    PWMvalue = speedLimit;
  }
  else
  {
    PWMvalue = pwmValue;
  }
  Serial.println(PWMvalue);
  if(digitalRead(alcoholPin) == 0)
  {
    analogWrite(motorBrown,0);
    for(int i = PWMvalue; i > 0; i--)
    {
       analogWrite(motorRed,i); 
    }
    while(digitalRead(alcoholPin) == 0)
    {
      delay(10);
    }
  }
  
  if(((digitalRead(directionWhite) == 0)) && (digitalRead(directionBlack) == 1))
  {
    analogWrite(motorRed,PWMvalue); 
    analogWrite(motorBrown,0);
    //Serial.println("Moving Front");
  }

  else if(((digitalRead(directionWhite) == 1)) && (digitalRead(directionBlack) == 0))
  {
    back();
  }
  else
  {
    Stop();
  }
}


void back()
{
    analogWrite(motorRed,0);
    analogWrite(motorBrown,PWMvalue);
    //Serial.println("Moving Back");
}

void Stop()
{
    analogWrite(motorRed,0);
    analogWrite(motorBrown,0);
    //Serial.println("Stop");
}

void sendsms(String data1)
{
  monitor.println("AT\r");
  delay(1000);
  monitor.println("AT+CMGF=1\r");
  delay(1000);
  monitor.println("AT+CMGS=\"7981663583\"\r");
  delay(1000);
  monitor.println(data1);
  delay(1000);
  monitor.println((char)26);
  delay(100);
  Serial.println("SMS Sent");
}
