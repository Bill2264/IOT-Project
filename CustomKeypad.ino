
#include <HCSR04.h>
#include <DFRobot_DHT11.h>
DFRobot_DHT11 DHT;
#include <Keypad.h>
#define DHT11_PIN 10

const byte ROWS = 4;
const byte COLS = 3;

char hexaKeys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte triggerPin = 21;
byte echoPin = 12;

byte rowPins[ROWS] = {15, 2, 0, 4};
byte colPins[COLS] = {16, 17, 5};


Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
  HCSR04.begin(triggerPin, echoPin);
}
  
void loop(){
  
  keypad();
 
  temp();
 
 dist();
  delay(1000);
}
