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
 
int leds = 0;
 
void setup() 
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}
 
void loop() 
{
    digitalWrite(triggerPin, LOW);
    delay(5);
    digitalWrite(triggerPin, HIGH);
    delay(5);
    digitalWrite(triggerPin, LOW);
  
  int ultraduration = pulseIn(echoPin, HIGH);
  int reading  = analogRead(lightPin);
   int numLEDSLit = reading / 57;  //1023 / 9 / 2
   if (numLEDSLit > 8) numLEDSLit = 8;
   leds = 0;   // no LEDs lit to start
   for (int i = 0; i < numLEDSLit; i++)    {
      leds = leds + (1 << i);  // sets the i'th bit
    }
   setBrightness((ultraduration/30));
  Serial.println(ultraduration);
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
