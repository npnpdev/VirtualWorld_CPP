#include "Wilcze_jagody.h"

Wilcze_jagody::Wilcze_jagody(int x, int y, int wiek, Swiat& swiat) : Roslina(99, 0, x, y, wiek, swiat) {symbol='J';}

Wilcze_jagody::~Wilcze_jagody() {}

void Wilcze_jagody::akcja() {
    cout << "Wilcze jagody";
    Roslina::akcja();
}

int Wilcze_jagody::kolizja(Organizm* organizm) {
    if (organizm->getInicjatywa() != 0) {
        swiat.usunOrganizm(organizm->getX(), organizm->getY());
        swiat.usunOrganizm(this->getX(), this->getY());

        cout << " Zjadl wilcze jagody i zginal!" << endl;
        return 2;
    }

    return Roslina::kolizja(organizm);
}

Wilcze_jagody* Wilcze_jagody::rozmnoz(int x, int y) const {
    return new Wilcze_jagody(x, y, 0, swiat);
}