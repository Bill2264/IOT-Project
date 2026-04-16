char keycode []= {'1','2','3','4'};
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
  if(customKey=='*')
  {tone(BUZZZER_PIN,500, 1000);}
  else if(customKey){
      if (customKey==keycode[count]){
        correct++;
      }
      tone(BUZZZER_PIN,1000, 20);
      count++;
      Serial.println("*");
      if(count==4)
      {
        if(correct==count)
      {
        Serial.println("Password Correct, door open");
        countdown = 30;
        
        tone(BUZZZER_PIN,1000, 1000);
        }
      else
      {
        Serial.println("Password Incorrect, door closed");
        tone(BUZZZER_PIN,2000, 100);
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
