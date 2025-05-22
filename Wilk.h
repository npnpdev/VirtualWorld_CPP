#ifndef PO_PROJEKT1_WILK_H
#define PO_PROJEKT1_WILK_H

#include "Zwierze.h"

class Wilk : public Zwierze {
public:
    Wilk(int x, int y, int wiek, Swiat& swiat);
    ~Wilk();

    virtual void akcja() override;
    virtual int kolizja(Organizm* organizm) override;
    virtual Wilk* rozmnoz(int x, int y) const override;
};

#endif //PO_PROJEKT1_WILK_H
