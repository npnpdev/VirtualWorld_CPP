#include "Gra.h"
#include "Wilk.h"
#include "Owca.h"
#include "Lis.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "Wilcze_jagody.h"
#include "Barszcz_sosnowskiego.h"
#include "Czlowiek.h"
#include <iostream>
#include <conio.h>
#include "cstdlib"
#include "ctime"
#include <fstream>

#define zageszczenieOrganizmow 5 // Im mniejsza wartość, tym wyższe zagęszczenie

Gra::Gra(int wiersze, int kolumny) : swiat(wiersze, kolumny) {
    int losowyX, losowyY;
    srand(time(nullptr));
    
    for(int i=0; i<wiersze*kolumny/zageszczenieOrganizmow; i++){
        do {
            losowyX = rand() % (wiersze);
            losowyY = rand() % (kolumny);
        } while(swiat.organizmNaPozycji(losowyX, losowyY) || (losowyX==0 && losowyY==0));

        switch (rand() % 10) {
            case 0:
                swiat.dodajOrganizm(new Wilk(losowyX, losowyY, 0, swiat), losowyX, losowyY);
                break;
            case 1:
                swiat.dodajOrganizm(new Owca(losowyX, losowyY, 0, swiat), losowyX, losowyY);
                break;
            case 2:
                swiat.dodajOrganizm(new Lis(losowyX, losowyY, 0, swiat), losowyX, losowyY);
                break;
            case 3:
                swiat.dodajOrganizm(new Zolw(losowyX, losowyY, 0, swiat), losowyX, losowyY);
                break;
            case 4:
                swiat.dodajOrganizm(new Antylopa(losowyX, losowyY, 0, swiat), losowyX, losowyY);
                break;
            case 5:
                swiat.dodajOrganizm(new Trawa(losowyX, losowyY, 0, swiat), losowyX, losowyY);
                break;
            case 6:
                swiat.dodajOrganizm(new Mlecz(losowyX, losowyY, 0, swiat), losowyX, losowyY);
                break;
            case 7:
                swiat.dodajOrganizm(new Guarana(losowyX, losowyY, 0, swiat), losowyX, losowyY);
                break;
            case 8:
                swiat.dodajOrganizm(new Wilcze_jagody(losowyX, losowyY, 0, swiat), losowyX, losowyY);
                break;
            case 9:
                swiat.dodajOrganizm(new Barszcz_sosnowskiego(losowyX, losowyY, 0, swiat), losowyX, losowyY);
                break;
            default:
                break;
        }
    }

    // Czlowiek
    swiat.dodajOrganizm(new Czlowiek(0, 0, 0, swiat), 0, 0);
}

void Gra::zapiszStanDoPliku(const string& nazwaPliku) {
    ofstream plik(nazwaPliku);
    if (!plik) {
        cout << "Nie można otworzyć pliku do zapisu!" << endl;
        return;
    }

    // Zapisujemy rozmiar świata
    plik << swiat.getRows() << " " << swiat.getCols() << endl;

    // Pobieramy organizmy ze swiata i zapisujemy je do pliku
    for (int i = 0; i < swiat.getRows(); ++i) {
        for (int j = 0; j < swiat.getCols(); ++j) {
            Organizm* organizm = swiat.getOrganizm(i, j);
            if (organizm != nullptr) {
                // Zapisujemy literę symbolu zamiast jego kodu ASCII
                char symbol = organizm->getSymbol();
                plik << symbol << " ";
                // Zapisujemy współrzędne organizmu
                plik << i << " " << j << " ";
                // Zapisujemy siłę i inicjatywę organizmu
                plik << organizm->getSila() << " " << organizm->getInicjatywa() << " ";
                // Jeśli organizm jest człowiekiem, zapisujemy informacje o umiejętności
                if (dynamic_cast<Czlowiek*>(organizm) != nullptr) {
                    Czlowiek* czlowiek = dynamic_cast<Czlowiek*>(organizm);
                    plik << czlowiek->getCzasUmiejetnosc() << " ";
                }
                plik << endl;
            }
        }
    }
    plik.close();
}

void Gra::wczytajStanZPliku(const string& nazwaPliku) {
    ifstream plik(nazwaPliku);
    if (!plik) {
        cout << "Nie można otworzyć pliku do odczytu!" << endl;
        return;
    }

    // Usuwamy istniejące organizmy
    swiat.wyczyscSwiat();

    // Odczytujemy rozmiar świata
    int rows, cols;
    plik >> rows >> cols;

    // Tworzymy nowy obiekt klasy Swiat
    Swiat nowySwiat(rows, cols);

    swiat = nowySwiat;

    // Odczytujemy dane organizmów z pliku i tworzymy je na podstawie odczytanych informacji
    char symbol;
    int x, y, sila, inicjatywa, czasUmiejetnosc;
    while (plik >> symbol >> x >> y >> sila >> inicjatywa) {
        switch (symbol) {
            case 'C': {
                plik >> czasUmiejetnosc;
                Czlowiek* czlowiek = new Czlowiek(x, y, sila, swiat);
                czlowiek->setCzasUmiejetnosci(czasUmiejetnosc);
                if (czasUmiejetnosc > 0) {
                    czlowiek->setUmiejetnosc(true);
                } else {
                    czlowiek->setUmiejetnosc(false);
                }
                swiat.dodajOrganizm(czlowiek, x, y);
                break;
            }
            case 'W':
                swiat.dodajOrganizm(new Wilk(x, y, sila, swiat), x, y);
                break;
            case 'O':
                swiat.dodajOrganizm(new Owca(x, y, sila, swiat), x, y);
                break;
            case 'L':
                swiat.dodajOrganizm(new Lis(x, y, sila, swiat), x, y);
                break;
            case 'Z':
                swiat.dodajOrganizm(new Zolw(x, y, sila, swiat), x, y);
                break;
            case 'A':
                swiat.dodajOrganizm(new Antylopa(x, y, sila, swiat), x, y);
                break;
            case 'T':
                swiat.dodajOrganizm(new Trawa(x, y, sila, swiat), x, y);
                break;
            case 'M':
                swiat.dodajOrganizm(new Mlecz(x, y, sila, swiat), x, y);
                break;
            case 'G':
                swiat.dodajOrganizm(new Guarana(x, y, sila, swiat), x, y);
                break;
            case 'J':
                swiat.dodajOrganizm(new Wilcze_jagody(x, y, sila, swiat), x, y);
                break;
            case 'B':
                swiat.dodajOrganizm(new Barszcz_sosnowskiego(x, y, sila, swiat), x, y);
                break;
            default:
                std::cerr << "Nieznany symbol organizmu: " << symbol << std::endl;
                break;
        }
    }
    plik.close();
}

void Gra::run() {
    while (true) {
        system("cls");
        showInfo("Autor: Igor Tomkowicz, s194103 \n");
        swiat.wyswietlSwiat();

        showInfo("Jezeli chcesz dokonac zapisu gry wcisnij S, jezeli chcesz zaladowac stan gry, wcisnij L");

        char klawisz = getch();

        if(klawisz == 's'){
            string nazwaPliku;
            cout << "Wpisz nazwe pliku: " << endl;
            cin >> nazwaPliku;
            zapiszStanDoPliku(nazwaPliku);

            cout << "Zapisano stan gry!" << endl;
            getch();
        }
        else if(klawisz=='l'){
            string nazwaPliku;
            cout << "Podaj nazwe zapisu: " << endl;
            cin >> nazwaPliku;
            wczytajStanZPliku(nazwaPliku);

            cout << "Wczytano stan gry!" << endl;
            getch();
            system("cls");
            swiat.wyswietlSwiat();
        }

        showInfo("Informacje z poprzedniej tury: ");
        swiat.wykonajTure();
        getch();

    }
}

void Gra::showInfo(const std::string &komunikat) {
    // '\r' przenosi kursor na początek linii, umożliwiając nadpisanie poprzedniego komunikatu
    std::cout << "\r" << komunikat << endl;
}
