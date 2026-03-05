

String getTemp() {
  DHT.read(DHT11_PIN);
  float temp = DHT.temperature; // Read temperature
  
  
  // Return as a string with 1 decimal place
  return String(temp, 1);
}


String getHumid() {
  DHT.read(DHT11_PIN);
  float humid = DHT.humidity; // Read humidity
  
  

  return String(humid, 0);
}