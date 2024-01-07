#include<ESP8266WiFi.h>
#include<ThingSpeak.h>
#include<DTH.h>

const char *ssid = "Hello_123";
const char *pass = "1234";

DTH dht(D3,DHT11);
WiFiClient client;

long myChannelNumber = 2345673;
const char myAPIkey[] = "FGSR36VG3GFGDG";


void setup()
{
  Serial.begin(9600);
  WiFi.begin(ssid,pass);
 
  while(WiFI.status() != WL_CONNECTED ){
    delay(2000);
    Serial.print("..");
  }
  Serial.println("NodeMCU Connected!");
  Serial.println(WiFi.localIP());
  dht.begin();
  ThingSpeak.begin(client);
}

void loop()
{
  float Humidity = dht.readHumidity();
  float Temperature = dht.readTemperature();
  
  Serial.println("Humidity : "+(String)Humidity);
  Serial.println("Temperature : "+(String)Temperature);
  
  ThingSpeak.writeField(myChannelNumber,1,Humidity,myAPIkey);
  ThingSpeak.writeField(myChannelNumber,2,Temperature,myAPIkey);
  
}
