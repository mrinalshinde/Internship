char inchar; 
int numring=0;
int comring=3; 
int onoff=0;  
void setup()
{
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT); 
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);
   
  Serial.print("AT+CLIP=1\r"); 
  delay(100);  
} 
void toggleLeds()
{
  if (onoff==0)
  {
    onoff=1;
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    Serial.println("D12 high D13 low");
  } 
  else
    if (onoff==1)
    {
      onoff=0;
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      Serial.println("D12 low D13 high");
    }
}
 
void loop() 
{
  if(Serial.available() >0)
  {
    inchar=Serial.read(); 
    if (inchar=='R')
    {
      delay(10);
      inchar=Serial.read(); 
      if (inchar=='I')
      {
        delay(10);
        inchar=Serial.read();
        if (inchar=='N')
        {
          delay(10);
          inchar=Serial.read(); 
          if (inchar=='G')
          {
            delay(10);
             numring++;
            Serial.println("ring!");
            if (numring==comring)
            {
              numring=0; 
              toggleLeds();
            }
          }
        }
      }
    }
  }
}

