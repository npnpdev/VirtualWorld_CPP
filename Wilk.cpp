#include "Wilk.h"

Wilk::Wilk(int x, int y, int wiek, Swiat& swiat) : Zwierze(9, 5, x, y, wiek, swiat) {symbol='W';}

Wilk::~Wilk() {}

void Wilk::akcja() {
    cout << "Wilk";
    Zwierze::akcja();
}

int Wilk::kolizja(Organizm* organizm) {
    return Zwierze::kolizja(organizm);
}

Wilk* Wilk::rozmnoz(int x, int y) const {
    return new Wilk(x, y, 0, swiat);
}

