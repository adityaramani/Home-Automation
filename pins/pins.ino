#include <Servo.h>

int a[6] = {1,1,1,1,1,1};
Servo myservoLeft;
Servo myservoRight;
int pos = 0;
//int redPinHall = A0;
//int greenPinHall = A1;
//int bluePinHall = A2;
//int redPinBedRoom = A3;
//int greenBedRoom = A4;
//int blueBedRoom = A5;
int redPinBathRoom = 11;
int greenPinBathRoom = 12;
int bluePinBathRoom = 2;
int motorHallEnable = 3;
int motorHallpin1 = 4;
int motorHallpin2 = 5;
int motorBedroomEnable = 6;  
int motorBedroompin1 = 7;
int motorBedroompin2 = 8;

int flagServo = a[0];
int flagLightHall = a[1];
int flagLightBedroom = a[2];
int flagLightBathroom = a[3];
int fanHall = a[4];
int fanBedroom = a[5];


int count = 0;
void setup() {
  
  Serial.begin(1200);
  myservoLeft.attach(9);
  myservoRight.attach(10);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT); 
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT); 
  pinMode(redPinBathRoom , OUTPUT);
  pinMode(greenPinBathRoom , OUTPUT);
  pinMode(bluePinBathRoom , OUTPUT);
  pinMode(motorHallEnable, OUTPUT);
  pinMode(motorHallpin1, OUTPUT);
  pinMode(motorHallpin2, OUTPUT);
  pinMode(motorBedroomEnable, OUTPUT);
  pinMode(motorBedroompin1, OUTPUT);
  pinMode(motorBedroompin2, OUTPUT);
  pinMode(13, OUTPUT);


}

void loop() {
  
  for(int i =0 ; i < 6; i++){
        //Serial.println(i);
         delay(100); 
}

  if(flagServo == 1)
 {
       for (pos = 0; pos <= 180; pos += 1) {
                myservoLeft.write(pos);
                 myservoRight.write(180 - pos); 
                delay(15);
       }
       delay(1000);
       flagServo = 2;
}
if(flagServo == 2)
{
  for (pos = 180; pos >= 0; pos -= 1) {
                myservoLeft.write(pos);
                myservoRight.write(180 - pos);                 
                delay(15);
       }
       delay(1000);
       flagServo = 0;
}

if(flagLightHall)
{
    digitalWrite(13, HIGH);
    analogWrite(A0, 255);
    analogWrite(A1, 0);
    analogWrite(A2, 0);
}
else
{
  analogWrite(A0, 0);
  analogWrite(A1, 0);
  analogWrite(A2, 0);
}

if(flagLightBedroom)
{
    analogWrite(A3, 0);
    analogWrite(A4, 255);
    analogWrite(A5, 0);
}
else
{
    analogWrite(A3, 0);
    analogWrite(A4, 0);
    analogWrite(A5, 0);
}

if(flagLightBathroom)
{
    analogWrite(redPinBathRoom, -1);
    analogWrite(greenPinBathRoom, -1);
    analogWrite(bluePinBathRoom, -1);
}
else
{
     analogWrite(redPinBathRoom, 0);
    analogWrite(greenPinBathRoom, 0);
    analogWrite(bluePinBathRoom, 0);
}

if(fanHall)
{
  analogWrite(motorHallEnable, 255);
  digitalWrite(motorHallpin1, HIGH);
  digitalWrite(motorHallpin2, LOW);
    
}
else
{
  digitalWrite(motorHallpin1, LOW);
  digitalWrite(motorHallpin2, LOW);
}

if(fanBedroom)
{
  analogWrite(motorBedroomEnable, 255);
  digitalWrite(motorBedroompin1, HIGH);
  digitalWrite(motorBedroompin2, LOW);
    
}
else
{
  digitalWrite(motorBedroompin1, LOW);
  digitalWrite(motorBedroompin2, LOW);
}


if(Serial.available() > 4)
  {
  for(int i =0 ; i< 5; i++)
 {      a[i] =  Serial.read() - '0';
         Serial.println(a[i]);
      delay(100);     
 }

 Serial.print("read Shit");
 
}

count = count  +1;
}



void setColor(int red, int green, int blue)
{
 
  analogWrite(A0, red);
  analogWrite(A1, green);
  analogWrite(A2, blue);  
}
