int DoorInput = A0;
int RoomInput = A1;
int ldrInput = A2;
int TempInput = A3;
int GasInput = A4;
int a[5] = {0,0,0,0,0};
int count = 0;

void setup() {
  pinMode(DoorInput , INPUT);
  pinMode(RoomInput , INPUT);
  pinMode(ldrInput , INPUT);
  pinMode(TempInput , INPUT);
  pinMode(GasInput , INPUT);
  Serial.begin(1200);
}

void loop() {
    
  
  
        for(int j = 0; j < 5 ; j++){
          Serial.println(a[j]) ;
        delay(200);
        }
      count = 0;
  
  
  a[0] = digitalRead(DoorInput);
  a[1] = digitalRead(RoomInput);

  int val = analogRead(ldrInput);
  if( map(val , 0 , 1023, 0 ,255) > 100)
      a[2] = 0;
  else
      a[2] = 1; 
  
   val = analogRead(TempInput);
  float mv = ( val/1024.0)*5000; 
  float cel = mv/10;
  if(cel > 27.0 )
    a[3] = 1;
  else
    a[3] = 0;

   a[4] = digitalRead(GasInput);

   
   
   count +=1;

}
