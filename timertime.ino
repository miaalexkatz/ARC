/*/*
Adafruit Arduino - Lesson 14. Knob
*/
 
#include <Servo.h> 
 
int potPin = 0;  
int servoPin = 9;
int buzzerPin = 11;
Servo servo; 
 
void setup() 
{ 
  Serial.begin(9600);
  servo.attach(servoPin);  
  pinMode(buzzerPin, OUTPUT);

  Serial.println("Please enter a duration (in seconds)");
  
} 


void loop() 
{
  if (Serial.available())
  {
    float time = Serial.read()-48;
    Serial.println(time);
    float angled = (time/180);
    Serial.println(angled);
    servo.write(0);
    int addtoservo = 0;

    for (int i = 0; i<180; i++){
      delay(angled*1000);
      addtoservo += 1;
      servo.write(addtoservo);
    }
    Serial.println("Timer complete!");
    tone(buzzerPin, 440, 1000);
  }
}
