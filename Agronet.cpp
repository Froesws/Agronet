#include "Arduino.h"
#include "Agronet.h"



void AgronetClass::beginSensor(sensor sensorMode, int16_t pinSelect) {
   if (sensorMode < M) {
        _pinSensor[sensorMode] = pinSelect; 
   } 
}


float AgronetClass::readDevice(sensor sensorMode){
  int16_t val;
  switch(sensorMode) {
    case TEMPERATURE:
    return readTemp(sensorMode);
    
    case LUMINOSITY:
        return analogRead(_pinSensor[sensorMode]);
    default:
        Serial.print("Undefined Sensor ");
        return 0; 
  }
}


float AgronetClass::readTemp(sensor sensorMode){
  int16_t val = analogRead(_pinSensor[sensorMode]);
  float R = (float)(1023-val)*10000/val;
  return 1/(log(R/10000)/B+1/298.15)-273.15;  
}

AgronetClass Agronet;

