#include "CLuminosite.h"

CLuminosite::CLuminosite(int id, int pin) : CCapteur(id, pin) {
    _pinMode = INPUT;
}

CLuminosite::~CLuminosite() {
    // Destructeur
}

void CLuminosite::initialiser() {
    pinMode(_pin, _pinMode);
    _isConnected = true;
}

float CLuminosite::lireLuminosite() {
    
}