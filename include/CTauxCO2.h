#ifndef CTauxCO2_H
#define CTauxCO2_H

#include "CCapteur.h"

class CTauxCO2 : public CCapteur {
public:
    CTauxCO2(int id, int pin);
    ~CTauxCO2();
    void initialiser() override;
    float lireTauxCO2();
};

#endif