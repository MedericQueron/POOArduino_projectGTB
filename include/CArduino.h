#ifndef CArduino_H
#define CArduino_H

#include "CCapteur.h"
#include "CTemperatureHumidite.h"
#include "CLuminosite.h"
#include "CTauxCO2.h"

class CArduino {
private:
    CTemperatureHumidite* _tempHum;
    CLuminosite* _lum;
    CTauxCO2* _co2;

public:
    CArduino();
    ~CArduino();
    void setUp();
    void loop();
    void initialiser();
    void envoyerDonnées();
};

#endif