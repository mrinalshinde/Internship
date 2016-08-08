void setup()
{
  Serial.begin(9600);
}
void loop()
{
  Serial.println("ATD9620881553;\r\n");
  delay(10000);
  Serial.println("ATH");
  while(1);
}

