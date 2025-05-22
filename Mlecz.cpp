#include "Mlecz.h"

#define iloscProb 3

Mlecz::Mlecz(int x, int y, int wiek, Swiat& swiat) : Roslina(0, 0, x, y, wiek, swiat) {symbol='M';}

Mlecz::~Mlecz() {}

void Mlecz::akcja() {
    cout << "Mlecz";
    for(int i = 0; i<iloscProb; i++){
        Roslina::akcja();
    }
}

int Mlecz::kolizja(Organizm* organizm) {
    return Roslina::kolizja(organizm);
}

Mlecz* Mlecz::rozmnoz(int x, int y) const {
    return new Mlecz(x, y, 0, swiat);
}
