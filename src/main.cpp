#include <Arduino.h>

#define red_led 7
#define green_led 8
#define blue_led 9

unsigned long last_time_red;
unsigned long last_time_green;
unsigned long last_time_blue;

int blue_brightness = 0;
int fade_amount = 5;

void setup()
{
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(blue_led, OUTPUT);
}

void loop()
{
  if (millis() - last_time_red > 200)
  {
    last_time_red = millis();
    digitalWrite(red_led, !digitalRead(red_led));
  }

  if (millis() - last_time_green > 1000)
  {
    last_time_green = millis();
    digitalWrite(green_led, !digitalRead(green_led));
  }

  if (millis() - last_time_blue > 15)
  {
    last_time_blue = millis();

    blue_brightness += fade_amount;

    if (blue_brightness <= 0 || blue_brightness >= 255)
    {
      fade_amount = -fade_amount;
    }

    analogWrite(blue_led, blue_brightness);
  }
}
