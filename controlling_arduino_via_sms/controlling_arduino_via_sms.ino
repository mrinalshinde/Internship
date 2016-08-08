char inchar; 
int led1 = 10;
int led2 = 11;
int led3 = 12;
int led4 = 13;
 
void setup()
{
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
 
 Serial.begin(9600);
 delay(20000);  
  Serial.print("AT+CMGF=1\r");  
  delay(100);
  Serial.print("AT+CNMI=2,2,0,0,0\r"); 
   delay(100);
  Serial.println("Ready...");
}
 
 void loop() 
{
  if(Serial.available() >0)
  {
    inchar=Serial.read(); 
    if (inchar=='#')
    {
      delay(10);
 
      inchar=Serial.read(); 
      if (inchar=='a')
      {
        delay(10);
        inchar=Serial.read();
        if (inchar=='0')
        {
          digitalWrite(led1, LOW);
        } 
        else if (inchar=='1')
        {
          digitalWrite(led1, HIGH);
        }
        delay(10);
        inchar=Serial.read(); 
        if (inchar=='b')
        {
          inchar=Serial.read();
          if (inchar=='0')
          {
            digitalWrite(led2, LOW);
          } 
          else if (inchar=='1')
          {
            digitalWrite(led2, HIGH);
          }
          delay(10);
          inchar=Serial.read(); 
          if (inchar=='c')
          {
            inchar=Serial.read();
            if (inchar=='0')
            {
              digitalWrite(led3, LOW);
            } 
            else if (inchar=='1')
            {
              digitalWrite(led3, HIGH);
            }
            delay(10);
            inchar=Serial.read(); 
            if (inchar=='d')
            {
              delay(10);
              inchar=Serial.read();
              if (inchar=='0')
              {
                digitalWrite(led4, LOW);
              } 
              else if (inchar=='1')
              {
                digitalWrite(led4, HIGH);
              }
              delay(10);
            }
          }
          Serial.println("AT+CMGD=1,4"); 
        }
      }
    }
  }
}



