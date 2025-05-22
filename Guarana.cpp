#include "Guarana.h"

#define mocGuarany 3 //Ilosc punktow siły, jaką dodaje guarana.

Guarana::Guarana(int x, int y, int wiek, Swiat& swiat) : Roslina(0, 0, x, y, wiek, swiat) {symbol='G';}

Guarana::~Guarana() {}

void Guarana::akcja() {
    cout << "Guarana";
    Roslina::akcja();
}

int Guarana::kolizja(Organizm* organizm) {
    if (organizm->getInicjatywa() != 0) {
        organizm->dodajSile(mocGuarany); // Zwiększenie siły organizmu o 3

        // Usunięcie zjedzonej guarany z planszy
        swiat.usunOrganizm(this->getX(), this->getY());

        cout << " Zjadla guarane i zwiekszyla swoja sile o " << mocGuarany << endl;
        return 1; // Zwracamy 1, aby metoda kolizja dokonala przemieszczenia
    }

    return 0;
}

Guarana* Guarana::rozmnoz(int x, int y) const {
    return new Guarana(x, y, 0, swiat);
}
