void temp()
{
  DHT.read(DHT11_PIN);
  Serial.print("temp:");
  Serial.print(DHT.temperature);
  Serial.print("  humi:"); 
  Serial.println(DHT.humidity);
}