//VTM https://www.youtube.com/c/VTMVlogVoThongMinh
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);
#include "MQ135.h"    //gọi thư viện MQ135
#include "DHT.h"      //gọi thư viện DHT11
#define PIN_MQ135 A2
MQ135 mq135_sensor = MQ135(PIN_MQ135);
const int DHTPIN = 2;       //Đọc dữ liệu từ DHT11 ở chân 2 trên mạch Arduino
const int DHTTYPE = DHT11;  //Khai báo loại cảm biến, có 2 loại là DHT11 và DHT22
DHT dht(DHTPIN, DHTTYPE);
///////////////////////////////////////
void setup() {
  Serial.begin(9600);
  dht.begin();         // Khởi động cảm biến
  lcd.init();
  lcd.backlight();
  lcd.setCursor(4, 0);
  lcd.print("SMART GARDEN");
}
////////////////////////////////////////
void loop() {
  float humidity = dht.readHumidity();    //Đọc độ ẩm
  float temperature = dht.readTemperature(); //Đọc nhiệt độ
  float ppm = mq135_sensor.getPPM();
  lcd.setCursor(0, 1);
  lcd.print("Nhiet do:");
  lcd.setCursor(11, 1);
  lcd.print(temperature);
  lcd.setCursor(15, 1);
  lcd.print("(C)");
  lcd.setCursor(0, 2);
  lcd.print("Do am:");
  lcd.setCursor(11, 2);
  lcd.print(humidity);
  lcd.setCursor(15, 2);
  lcd.print("(%)");
  lcd.setCursor(0, 3);
  lcd.print("Khong khi:");
  lcd.setCursor(11, 3);
  lcd.print(ppm);
  lcd.setCursor(15, 3);
  lcd.print("(ppm)");
  delay(500);
}
