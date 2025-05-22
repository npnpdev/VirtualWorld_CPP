#ifndef PO_PROJEKT1_GUARANA_H
#define PO_PROJEKT1_GUARANA_H

#include "Roslina.h"

class Guarana : public Roslina {
public:
    Guarana(int x, int y, int wiek, Swiat& swiat);
    ~Guarana();

    virtual void akcja() override;
    virtual int kolizja(Organizm* organizm) override;
    virtual Guarana* rozmnoz(int x, int y) const override;
};

#endif //PO_PROJEKT1_GUARANA_H
