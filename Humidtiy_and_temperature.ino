void temp()
{
  DHT.read(DHT11_PIN);
  Serial.print("temp:");
  Serial.print(DHT.temperature);
  Serial.print("  humi:"); 
  Serial.println(DHT.humidity);
}

float getTemp() {
   DHT.read(DHT11_PIN);
   return DHT.temperature;
}
int getHumid() {
   DHT.read(DHT11_PIN);
   return DHT.humidity;
}
