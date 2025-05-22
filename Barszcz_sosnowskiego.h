#ifndef PO_PROJEKT1_BARSZCZ_SOSNOWSKIEGO_H
#define PO_PROJEKT1_BARSZCZ_SOSNOWSKIEGO_H

#include "Roslina.h"

class Barszcz_sosnowskiego: public Roslina {
public:
    Barszcz_sosnowskiego(int x, int y, int wiek, Swiat& swiat);
    ~Barszcz_sosnowskiego();

    virtual void akcja() override;
    virtual int kolizja(Organizm* organizm) override;
    virtual Barszcz_sosnowskiego* rozmnoz(int x, int y) const override;
};

#endif //PO_PROJEKT1_BARSZCZ_SOSNOWSKIEGO_H
