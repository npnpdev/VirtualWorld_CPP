#ifndef PO_PROJEKT1_TRAWA_H
#define PO_PROJEKT1_TRAWA_H

#include "Roslina.h"

class Trawa : public Roslina {
public:
    Trawa(int x, int y, int wiek, Swiat& swiat);
    ~Trawa();

    virtual void akcja() override;
    virtual int kolizja(Organizm* organizm) override;
    virtual Trawa* rozmnoz(int x, int y) const override;
};

#endif //PO_PROJEKT1_TRAWA_H
