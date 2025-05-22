#ifndef PO_PROJEKT1_ZOLW_H
#define PO_PROJEKT1_ZOLW_H

#include "Zwierze.h"

class Zolw : public Zwierze {
public:
    Zolw(int x, int y, int wiek, Swiat& swiat);
    ~Zolw();

    virtual void akcja() override;
    virtual int kolizja(Organizm* organizm) override;
    virtual Zolw* rozmnoz(int x, int y) const override;
};

#endif
