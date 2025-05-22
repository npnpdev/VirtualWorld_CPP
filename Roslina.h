#ifndef PO_PROJEKT1_ROSLINA_H
#define PO_PROJEKT1_ROSLINA_H

#include "Organizm.h"

class Roslina : public Organizm {
public:
    Roslina(int sila, int inicjatywa, int x, int y, int wiek, Swiat& swiat);
    virtual ~Roslina();

    virtual void akcja() override;
    virtual int kolizja(Organizm* organizm) override;
    virtual Roslina* rozmnoz(int x, int y) const = 0;
    virtual void rysowanie() const override;
};


#endif //PO_PROJEKT1_ROSLINA_H
