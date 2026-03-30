#include "CTemperatureHumidite.h"


CTemperatureHumidite::CTemperatureHumidite(int id, int pin) : CCapteur(id, pin) {
    _temperature = 0.0;
    _humidite = 0.0;
}

CTemperatureHumidite::~CTemperatureHumidite() {

}

void CTemperatureHumidite::initialiser() {
    _isConnected = true;
}

float CTemperatureHumidite::lireTemperature() {
    
}

float CTemperatureHumidite::lireHumidite() {
    
}
