char incoming_char=0;
 
void setup()
{
  Serial.begin(9600);
 
  delay(20000);  
 
  Serial.print("AT+CMGF=1\r");
  delay(100);
  Serial.print("AT+CNMI=3,3,0,0,0\r"); 
  delay(100);
}
 void loop()
{
  if(Serial.available() >0)
  {
    incoming_char=Serial.read(); 
    Serial.print(incoming_char); 
  }
}
