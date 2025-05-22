#include "Lis.h"

Lis::Lis(int x, int y, int wiek, Swiat& swiat) : Zwierze(3, 7, x, y, wiek, swiat) {symbol='L';}

Lis::~Lis() {}

void Lis::akcja() {
    cout << "Lis";

    int dx, dy;
    int new_x, new_y;
    int wynikKolizji = 0;

    do {
        dx = rand() % 3 - 1; // -1, 0, 1
        dy = rand() % 3 - 1; // -1, 0, 1

        // Oblicz nowe współrzędne
        new_x = getX() + dx;
        new_y = getY() + dy;

        // Sprawdzenie, czy nowe pole jest w granicach świata
    } while ((new_x == getX() && new_y == getY()) || // Nowe współrzędne są równe obecnym
             (new_x < 0 || new_x >= swiat.getRows()) || // Nowe współrzędne wykraczają poza zakres wierszy
             (new_y < 0 || new_y >= swiat.getCols())); // Nowe współrzędne wykraczają poza zakres kolumn

    // Sprawdzenie, czy na nowym polu znajduje się inny organizm
    if (swiat.organizmNaPozycji(new_x, new_y)) {
        // Pobranie organizmu znajdującego się na nowym polu
        Organizm* organizm = swiat.getOrganizm(new_x, new_y);

        if (organizm->getSila() > this->getSila()) {
            cout << " skorzystal z dobryWech!" << endl;
            return;
        }
        else{
            wynikKolizji = organizm->kolizja(this);
        }
    }
    if(wynikKolizji==2){
        return;
    }

    if(getX()!=-1){
        int stary_x = getX();
        int stary_y = getY();

        swiat.usunOrganizm(stary_x, stary_y);

        setX(new_x);
        setY(new_y);

        swiat.dodajOrganizm(this, new_x, new_y);

        cout << " przemiescil sie z (" << stary_x << ", " << stary_y << ") na (" << new_x << ", " << new_y << ")." << endl;
    }
}


int Lis::kolizja(Organizm* organizm) {
    return Zwierze::kolizja(organizm);
}

Lis* Lis::rozmnoz(int x, int y) const {
    return new Lis(x, y, 0, swiat);
}