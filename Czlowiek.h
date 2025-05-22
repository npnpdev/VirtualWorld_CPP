#ifndef PO_PROJEKT1_CZLOWIEK_H
#define PO_PROJEKT1_CZLOWIEK_H

#include "Zwierze.h"

class Czlowiek : public Zwierze {
public:
    Czlowiek(int x, int y, int wiek, Swiat& swiat);
    ~Czlowiek();

    virtual void akcja() override;
    virtual int kolizja(Organizm* organizm) override;
    virtual Czlowiek* rozmnoz(int x, int y) const override;

    //gettery
    int getCzasUmiejetnosc() const {return licznikTur;}

    //settery
    void setCzasUmiejetnosci(int licznik){licznikTur=licznik;};
    void setUmiejetnosc(bool czyAktywna){umiejetnoscAktywna=czyAktywna;};

private:
    void przesunCzlowieka(int dx, int dy);
    bool umiejetnoscAktywna;
    int licznikTur = 0;
};
#endif //PO_PROJEKT1_CZLOWIEK_H
