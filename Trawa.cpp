#include "Trawa.h"

Trawa::Trawa(int x, int y, int wiek, Swiat& swiat) : Roslina(0, 0, x, y, wiek, swiat) {symbol='T';}

Trawa::~Trawa() {}

void Trawa::akcja() {
    cout << "Trawa";
    Roslina::akcja();
}

int Trawa::kolizja(Organizm* organizm) {
    return Roslina::kolizja(organizm);
}

Trawa* Trawa::rozmnoz(int x, int y) const {
    return new Trawa(x, y, 0, swiat);
}

