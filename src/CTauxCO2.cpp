#include "CTauxCO2.h"

CTauxCO2::CTauxCO2(int id, int pin) : CCapteur(id, pin) {
    _pinMode = INPUT;
}

CTauxCO2::~CTauxCO2() {
    // Destructeur
}

void CTauxCO2::initialiser() {
    pinMode(_pin, _pinMode);
    _isConnected = true;
}

float CTauxCO2::lireTauxCO2() {
    
    
}