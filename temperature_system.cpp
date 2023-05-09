#include "temperature_system.h"
#include "Arduino.h"
#include "main.h"


void init_temperature_system(void)
{
  // to init heater and cooler pin as output pin
  pinMode(HEATER, OUTPUT);
  pinMode(COOLER, OUTPUT);
  
  // to turn off the heater and cooler pins initially
  digitalWrite(HEATER, LOW);
  digitalWrite(COOLER, LOW);
}

float read_temperature(void)
{
  float temperature;
  /*  // to read values from 0 to 1023
   // convert adc to voltage 
  // convert voltage into temp */
  temperature = (((analogRead(TEMPERATURE_SENSOR) * (float) 5/1024)) / (float) 0.01);
  return temperature;
}

// function to control the cooler
void cooler_control(bool control)
{
   if(control){
     digitalWrite(COOLER, HIGH);
   }else{
     digitalWrite(COOLER, LOW);
   }
}
void heater_control(bool control)
{
    if(control){
     digitalWrite(HEATER, HIGH);
   }else{
     digitalWrite(HEATER, LOW);
   }
}
