#ifndef PO_PROJEKT1_WILCZE_JAGODY_H
#define PO_PROJEKT1_WILCZE_JAGODY_H

#include "Roslina.h"

class Wilcze_jagody : public Roslina {
public:
    Wilcze_jagody(int x, int y, int wiek, Swiat& swiat);
    ~Wilcze_jagody();

    virtual void akcja() override;
    virtual int kolizja(Organizm* organizm) override;
    virtual Wilcze_jagody* rozmnoz(int x, int y) const override;
};

#endif //PO_PROJEKT1_WILCZE_JAGODY_H
