#ifndef PO_PROJEKT1_SWIAT_H
#define PO_PROJEKT1_SWIAT_H

#include <iostream>
#include <vector>
#include "Organizm.h"

using namespace std;

class Organizm;

class Swiat {
private:
    int n; // liczba wierszy
    int m; // liczba kolumn
    vector<vector<Organizm*>> grid; // siatka świata

public:
    Swiat(int rows, int cols);
    ~Swiat();

    void wyczyscSwiat();
    void wyswietlSwiat();
    void wykonajTure();
    void dodajOrganizm(Organizm* organizm, int x, int y);
    void usunOrganizm(int x, int y);

    // Gettery do pobrania liczby wierszy i kolumn
    int getRows() const { return n; }
    int getCols() const { return m; }

    // Settery
    void setRows(int rows) {n = rows;};
    void setCols(int cols) {m = cols;};

    Organizm* getOrganizm(int x, int y) const;
    int getSilaOrganizmu(int x, int y) const;
    bool organizmNaPozycji(int x, int y) const;
    bool znajdzPustePoleObok(int& x, int& y) const;
};
#endif //PO_PROJEKT1_SWIAT_H
