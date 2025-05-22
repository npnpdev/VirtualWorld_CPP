#ifndef PO_PROJEKT1_LIS_H
#define PO_PROJEKT1_LIS_H

#include "Zwierze.h"

class Lis : public Zwierze {
public:
    Lis(int x, int y, int wiek, Swiat& swiat);
    ~Lis();

    virtual void akcja() override;
    virtual int kolizja(Organizm* organizm) override;
    virtual Lis* rozmnoz(int x, int y) const override;
};

#endif
