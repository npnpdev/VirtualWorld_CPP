#include "Zwierze.h"

Zwierze::Zwierze(int sila, int inicjatywa, int x, int y, int wiek, Swiat& swiat) : Organizm(sila, inicjatywa, x, y, wiek, swiat) {
}

Zwierze::~Zwierze() {}

void Zwierze::akcja() {
    // Implementacja ruchu zwierzęcia
    // Przesuwanie się na losowe sąsiednie pole
    int dx, dy;
    int wynikKolizji = 0;
    int new_x, new_y;

    do {
        dx = rand() % 3 - 1; // -1, 0, 1
        dy = rand() % 3 - 1; // -1, 0, 1

        // Obliczanie nowych współrzędnych
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

        // Kolizja organizmów
        wynikKolizji = organizm->kolizja(this);
    }
    if(wynikKolizji==2){
        return;
    }

    else{
        if(getX()!=-1){
            // Stare współrzędne zwierzęcia
            int stary_x = getX();
            int stary_y = getY();

            // Usuniecie zwierzecia ze starej pozycji
            swiat.usunOrganizm(stary_x, stary_y);

            // Aktualizacja pozycji zwierzęcia
            setX(new_x);
            setY(new_y);

            // Aktualizacja pozycji zwierzęcia na siatce światowej
            swiat.dodajOrganizm(this, new_x, new_y);

            cout << " przemiescil sie z (" << stary_x << ", " << stary_y << ") na (" << new_x << ", " << new_y << ")." << endl;
        }
    }
}

int Zwierze::kolizja(Organizm* organizm) {
    if ((organizm->getSymbol() == this->getSymbol())) {
        // Kolizja z organizmem tego samego gatunku
        // Tworzenie nowego zwierzęcia tego samego gatunku
        int nowyX = getX();
        int nowyY = getY();
        bool znalezionoPustePole = swiat.znajdzPustePoleObok(nowyX, nowyY);
        if (znalezionoPustePole) {
            Zwierze* noweZwierze = this->rozmnoz(nowyX, nowyY);
            swiat.dodajOrganizm(noweZwierze, nowyX, nowyY);

            cout << " - nowe zwierze tego samego gatunku narodzilo sie na pozycji (" << nowyX << ", " << nowyY << ")." << endl;
        }
        return 2; // Zwracamy 2, aby organizm nie wykonywal juz ruchu w tej rundzie
    } else {
        // Kolizja z organizmem innego gatunku
        if (organizm->getSila() >= this->getSila()) {
            // Organizm przeciwny ma większą siłę - ginie
            swiat.usunOrganizm(this->getX(), this->getY());
            this->setX(-1);

            cout << " Zwierze o sile " << this->getSila() << " zostalo zabite przez organizm na pozycji (" << organizm->getX() << ", " << organizm->getY() << ")." << endl;
            return 1;
        } else {
            swiat.usunOrganizm(organizm->getX(), organizm->getY());
            organizm->setX(-1);

            cout << " Zwierze o sile " << organizm->getSila() << " zostalo zabite przez organizm na pozycji (" << this->getX() << ", " << this->getY() << ")." << endl;

            return 1;
        }
    }
}

void Zwierze::rysowanie() const {
    cout << symbol << " ";
}
