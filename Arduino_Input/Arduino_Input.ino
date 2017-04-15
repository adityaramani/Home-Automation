#include <Servo.h>
int pos;
int DoorInput = A0;
int RoomInput = A1;
int ldrInput = A2;
int TempInput = A3;
int GasInput = A4;
int a[5] = {0,0,0,0,0};
int server[5] = {-1,-1,-1,-1,-1};
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


void doors_open()
{
   for (pos = 0; pos <= 180; pos += 1) {
                myservoLeft.write(pos);
                 myservoRight.write(180 - pos);
                delay(15);
       }
    delay(1000);

}

void doors_close()
{

      for (pos = 180; pos >= 0; pos -= 1) {
                myservoLeft.write(pos);
                myservoRight.write(180 - pos);
                delay(15);
      }
  delay(1000);


}



void setup() {
  myservoLeft.attach(9);
  myservoRight.attach(10);
  pinMode(DoorInput , INPUT);
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


    if( Serial.available() > 4){

      for( i = 0 ; i < 5; i++){
            server[i] = Serial.read() - '0';

            delay(100);
      }
delay(2000);
   Flagservo = a[0];

}

 else
{
  a[0] = digitalRead(DoorInput);
  Flagservo  =a[0];
  //a[1] is value of IR sensor in room
  a[1] =  a[0];

  int val = analogRead(ldrInput);
  if( map(val , 0 , 1023, 0 ,255) > 100)
      a[2] = 1; //set high cause the surrounding is dark
  else
      a[2] = 0;

  val = analogRead(TempInput);
  

  float mv = ( val/1024.0)*5000;
  float cel = mv/10;
  //Serial.print("Temp :" );
  //Serial.println(cel);
  if(cel > 95.0 ) // if temp is > 27 set a[3] as high , so as to turn on fans..  Change value during presenting
    a[3] = 1;
  else
    a[3] = 0;

   a[4] = digitalRead(GasInput);
}

if(server[0] == 1){
  doors_open();
  delay(1000);
  doors_close();
  server[0] = -1;
}

else if(Flagservo)
 {
       doors_open();
       delay(1000);
       doors_close();
       Flagservo = 0 ;
       a[0] = 0;
}

if(server[2] == 1)
{
  digitalWrite(LightHallEnable , HIGH);
  digitalWrite(LightBedroomEnable , HIGH);
}
else if(server[2] == 0 ) {
  digitalWrite(LightHallEnable , LOW);
  digitalWrite(LightBedroomEnable ,LOW);


}


else{
  if(a[2])
 {
   digitalWrite(LightHallEnable , HIGH);
   digitalWrite(LightBedroomEnable , HIGH);
  }
else{
  digitalWrite(LightHallEnable , LOW);
  digitalWrite(LightBedroomEnable ,LOW);

}
}

if(server[3] == 1){
  digitalWrite(FanHall , HIGH);
  digitalWrite(FanBedroom , LOW);

}
else if(server[3] == 0 )
{
    digitalWrite(FanHall , LOW);
  digitalWrite(FanBedroom , LOW);

}
else{
if(a[3])
{
  digitalWrite(FanHall , HIGH);
  digitalWrite(FanBedroom , HIGH);

 }
else
{
  digitalWrite(FanHall , LOW);
  digitalWrite(FanBedroom , LOW);

}
}



for(i = 0 ;i < 5 ;i++){
      Serial.println(a[i]);
      delay(250);
    }

delay(2000);

}
