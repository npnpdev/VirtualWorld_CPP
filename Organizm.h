#ifndef PO_PROJEKT1_ORGANIZM_H
#define PO_PROJEKT1_ORGANIZM_H

#include "Swiat.h"

class Swiat; // Deklaracja wstępna klasy Swiat

class Organizm {
protected:
    int sila;
    int inicjatywa;
    int wiek;
    int x;
    int y;
    char symbol;
    Swiat& swiat; // Referencja do świata, w którym znajduje się organizm

public:
    Organizm(int sila, int inicjatywa, int x, int y, int wiek, Swiat& swiat);
    virtual ~Organizm(); // Wirtualny destruktor dla klasy abstrakcyjnej

    virtual void akcja() = 0; // Metoda czysto wirtualna, implementacja zależy od konkretnych organizmów
    virtual int kolizja(Organizm* organizm) = 0; // Metoda czysto wirtualna, implementacja zależy od konkretnych organizmów
    virtual void rysowanie() const = 0; // Metoda czysto wirtualna, implementacja zależy od konkretnych organizmów
    virtual Organizm* rozmnoz(int x, int y) const = 0;

    // Gettery
    int getSila() const { return sila; };
    int getInicjatywa() const { return inicjatywa; };
    int getWiek() const { return wiek; };
    int getX() const {return x;};
    int getY() const {return y;};
    int getSymbol() const {return symbol;};

    void inkrementujWiek() {wiek++;};
    void dodajSile(int dodaj) {sila+=dodaj;};

    // Settery
    void setX(int newX) {x = newX;}
    void setY(int newY) {y = newY;}
};

#endif //PO_PROJEKT1_ORGANIZM_H