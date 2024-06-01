#include <dht11.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 4);

#define humidity_temp_pin_1 2
#define humidity_temp_pin_2 3
#define humidity_temp_pin_3 4

dht11 humidity_temp_1;
dht11 humidity_temp_2;
dht11 humidity_temp_3;

int land_sensor_pin = 5;

int land_sensor_data;

int fan_relay = 13;
int nasos_relay = 12;

void  setup()
{
  Wire.begin();
  lcd.begin();
  pinMode(land_sensor_pin, INPUT);
  pinMode(fan_relay, OUTPUT);
  pinMode(nasos_relay, OUTPUT);
  Serial.begin(9600);
 
}

void loop()
{
  Serial.println();

  int chk1 = humidity_temp_1.read(humidity_temp_pin_1);
  int chk2 = humidity_temp_2.read(humidity_temp_pin_2);
  int chk3 = humidity_temp_3.read(humidity_temp_pin_3);

  Serial.print("Humidity 1 (%): ");
  Serial.println((float)humidity_temp_1.humidity, 2);

  Serial.print("Humidity 2 (%): ");
  Serial.println((float)humidity_temp_2.humidity, 2);

  Serial.print("Humidity 3 (%): ");
  Serial.println((float)humidity_temp_3.humidity, 2);

  Serial.print("Temperature 1  (C): ");
  Serial.println((float)humidity_temp_1.temperature, 2);

  Serial.print("Temperature 2  (C): ");
  Serial.println((float)humidity_temp_2.temperature, 2);

  Serial.print("Temperature 3  (C): ");
  Serial.println((float)humidity_temp_3.temperature, 2);

  land_sensor_data = digitalRead(land_sensor_pin);

//  if (land_sensor_data = true) {
//    Serial.print("Torpaq nəmliyi 1: ");
//    Serial.println(land_sensor_data);
//  } else {
//      Serial.print("Torpaq nəmliyi yoxdur: ");
//      Serial.println(land_sensor_data);  
//  }

//  lcd.clear();
//  lcd.setCursor(0, 0);
//  lcd.print("Nəmlik sensoru № 1 (%): ");
//  lcd.setCursor(0, 1);
//  lcd.print((float)humidity_temp_1.humidity);

//  digitalWrite(nasos_relay, HIGH);
//  delay(1000);
//  digitalWrite(nasos_relay, LOW);

  delay(1000);

}
