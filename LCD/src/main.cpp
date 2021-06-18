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
#include <MFRC522.h>
#include <SPI.h>

// Initialize LiquidCrystal LCD (16 pin w/ Hitachi HD44780 driver)
const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Initialize MFRC522 instance
const int ss = 53, rst = 5; 
MFRC522 mfrc522(ss, rst);

void setup() {
  lcd.begin(16, 2);  // 16 col x 2 row LCD
  lcd.setCursor(0, 0);
  lcd.print("Badge Scanner:");

  SPI.begin();
  mfrc522.PCD_Init();
}

void loop() {
  lcd.setCursor(0, 1);

  // Look for new cards, and select one if present
  if ( ! mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial() ) {
    delay(50);
    lcd.print("No Badge Present");
    return;
  }

  // Print UID
  lcd.print("                ");  // Clear line
  lcd.setCursor(0, 1);
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    lcd.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    lcd.print(mfrc522.uid.uidByte[i], HEX);
  } 

  delay(1000);
}

