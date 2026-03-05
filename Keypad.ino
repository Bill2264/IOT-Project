char* keycode = "1234";
char* check ="0000";
//password check
int count = 0,correct = 0;
int countdown = 0;
String doorstatus;
void doorUnlockTimer()
{
  if(countdown>0)
  {
    doorstatus = "Door is Open";
  }
  else{
    doorstatus = "Door is Closed";
  }
  countdown--;
}
void keypad()
{
  char customKey = customKeypad.getKey();
  if(customKey)
    {
      if (customKey==keycode[count]){
        correct++;
      }
      count++;
      Serial.println("*");
      if(count==4)
      {
        if(correct==count)
      {
        Serial.println("Password Correct, door open");
        countdown = 30;
        }
      else
      {
        Serial.println("Password Incorrect, door closed");
      }
      count =0;
      correct=0;
      }
    }
}
String getStatus()
{
  return String(doorstatus);
}