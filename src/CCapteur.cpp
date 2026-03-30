#include "CCapteur.h"

CCapteur::CCapteur(int id, int pin) : _id(id), _pin(pin), _isConnected(false), _pinMode(INPUT) {
    _value[0] = 0.0;
    _value[1] = 0.0;
}

CCapteur::~CCapteur() {
    // Destructeur
}

int CCapteur::getId() {
    return _id;
}

bool CCapteur::getIsConnected() {
    return _isConnected;
}

float CCapteur::getValue(int index) {
    if (index >= 0 && index < 2) {
        return _value[index];
    }
    return 0.0;
}

int CCapteur::getPin() {
    return _pin;
}

bool CCapteur::getPinMode() {
    return _pinMode;
}
