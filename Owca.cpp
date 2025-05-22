#include "Owca.h"

Owca::Owca(int x, int y, int wiek, Swiat& swiat) : Zwierze(4, 4, x, y, wiek, swiat) {symbol='O';}

Owca::~Owca() {}

void Owca::akcja() {
    cout << "Owca";
    Zwierze::akcja();
}

int Owca::kolizja(Organizm* organizm) {
    return Zwierze::kolizja(organizm);
}

Owca* Owca::rozmnoz(int x, int y) const {
    return new Owca(x, y, 0, swiat);
}