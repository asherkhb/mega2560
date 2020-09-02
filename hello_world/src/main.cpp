/*
 * Hello World (Blink)
 * Blink the builtin LED to spell "hello world" in morse code.
 */

#include <Arduino.h>
#include <Morse.h>

String message = "hello world";
int message_length = message.length();

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  for (int i = 0; i < message_length; i++)
  {
    morse_encoder(message[i]);
  }
}
