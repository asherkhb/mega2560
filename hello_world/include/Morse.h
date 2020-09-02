/* Builtin LED Morse Encoder
 * Timing Rules:
 * - Time Unit (tu) = 250ms
 * - Dot = 1tu, Dash = 3tu, Spacing = 1tu
 * - Letter Spacing = 3tu, Word Spacing = 7tu
 */

#include <Arduino.h>

void msg(int on, int off)
{
  digitalWrite(LED_BUILTIN, HIGH);  // set LED voltage to HIGH, 5v (on)
  delay(on);  // wait for "on" duration
  digitalWrite(LED_BUILTIN, LOW);  // set LED voltage to LOW, 0v (ground) (off)
  delay(off);  // wait for "off" duration
}

void dot()
{
  msg(250, 250);
}

void dash()
{
  msg(750, 250);
}

void morse_encoder(char letter)
{
  switch (letter)
  {
    case 'd': dash(); dot(); dot(); break;
    case 'e': dot(); break;
    case 'h': dot(); dot(); dot(); dot(); break;
    case 'l': dot(); dash(); dot(); dot(); break;
    case 'o': dash(); dash(); dash(); break;
    case 'r': dot(); dash(); dot(); break;
    case 'w': dot(); dash(); dash(); break;
    case ' ': delay(1000); break;
  };
  delay(750);
}
