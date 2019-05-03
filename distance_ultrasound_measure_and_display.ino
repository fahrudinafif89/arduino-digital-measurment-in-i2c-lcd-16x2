
/***********************************************this program is made by mfahrudinafif89@gmail.com********************************************************
 *******************************more detail click:https://github.com/fahrudinafif89/arduino-digital-measurment-in-i2c-lcd-16x2***************************
 *****************************8**********************************inspired from any source****************************************************************/


int trigPin= 11;            // membuat varibel trig yang di set ke-pin 3
int echoPin= 12;            // membuat variabel echo yang di set ke-pin 2 
long durasi, jarak;     // membuat variabel durasi dan jarak
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//long duration;
//int distanceCm, distanceInch;

LiquidCrystal_I2C lcd(0x27, 16, 2);  //use the adrees of your i2c 
 
void setup() 
{
  pinMode(trigPin, OUTPUT);    // set pin trig menjadi OUTPUT
  pinMode(echoPin, INPUT);     // set pin echo menjadi INPUT
  
  lcd.begin();
  lcd.backlight();
  
  lcd.setCursor(5,0);
  lcd.print("DIGITAL");
  lcd.setCursor(3,1);
  lcd.print("MEASURMENT");
  delay(3000);lcd.clear();
}
 
void loop() 
{
  long duration, inches, cm, mm;
  pinMode(trigPin, OUTPUT); 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(200); 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(100); 
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT); 
  duration = pulseIn(echoPin, HIGH);
  
  inches = microsecondsToInches(duration); 
  cm = microsecondsToCentimeters(duration);
  mm = microsecondsToMillimeters(duration);
  
  lcd.setCursor(0,0);
  lcd.print("distance:");
  
  lcd.setCursor(10,0);
  lcd.print(inches); 
  lcd.print(" in  "); 
  lcd.print("   ");
  
  lcd.setCursor(0,1);
  lcd.print(cm);
  lcd.print(" cm ");
  lcd.print(" ");

  
  lcd.setCursor(11,1);
  lcd.print(mm);
  lcd.print(" mm ");
  lcd.print(" ");
  
  delay(100);
}

long microsecondsToInches(long microseconds)
{
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}
long microsecondsToMillimeters(long microseconds)
{
  return microseconds / 2.9 / 2;
}
