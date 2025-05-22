#include "Barszcz_sosnowskiego.h"
#include "Zwierze.h"

Barszcz_sosnowskiego::Barszcz_sosnowskiego(int x, int y, int wiek, Swiat& swiat) : Roslina(10, 0, x, y, wiek, swiat) {symbol='B';}

Barszcz_sosnowskiego::~Barszcz_sosnowskiego() {}

void Barszcz_sosnowskiego::akcja() {
    cout << "Barszcz sosnowskiego";

    // Iteracja po otaczających polach i zabijanie zwierząt
    for (int i = getX() - 1; i <= getX() + 1; ++i) {
        for (int j = getY() - 1; j <= getY() + 1; ++j) {
            // Sprawdzenie, czy badane pole znajduje się w granicach planszy i czy nie jest to pole, na którym stoi barszcz
            if (i >= 0 && i < swiat.getCols() && j >= 0 && j < swiat.getRows() && !(i == getX() && j == getY())) {
                if (swiat.organizmNaPozycji(i, j)) {
                    Organizm* organizm = swiat.getOrganizm(i, j);
                    // Zabija tylko zwierzęta, pomijając rośliny
                    if (dynamic_cast<Zwierze*>(organizm) != nullptr) {
                        swiat.usunOrganizm(i, j);
                        cout << " zabił organizm na pozycji (" << i << ", " << j << ")." << endl;
                    }
                }
            }
        }
    }

    Roslina::akcja();
}

int Barszcz_sosnowskiego::kolizja(Organizm* organizm) {
    if (organizm->getInicjatywa() != 0) {
        swiat.usunOrganizm(organizm->getX(), organizm->getY());

        swiat.usunOrganizm(this->getX(), this->getY());

        cout << " Zjadl barszcz sosnowskiego i zginal!" << endl;
        return 2; // Zwracamy 2, aby metoda nie dokonywala przemieszczenia
    }

    return 0;
}

Barszcz_sosnowskiego* Barszcz_sosnowskiego::rozmnoz(int x, int y) const {
    return new Barszcz_sosnowskiego(x, y, 0, swiat);
}