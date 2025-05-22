#ifndef PO_PROJEKT1_ZWIERZE_H
#define PO_PROJEKT1_ZWIERZE_H

#include "Organizm.h"

class Zwierze : public Organizm {
public:
    Zwierze(int sila, int inicjatywa, int x, int y, int wiek, Swiat& swiat);
    virtual ~Zwierze();

    virtual void akcja() override;
    virtual int kolizja(Organizm* organizm) override;
    virtual void rysowanie() const override;
    virtual Zwierze* rozmnoz(int x, int y) const = 0;
};


#endif //PO_PROJEKT1_ZWIERZE_H
