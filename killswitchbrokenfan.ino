/*
Adafruit Arduino - Lesson 15. Bi-directional Motor
*/

//#include <LiquidCrystal.h>              //include the LiquidCrystal library
//
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
int enablePin = 11;
int in1Pin = 10;
int in2Pin = 9;
int switchPin = 7;
int potPin = A0;
int killswitch = 4;
int redlight = 6;
int greenlight = 5;
 
void setup()
{
//  lcd.begin(16, 2);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(enablePin, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP);
  pinMode(killswitch, INPUT_PULLUP);
  pinMode(redlight, OUTPUT);
  pinMode(greenlight, OUTPUT);
  Serial.begin(9600);
}
 
void loop()
{
  int speed = analogRead(potPin) / 4;
  boolean reverse = digitalRead(switchPin);
  int iskilled = digitalRead(killswitch);
  Serial.println(iskilled);
  if (iskilled >=1){
    digitalWrite(redlight, HIGH);
    digitalWrite(greenlight, HIGH);
    setMotor(0, reverse);
  } else {
    digitalWrite(greenlight, HIGH);
    digitalWrite(redlight, LOW);
    setMotor(speed, reverse);
  }
}
 
void setMotor(int speed, boolean reverse)
{
  analogWrite(enablePin, speed);
  digitalWrite(in1Pin, ! reverse);
  digitalWrite(in2Pin, reverse);
}
