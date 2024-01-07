void setup(){
  Serial.begin(9600);
  pinMode(4,INPUT);
  pinMode(7,OUTPUT);
}
void loop(){
  int x = digitalRead(4);
  if(x==1)
    digitalWrite(7,HIGH);
  else
    digitalWrite(7,LOW);
  Serial.println(x);
  delay(1000);

}
