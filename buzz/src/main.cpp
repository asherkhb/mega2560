#include <Arduino.h>
#include <pitches.h>

#define BUZZER 11   // active buzzer 

int melody[] = { NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6 };
int duration = 500;

void setup() {
  // Turn off builtin LED
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  // Initialize Buzzer
  pinMode(BUZZER, OUTPUT);
}

void loop()
{
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    tone(BUZZER, melody[thisNote], duration);
    delay(1000);
  }
  delay(2000);
}
