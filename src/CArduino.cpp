#include "CArduino.h"

CArduino::CArduino() {
    _tempHum = new CTemperatureHumidite(1, 2); // ID 1, pin 2
    _lum = new CLuminosite(2, A0); // ID 2, pin A0
    _co2 = new CTauxCO2(3, A1); // ID 3, pin A1
}

CArduino::~CArduino() {
    delete _tempHum;
    delete _lum;
    delete _co2;
}

void CArduino::setUp() {
    initialiser();
}

void CArduino::loop() {
    // Lire les données des capteurs
    float temp = _tempHum->lireTemperature();
    float hum = _tempHum->lireHumidite();
    float lum = _lum->lireLuminosite();
    float co2 = _co2->lireTauxCO2();

    // Envoyer les données
    envoyerDonnées();
}

void CArduino::initialiser() {
    _tempHum->initialiser();
    _lum->initialiser();
    _co2->initialiser();
    Serial.begin(9600);
}

void CArduino::envoyerDonnées() {
    Serial.print("Temp: "); Serial.print(_tempHum->getValue(0)); Serial.println(" C");
    Serial.print("Hum: "); Serial.print(_tempHum->getValue(1)); Serial.println(" %");
    Serial.print("Lum: "); Serial.print(_lum->getValue(0)); Serial.println(" lux");
    Serial.print("CO2: "); Serial.print(_co2->getValue(0)); Serial.println(" ppm");
    delay(2000);
}