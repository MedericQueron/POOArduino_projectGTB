#ifndef CTemperatureHumidite_H
#define CTemperatureHumidite_H

#include "CCapteur.h"

class CTemperatureHumidite : public CCapteur {
private:
    float _temperature;
    float _humidite;

public:
    CTemperatureHumidite(int id, int pin);
    ~CTemperatureHumidite();
    void initialiser() override;
    float lireTemperature();
    float lireHumidite();
};

#endif