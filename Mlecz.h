#ifndef PO_PROJEKT1_MLECZ_H
#define PO_PROJEKT1_MLECZ_H

#include "Roslina.h"

class Mlecz : public Roslina {
public:
    Mlecz(int x, int y, int wiek, Swiat& swiat);
    ~Mlecz();

    virtual void akcja() override;
    virtual int kolizja(Organizm* organizm) override;
    virtual Mlecz* rozmnoz(int x, int y) const override;
};

#endif //PO_PROJEKT1_MLECZ_H
