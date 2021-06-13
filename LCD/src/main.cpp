/*
  LiquidCrystal Library - Temperature Display

  Use a termistor to measure temp, and display on LCD screen.

  Circuit:
  - Analog Pins: Thermistor
  - Digital Pins: RS, E, D4, D5, D6, D7
  - Ground: RW, VSS, K, Thermistor (w/ 10k resistor)
  - 5V: VDD, A, Thermistor
  - 10K Potentiometer : V0 (1 ground, 1 5V)
 */

#include <Arduino.h>
#include <LiquidCrystal.h>


const int temp = 0; // Temp Analog Sensor Pin
// Initialize LiquidCrystal LCD (16 pin w/ Hitachi HD44780 driver)
const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);  // 16 col x 2 row LCD
  lcd.setCursor(2, 0);
  lcd.print("Temperature:");
  lcd.setCursor(10, 1);
  lcd.print("F");
}

void loop() {
  int tempReading = analogRead(temp);

  // Conversion from Elegoo lesson code (quality unknown)
  double tempK = log(10000.0 * ((1024.0 / tempReading - 1)));
  tempK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * tempK * tempK )) * tempK );
  float tempC = tempK - 273.15;
  float tempF = (tempC * 9.0)/ 5.0 + 32.0;

  lcd.setCursor(5, 1);
  lcd.print(tempF);
  
  delay(500);
}

