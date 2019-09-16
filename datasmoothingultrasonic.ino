/*
Adafruit Arduino - Lesson 9. Light sensing
Tutorial for Ultrasonic: https://randomnerdtutorials.com/complete-guide-for-ultrasonic-sensor-hc-sr04/
*/
 
int lightPin = 0;
int latchPin = 5;
int clockPin = 6;
int dataPin = 4;
int triggerPin = 11;
int echoPin = 12;
int buzzerPin = 9;
 
int leds = 0;
 
void setup() 
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}
 
void loop() 
{
  int durationtoav = 0;
  for (int i = 0; i<10; i++){
    digitalWrite(triggerPin, LOW);
    delay(2);
    digitalWrite(triggerPin, HIGH);
    delay(2);
    digitalWrite(triggerPin, LOW);
  
    int ultraduration = pulseIn(echoPin, HIGH);
    durationtoav += ultraduration;
  }

  float ultradurationaverage = durationtoav/10;
  int reading  = analogRead(lightPin);
   int numLEDSLit = reading / 57;  //1023 / 9 / 2
   if (numLEDSLit > 8) numLEDSLit = 8;
   leds = 0;   // no LEDs lit to start
   for (int i = 0; i < numLEDSLit; i++)    {
      leds = leds + (1 << i);  // sets the i'th bit
    }
    setBrightness((ultradurationaverage/74));
    tone(buzzerPin, ultradurationaverage/50);
    updateShiftRegister();
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
