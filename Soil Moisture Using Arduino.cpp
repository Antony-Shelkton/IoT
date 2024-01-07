void setup()
{
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(6,OUTPUT);
}
void loop()
{
  int serial_data = analogRead(0);
  Serial.println(serial_data);
  if(serial_data > 300)
    digitalWrite(6,HIGH);
  else
    digitalWrite(6,LOW);
}
