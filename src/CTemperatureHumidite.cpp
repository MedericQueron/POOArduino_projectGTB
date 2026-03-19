#include "CTemperatureHumidite.h"
// Supposons utilisation de DHT11 ou DHT22, ajouter #include <DHT.h> si nécessaire
// Pour simplifier, simulation

CTemperatureHumidite::CTemperatureHumidite(int id, int pin) : CCapteur(id, pin) {
    _temperature = 0.0;
    _humidite = 0.0;
}

CTemperatureHumidite::~CTemperatureHumidite() {
    // Destructeur
}

void CTemperatureHumidite::initialiser() {
    // Initialisation du capteur DHT
    // dht.begin();
    _isConnected = true;
}

float CTemperatureHumidite::lireTemperature() {
    
}

float CTemperatureHumidite::lireHumidite() {
    
}