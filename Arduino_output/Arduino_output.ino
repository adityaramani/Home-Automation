#include <Servo.h>

//int redPinHall = A0;
//int greenPinHall = A1;
//int bluePinHall = A2;
//int redPinBedRoom = A3;
//int greenBedRoom = A4;
//int blueBedRoom = A5;
int redPinBathRoom = 11;
int greenPinBathRoom = 12;
int bluePinBathRoom = 2;
int motorHallpin1 = 4;
int motorHallpin2 = 5;
int motorBedroompin1 = 7;
int motorBedroompin2 = 8;


void setup() {
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT); 
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT); 
  pinMode(redPinBathRoom , OUTPUT);
  pinMode(greenPinBathRoom , OUTPUT);
  pinMode(bluePinBathRoom , OUTPUT);
  pinMode(motorHallpin1, OUTPUT);
  pinMode(motorHallpin2, OUTPUT);
   pinMode(motorBedroompin1, OUTPUT);
  pinMode(motorBedroompin2, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {

digitalWrite(13, HIGH);
analogWrite(A0, 255);
analogWrite(A1, 0);
analogWrite(A2, 0);
analogWrite(A3, 0);
analogWrite(A4, 255);
analogWrite(A5, 0);
analogWrite(redPinBathRoom, 0);
analogWrite(greenPinBathRoom,0);
analogWrite(bluePinBathRoom, 255);
digitalWrite(motorHallpin1, HIGH);
digitalWrite(motorHallpin2, LOW);
digitalWrite(motorBedroompin1, HIGH);
digitalWrite(motorBedroompin2, LOW);

}




void setColor(int red, int green, int blue)
{
 
  analogWrite(A0, red);
  analogWrite(A1, green);
  analogWrite(A2, blue);  
}






