
/*
 * Agronet.h
 * 
 * Autor: William Froes
 * 
 * Novembro de 2020
 */

#ifndef Agronet_h
#define Agronet_h

#include "Arduino.h"

#define M 5 //  Numero de sensores

enum sensor {
    TEMPERATURE,
    LUMINOSITY,
    MOISTURE_AIR,
    PH_SOIL,
    MOISTURE_SOIL
};

class AgronetClass
{
  public:

    void beginSensor(sensor sensorMode, int16_t pinSelect);
    float readDevice(sensor sensorMode);

    float readTemp(sensor sensorMode);
  private:
    int16_t _pinSensor[M-1];
    const int16_t B = 3975; //Thermistor constant needed 
};
extern  AgronetClass Agronet;
#endif





