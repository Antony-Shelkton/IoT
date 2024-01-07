#include<ESP8266WiFi.h>
#include<ThingSpeak.h>
const char *ssid = "Hello_123";
const char *pass = "1234";
WiFiClient client;

long myChannelNumber = 2345673;
const char myAPIkey[] = "FGSR36VG3GFGDG";

void setup()
{
  Serial.begin(9600);
  WiFi.begin(ssid,pass);
  pinMode(D7,INPUT);
  pinMode(D6,OUTPUT);
  while(WiFI.status() != WL_CONNECTED ){
    delay(2000);
    Serial.print("..");
  }
  Serial.println("NodeMCU Connected!");
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(client);
}

void loop()
{
  int x = a=digitalRead(7);
  if(x!=HIGH)
    digitalWrite(6,HIGH);
  else
    digitalWrite(6,LOW);
  
  ThingSpeak.writeField(myChannelNumber,1,x,myAPIkey);
  
}
