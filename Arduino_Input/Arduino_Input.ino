#include <Servo.h>
int pos;
int DoorInput = A0;
int RoomInput = A1;
int ldrInput = A2;
int TempInput = A3;
int GasInput = A4;
int a[5] = {0,0,0,0,0};
int prev[5] = {0,0,0,0,0};

int LightHallEnable = 3;
int LightBedroomEnable = 4;
int LightBathroomEnable = 7;
Servo myservoLeft;
Servo myservoRight;
int FanHall = 5;
int FanBedroom = 6;
int Flagservo =1 ;
int FlagLightHall = 1;

void setup() {
  myservoLeft.attach(9);
  myservoRight.attach(10);
  pinMode(DoorInput , INPUT_PULLUP);
  pinMode(ldrInput , INPUT);
  pinMode(TempInput , INPUT);
  pinMode(GasInput , INPUT);
  pinMode(LightHallEnable , OUTPUT);
  pinMode(LightBedroomEnable , OUTPUT);
  pinMode(LightBathroomEnable , OUTPUT);
  pinMode(FanHall , OUTPUT);
  pinMode(FanBedroom , OUTPUT);
  Serial.begin(9600);
}
int i;
void loop() {

  
    if( Serial.available() > 5){
       for( i = 0 ; i < 5; i++){
         prev[i] = a[i];
       }  
      
      for( i = 0 ; i < 5; i++){
            a[i] = Serial.read() - '0';
            
            delay(100);
      }
    
   Flagservo = a[0];  
  }
    
 else
{
  
  
  a[0] = digitalRead(DoorInput);
 //  Flagservo  =a[0];
     //
  // a[1] = 1;

  int val = analogRead(ldrInput);
  if( map(val , 0 , 1023, 0 ,255) > 100)
      a[2] = 1;
  else
      a[2] = 0; 
  
  val = analogRead(TempInput);
  float mv = ( val/1024.0)*5000; 
  float cel = mv/10;
  Serial.println(cel);
  if(cel > 27.0 )
    a[3] = 1;
  else
    a[3] = 0;

   a[4] = digitalRead(GasInput);
}
   
 if(Flagservo == 1)
 {
       for (pos = 0; pos <= 180; pos += 1) {
                myservoLeft.write(pos);
                 myservoRight.write(180 - pos); 
                delay(15);
       }
       delay(1000);
       Flagservo = 2;
}
if(Flagservo == 2)
{
  for (pos = 180; pos >= 0; pos -= 1) {
                myservoLeft.write(pos);
                myservoRight.write(180 - pos);                 
                delay(15);
       }
       delay(1000);
       Flagservo = 0;
}

if(FlagLightHall && a[2])
{
  digitalWrite(LightHallEnable , HIGH);
 }
else
{
  digitalWrite(LightHallEnable , LOW);
}

if(FlagLightHall && a[3])
{
  digitalWrite(FanHall , HIGH);
 }
else
{
  digitalWrite(FanHall , LOW);
}

if(a[1] == 1)
{
  if( a[2] )
    digitalWrite(LightBedroomEnable , HIGH);
  if( a[3] )
    digitalWrite(FanBedroom , HIGH);
}
else
{
  digitalWrite(FanBedroom , LOW);
  digitalWrite(LightBedroomEnable ,LOW);
}
int i;
for(i = 0 ;i < 5 ;i++){
      Serial.println(a[i]);
      delay(250);
    } 
 
 
}
