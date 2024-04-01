#include <LiquidCrystal.h>
const int trigPin = 10; 
const int echoPin = 9; 
const int redLedPin1 = 8; 
const int redLedPin2 = 7; 
const int buzzerPin = 13; 
LiquidCrystal lcd(12, 11, 6, 5, 4, 3 ); 
void setup() {
Serial.begin(9600); 
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(redLedPin1, OUTPUT);
pinMode(redLedPin2, OUTPUT);
pinMode(buzzerPin, OUTPUT);
lcd.begin(16, 2); 
lcd.print("Parking Sensor");
delay(500);
lcd.clear();
}
void loop() {
long duration,distance;
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration / 2) / 29.1;
if (distance <10){
tone(buzzerPin, 1000); 
lcd.setCursor(0, 0);
lcd.print("You are about to");
lcd.setCursor(0, 1);
lcd.print("hit the rear!");
Serial.println("You are about to hit the rear!");
Serial.print(distance);
  Serial.println(" cm");
for (int i = 0; i < 1; i++) {
digitalWrite(redLedPin1, HIGH);
digitalWrite(redLedPin2, HIGH);
delay(100);
digitalWrite(redLedPin1, LOW);
digitalWrite(redLedPin2, LOW);
delay(100);
}
} else {
noTone(buzzerPin); 
lcd.clear(); 
digitalWrite(redLedPin1, LOW); 
digitalWrite(redLedPin2, LOW);
Serial.println("Safe distance");
Serial.print(distance);
  Serial.println(" cm");
}
delay(500);
}
