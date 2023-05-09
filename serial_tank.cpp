#include "HardwareSerial.h"
#include "serial_tank.h"
#include "Arduino.h"
#include "main.h"

unsigned int volume_value;
unsigned char valueh, valuel;

void init_serial_tank(void) 
{
  // to begin the serial commmunication
  // between serial tank and arduino board
    Serial.begin(19200);
    Serial.write(0xFF); //sincroniza comunicação
    Serial.write(0xFF);
    Serial.write(0xFF);   
}

unsigned int volume(void)
{
  /* to readthe volume of water */
  Serial.write(VOLUME);
  /*wait for data*/
   while(!Serial.available());
   valueh = Serial.read();
   while(!Serial.available());
   valuel = Serial.read();
  /*combing Higher byte and lower Byte*/
  volume_value = valueh << 8 | valuel;
  
  // return the volume of the water
  return volume_value;

}

void enable_inlet(void)
{
  Serial.write(INLET_VALVE);
  Serial.write(ENABLE);
}  
void disable_inlet(void)
{
  Serial.write(INLET_VALVE);
  Serial.write(DISABLE);
}  
void enable_outlet(void)
{  
  Serial.write(OUTLET_VALVE);
  Serial.write(ENABLE);    
}
void disable_outlet(void)
{  
  Serial.write(OUTLET_VALVE);
  Serial.write(DISABLE);      
}
