#include "Czlowiek.h"
#include "conio.h"

#define czasTrwaniaUmiejetnosci 5; // Ilość tur
#define klawiszUmiejetnosci 'x' // Klawisz, którym aktywujemy umiejętność człowieka

Czlowiek::Czlowiek(int x, int y, int wiek, Swiat& swiat) : Zwierze(5, 4, x, y, wiek, swiat) {symbol='C';}

Czlowiek::~Czlowiek() {}

void Czlowiek::przesunCzlowieka(int dx, int dy) {
    int noweX = getX() + dx;
    int noweY = getY() + dy;

    if (noweX >= 0 && noweX < swiat.getCols() && noweY >= 0 && noweY < swiat.getRows()) {
        Organizm* organizmNaPolu = swiat.getOrganizm(noweX, noweY);

        // Jeśli na nowym polu nie ma innego organizmu lub kolizja nie powoduje śmierci
        if (organizmNaPolu == nullptr || (organizmNaPolu->kolizja(this) != 2 && getX() != -1)) {
            // Usuwamy człowieka z obecnej pozycji
            swiat.usunOrganizm(getX(), getY());
            // Dodajemy człowieka na nowej pozycji
            swiat.dodajOrganizm(this, noweX, noweY);
            // Aktualizujemy pozycję człowieka
            setX(noweX);
            setY(noweY);
        }
    }
}

void Czlowiek::akcja() {
    char klawisz = 0;

    // Obsluga umiejetnosci
    if (umiejetnoscAktywna) {
        if (licznikTur > 0) {
            cout << "Umiejetnosc jest jeszcze aktywna przez " << licznikTur << " tur" << endl;
            --licznikTur;
        } else {
            umiejetnoscAktywna = false;
            licznikTur = -czasTrwaniaUmiejetnosci; // Czas odnowienia umiejętności
        }
    } else if (licznikTur == 0) {
        cout << "Umiejetnosc specjalna czlowieka jest gotowa do uzycia!" << endl;

        // Jeżeli umiejętność nie jest aktywna i nie jest w fazie odnowienia, możemy wybrać aktywację
        do {
            cout << "Nacisnij strzalke (w/a/s/d) aby wybrac kierunek ruchu lub '" << klawiszUmiejetnosci << "' aby aktywowac umiejetnosc: " << endl;
            klawisz = _getch();
        } while (klawisz != 'w' && klawisz != 'a' && klawisz != 's' && klawisz != 'd' && klawisz != klawiszUmiejetnosci);

        if (klawisz == klawiszUmiejetnosci) {
            umiejetnoscAktywna = true;
            licznikTur = czasTrwaniaUmiejetnosci;
            cout << "Umiejetnosc specjalna czlowieka zostala aktywowana!" << endl;
        }
    }
    else{
        licznikTur++;
        cout << "Umiejetnosc specjalna czlowieka odnawia sie jeszcze przez " << -licznikTur << " tur" << endl;
    }

    // Obsluga poruszania sie
    if(klawisz==klawiszUmiejetnosci || klawisz == 0){
        do {
            cout << "Nacisnij strzalke (w/a/s/d) aby wybrac kierunek ruchu: " << endl;
            klawisz = _getch();
        } while (klawisz != 'w' && klawisz != 'a' && klawisz != 's' && klawisz != 'd');
    }

    // Obsługa ruchu gracza na podstawie naciśniętego klawisza
    switch (klawisz) {
        case 'w':
            przesunCzlowieka(-1, 0);
            break;
        case 'a':
            przesunCzlowieka(0, -1);
            break;
        case 's':
            przesunCzlowieka(1, 0);
            break;
        case 'd':
            przesunCzlowieka(0, 1);
            break;
    }
}

int Czlowiek::kolizja(Organizm* organizm) {
    Zwierze* zwierze = dynamic_cast<Zwierze*>(organizm);

    if (umiejetnoscAktywna && zwierze) {
        // Przemieszczenie organizmu na losowe puste pole obok człowieka
        int noweX = organizm->getX();
        int noweY = organizm->getY();

        if(swiat.znajdzPustePoleObok(noweX, noweY)){
            swiat.usunOrganizm(organizm->getX(), organizm->getY());

            organizm->setX(noweX);
            organizm->setY(noweY);

            swiat.dodajOrganizm(organizm, noweX, noweY);

            cout << " probowal zaatakowac czlowieka, jednak umiejetnosc sprawila, ze zostal przeniesiony na pole (" << noweX << "," << noweY << ")." << endl;

            return 2;
        }
        else{
            cout << "Nie znaleziono nowego pustego pola!" << endl;
        }
    } else {
        return Zwierze::kolizja(organizm);
    }
    return 0;
}

Czlowiek* Czlowiek::rozmnoz(int x, int y) const {
    return new Czlowiek(x, y, 0, swiat);
}

