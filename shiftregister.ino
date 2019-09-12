
/*
Adafruit Arduino - Lesson 4. 8 LEDs and a Shift Register
*/
 
int latchPin = 5;
int clockPin = 6;
int dataPin = 4;
int potPin = A0;
int potvalue= 0;
int outputpin = 3;
 
byte leds = 0;
 
void setup() 

{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
  Serial.begin(9600);
}
 
void loop() 
{
  potvalue = analogRead(potPin);

  leds = 0;
  Serial.println(potvalue);
  setBrightness(potvalue/4);
  updateShiftRegister();
  for (int i = 0; i<8;i++)
  {
    bitSet(leds, i);
    updateShiftRegister();
  }
 delay(50);
}


void setBrightness(byte brightness){
  analogWrite(3, 255-brightness);
}

void updateShiftRegister()
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, leds);
   digitalWrite(latchPin, HIGH);
} 
