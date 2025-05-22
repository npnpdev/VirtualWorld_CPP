#ifndef PO_PROJEKT1_GRA_H
#define PO_PROJEKT1_GRA_H

#include "Swiat.h"

class Gra {
public:
    Gra(int rows, int cols);
    void run();

private:
    Swiat swiat;

    void showInfo(const string& komunikat); //wyswietla komunikat
    void zapiszStanDoPliku(const string& nazwaPliku);
    void wczytajStanZPliku(const string& nazwaPliku);
};

#endif //PO_PROJEKT1_GRA_H
