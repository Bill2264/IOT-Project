

String getTemp() {
  DHT.read(DHT11_PIN);
  float temp = DHT.temperature; // Read temperature
  Serial.println("DHT11 Temperature: " + String(temp, 1) + " °C");
  
  // Return as a string with 1 decimal place
  return String(temp, 1);
}


String getHumid() {
  DHT.read(DHT11_PIN);
  float humid = DHT.humidity; // Read humidity
  Serial.println("DHT11 Humidity: " + String(humid, 0) + " %");
  

  return String(humid, 0);
}