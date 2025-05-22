#ifndef PO_PROJEKT1_ANTYLOPA_H
#define PO_PROJEKT1_ANTYLOPA_H

#include "Zwierze.h"

class Antylopa : public Zwierze {
public:
    Antylopa(int x, int y, int wiek, Swiat& swiat);
    ~Antylopa();

    virtual void akcja() override;
    virtual int kolizja(Organizm* organizm) override;
    virtual Antylopa* rozmnoz(int x, int y) const override;

private:
    void przesunNaNiezajeteSasiedniePole();
};

#endif
