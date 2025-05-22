#include "Zolw.h"

#define szansaNaZmianePozycji 25 // W procentach

Zolw::Zolw(int x, int y, int wiek, Swiat& swiat) : Zwierze(2, 1, x, y, wiek, swiat) {symbol='Z';}

Zolw::~Zolw() {}

void Zolw::akcja() {
    cout << "Zolw";

    if (rand() % 100 < szansaNaZmianePozycji) {
        Zwierze::akcja();
    }
    else {
        cout << " nie przemiescil sie w tej turze" << endl;
    }
}

int Zolw::kolizja(Organizm* organizm) {
    if (organizm != nullptr && organizm->getSila() < 5 && organizm->getSymbol()!='Z') {
        // Napastnik ma mniejszą siłę niż 5, więc musi wrócić na swoje poprzednie pole
        int poprzedni_x = organizm->getX();
        int poprzedni_y = organizm->getY();

        swiat.usunOrganizm(organizm->getX(), organizm->getY());

        // Przywrócenie napastnika na jego poprzednie pole
        swiat.dodajOrganizm(organizm, poprzedni_x, poprzedni_y);

        cout << " zostal odepchniety przez zolwia na jego poprzednie pole." << endl;
        return 2;
    }
    else{
        return Zwierze::kolizja(organizm);
    }
}

Zolw* Zolw::rozmnoz(int x, int y) const {
    return new Zolw(x, y, 0, swiat);
}
