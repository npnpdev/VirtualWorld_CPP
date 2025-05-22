#include "Roslina.h"
#include "Zwierze.h"

#define szansaRozmnozenia 10 // Wartość procentowa

Roslina::Roslina(int sila, int inicjatywa, int x, int y, int wiek, Swiat& swiat)
        : Organizm(sila, inicjatywa, x, y, wiek, swiat) {}

Roslina::~Roslina() {}

void Roslina::akcja() {
    if ((rand() % szansaRozmnozenia) == 0) {
        // Znalezienie pustego pola obok aktualnej pozycji
        int nowePustePoleX = getX();
        int nowePustePoleY = getY();
        if (swiat.znajdzPustePoleObok(nowePustePoleX, nowePustePoleY)) {
            // Dodanie nowej rośliny na znalezionym pustym polu
            Roslina* nowaRoslina = this->rozmnoz(nowePustePoleX, nowePustePoleY);
            swiat.dodajOrganizm(nowaRoslina, nowePustePoleX, nowePustePoleY);

            cout << " zostala rozmnozona" << endl;
        }
    }
    else{
        cout << " w tej rundzie sie nie rozmnozyla" << endl;
    }
}

int Roslina::kolizja(Organizm* organizm) {
    Zwierze* zwierze = dynamic_cast<Zwierze*>(organizm);

    // Jeśli organizm jest zwierzęciem, wywołujemy jego metodę kolizja, w przeciwnym razie zwracamy 0
    if (zwierze) {
        return zwierze->kolizja(this);
    } else {
        return 0;
    }
}

void Roslina::rysowanie() const {
    cout << symbol << " ";
}
