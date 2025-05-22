#include "Swiat.h"
#include <iostream>
#include <algorithm>
#include <cstdlib> // dla srand() i rand()
#include <ctime>   // dla time()
#include <conio.h>

Swiat::Swiat(int rows, int cols) : n(rows), m(cols) {
    // Inicjalizacja siatki światowej ze wskaźnikami na nullptr
    grid.resize(n, vector<Organizm*>(m, nullptr));
}

Swiat::~Swiat() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            delete grid[i][j];
        }
    }
}

void Swiat::wyczyscSwiat() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            delete grid[i][j];
            grid[i][j] = nullptr;
        }
    }
}

void Swiat::wyswietlSwiat() {
    // Wyświetlenie świata
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] != nullptr) {
                grid[i][j]->rysowanie(); // Wywołanie metody rysowanie dla danego organizmu
            } else {
                cout << ". "; // Wyświetlanie "." na pustych polach
            }
        }
        cout << endl;
    }
}

void Swiat::usunOrganizm(int x, int y) {
    grid[x][y] = nullptr;
}

void Swiat::dodajOrganizm(Organizm* organizm, int x, int y) {
    grid[x][y] = organizm;
}

int Swiat::getSilaOrganizmu(int x, int y) const {
    // Sprawdzamy, czy podane współrzędne są poprawne
    if (x >= 0 && x < n && y >= 0 && y < m) {
        Organizm* organizm = grid[x][y];
        if (organizm != nullptr) {
            return organizm->getSila();
        }
    }
    return 0;
}

Organizm* Swiat::getOrganizm(int x, int y) const {
    // Sprawdzamy, czy podane współrzędne są poprawne
    if (x >= 0 && x < n && y >= 0 && y < m) {
        return grid[x][y];
    } else {
        return nullptr;
    }
}

bool Swiat::organizmNaPozycji(int x, int y) const {
    if (x >= 0 && x < n && y >= 0 && y < m) {
        return grid[x][y] != nullptr;
    } else {
        return false;
    }
}

bool Swiat::znajdzPustePoleObok(int& x, int& y) const {
    // Tworzymy wektor par (x, y), reprezentujących wszystkie możliwe pozycje obok pola (x, y)
    vector<pair<int, int>> wolnePola;

    // Iterujemy przez wszystkie możliwe położenia obok danego pola (x, y)
    for (int i = x - 1; i <= x + 1; ++i) {
        for (int j = y - 1; j <= y + 1; ++j) {
            // Pomijamy pole, na którym aktualnie znajduje się organizm
            if (i == x && j == y) {
                continue;
            }
            // Sprawdzamy, czy pole jest w granicach świata i czy jest puste
            if (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == nullptr) {
                wolnePola.emplace_back(i, j);
            }
        }
    }

    // Jeśli nie ma żadnego wolnego pola obok, zwracamy false
    if (wolnePola.empty()) {
        cout << "Brak pustego pola!" << endl;
        return false;
    }

    // Losujemy indeks z dostępnych pól
    int idx = rand() % wolnePola.size();

    // Ustawiamy współrzędne na wylosowane wolne pole
    x = wolnePola[idx].first;
    y = wolnePola[idx].second;

    return true;
}

bool porownajOrganizmy(const tuple<Organizm*, int, int>& a, const tuple<Organizm*, int, int>& b) {
    Organizm* orgA = get<0>(a);
    Organizm* orgB = get<0>(b);
    if (orgA->getInicjatywa() == orgB->getInicjatywa()) {
        return orgA->getWiek() > orgB->getWiek();
    }
    return orgA->getInicjatywa() > orgB->getInicjatywa();
}

void Swiat::wykonajTure() {
    // Tworzymy wektor wskaźników do organizmów wraz z ich współrzędnymi
    vector<tuple<Organizm*, int, int>> organizmy;

    // Wypełniamy wektor organizmami i ich współrzędnymi
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] != nullptr) {
                organizmy.push_back(make_tuple(grid[i][j], i, j));
            }
        }
    }

    // Sortujemy organizmy według ich inicjatywy, a w przypadku takiej samej inicjatywy według wieku
    sort(organizmy.begin(), organizmy.end(), porownajOrganizmy);

    // Wykonujemy akcję dla każdego organizmu w posortowanej kolejności
    for (const auto& [organizm, posX, posY] : organizmy) {
        // Sprawdzamy, czy dany organizm nadal znajduje się na pozycji (x, y)
        if (organizm == grid[posX][posY] && grid[posX][posY] != nullptr) {
            organizm->akcja();
            organizm->inkrementujWiek();
            getch();
            system("cls");
            wyswietlSwiat();
        }
    }
}