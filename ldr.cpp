#include "ldr.h"
#include "Arduino.h"
#include "main.h"

void init_ldr(void)
{
   pinMode(GARDEN_LIGHT, OUTPUT);
   
}
void brightness_control(void)
{
  unsigned int ldr_val;
   /* to read the values from ldr sensor connected to A0 pin */
  ldr_val = analogRead(LDR_SENSOR);

  /* mapping 0 to 1023 to 0 to 255 */ // by dividing by 4
  /* scaling down 0 to 1023 -> 255 to 0 */
  // resistance and voltage is reverse . so 1023 - V = R
  ldr_val = (1023 - ldr_val) / 4;

  // assign duty cycle to LED based on LDR value
  analogWrite(GARDEN_LIGHT, ldr_val);
  delay(100);
}
