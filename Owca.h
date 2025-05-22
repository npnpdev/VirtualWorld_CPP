#ifndef PO_PROJEKT1_OWCA_H
#define PO_PROJEKT1_OWCA_H

#include "Zwierze.h"

class Owca : public Zwierze {
public:
    Owca(int x, int y, int wiek, Swiat& swiat);
    ~Owca();

    virtual void akcja() override;
    virtual int kolizja(Organizm* organizm) override;
    virtual Owca* rozmnoz(int x, int y) const override;
};

#endif
