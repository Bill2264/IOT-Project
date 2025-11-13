void dist()
{
   double* distances = HCSR04.measureDistanceCm();
  Serial.print("1: ");
  Serial.print(distances[0]);
  Serial.println(" cm");
  
  Serial.println("---");
}