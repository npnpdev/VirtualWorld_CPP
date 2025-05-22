#include "Antylopa.h"

Antylopa::Antylopa(int x, int y, int wiek, Swiat& swiat) : Zwierze(4, 4, x, y, wiek, swiat) {symbol='A';}
Antylopa::~Antylopa() {}

void Antylopa::akcja() {
    cout << "Antylopa";

    // Stare współrzędne antylopy
    int stary_x = getX();
    int stary_y = getY();

    // Lista możliwych kierunków ruchu
    std::vector<std::pair<int, int>> mozliweRuchy;

    // Zmienna do przechowania wylosowanego kierunku
    std::pair<int, int> wylosowanyKierunek;

    // Szukanie możliwych kierunków ruchu
    for (int dx = -2; dx <= 2; dx += 2) {
        for (int dy = -2; dy <= 2; dy += 2) {
            int new_x = stary_x + dx;
            int new_y = stary_y + dy;
            if (new_x >= 0 && new_x < swiat.getRows() && new_y >= 0 && new_y < swiat.getCols() && new_x != stary_x && new_y != stary_y) {
                mozliweRuchy.push_back({dx, dy});
            }
        }
    }

    // Jeśli nie ma możliwych ruchów, antylopa pozostaje na miejscu
    if (mozliweRuchy.empty()) {
        cout << " zostala na swoim miejscu, brak dostepnych pol do przemieszczenia." << endl;
        return;
    }

    //Inicjalizacja losowego ruchu
    if (wylosowanyKierunek.first == 0 && wylosowanyKierunek.second == 0) {
        int losowyIndeks = rand() % mozliweRuchy.size();
        wylosowanyKierunek = mozliweRuchy[losowyIndeks];
    }

    // Próba przesunięcia na nowe pole
    int new_x = stary_x + wylosowanyKierunek.first;
    int new_y = stary_y + wylosowanyKierunek.second;


    if (swiat.organizmNaPozycji(new_x, new_y)) {
        Organizm* organizm = swiat.getOrganizm(new_x, new_y);

        if(organizm->kolizja(this) == 2){ return;}
    }
    if(getX()!=-1){
        swiat.usunOrganizm(getX(), getY());

        // Aktualizacja współrzędnych antylopy
        setX(new_x);
        setY(new_y);

        swiat.dodajOrganizm(this, new_x, new_y);

        cout << " przemiescila sie z (" << stary_x << ", " << stary_y << ") na (" << new_x << ", " << new_y << ")." << endl;

    }
}

void Antylopa::przesunNaNiezajeteSasiedniePole() {
    // Iteracja przez sąsiednie pola
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int new_x = getX() + i;
            int new_y = getY() + j;
            // Sprawdzanie czy nowe pole jest w granicach świata
            if (new_x >= 0 && new_x < swiat.getRows() && new_y >= 0 && new_y < swiat.getCols() && !swiat.organizmNaPozycji(new_x, new_y)) {
                swiat.usunOrganizm(getX(), getY());
                setX(new_x);
                setY(new_y);
                swiat.dodajOrganizm(this, new_x, new_y);
                return;
            }
        }
    }
}

int Antylopa::kolizja(Organizm* organizm) {
    // 50% szans na ucieczkę przed walką
    if (rand() % 2 == 0 && organizm->getSymbol()!='A') {
        // Przesunięcie antylopy na niezajęte sąsiednie pole
        przesunNaNiezajeteSasiedniePole();
        cout << "Antylopa uciekla przed walka!" << endl;
        return 1;
    } else {
        // W przeciwnym razie zachowanie standardowe podczas kolizji (walka)
        return Zwierze::kolizja(organizm);
    }
}

Antylopa* Antylopa::rozmnoz(int x, int y) const {
    return new Antylopa(x, y, 0, swiat);
}