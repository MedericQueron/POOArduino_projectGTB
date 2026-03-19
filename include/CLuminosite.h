#ifndef CLuminosite_H
#define CLuminosite_H

#include "CCapteur.h"

class CLuminosite : public CCapteur {
public:
    CLuminosite(int id, int pin);
    ~CLuminosite();
    void initialiser() override;
    float lireLuminosite();
};

#endif