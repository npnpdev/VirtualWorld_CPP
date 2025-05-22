# Symulator Wirtualnego Świata (C++)

> Konsolowa aplikacja, w której na dwuwymiarowej planszy NxM żyją rośliny i zwierzęta, a gracz steruje Człowiekiem. Projekt realizowany zgodnie z zasadami programowania obiektowego.

---

## Spis treści

* [Opis](#opis)
* [Punktacja](#punktacja)
* [Funkcjonalności](#funkcjonalności)
* [Architektura OOP](#architektura-oop)
* [Struktura katalogów](#struktura-katalogów)
* [Budowanie i uruchomienie](#budowanie-i-uruchomienie)
* [Sterowanie](#sterowanie)
* [Autor](#autor)
* [Licencja](#licencja)

---

## Opis

Symulator to turowa gra na planszy o rozmiarze zadanym przez użytkownika (domyślnie 20×20). Na każdym polu może znajdować się co najwyżej jeden organizm. W każdej turze każdy organizm wywołuje metodę `akcja()`, a w przypadku kolizji — `kolizja()`.

---

## Funkcjonalności

* **Plansza**: dowolny rozmiar NxM (min. 20×20).
* **Organizmy**: abstrakcyjna klasa `Organizm` z polami `sila`, `inicjatywa`, położenie `(x,y)` i referencją do świata.
* **Zwierzęta**: losowy ruch, walka wg siły (wyjątki: żółw, cyber-owca).
* **Rośliny**: rozprzestrzenianie się z zadanym prawdopodobieństwem, 5 gatunków.
* **Człowiek**: sterowany strzałkami, umiejętność specjalna aktywowana klawiszem (5 tur działania + 5 tur odnowienia).
* **Raport**: na konsoli wyświetlane zdarzenia (jedzenie, walka).

---

## Technologie i umiejętności

* **Język**: nowoczesne C++ (C++11/14) z wykorzystaniem bibliotek standardowych STL (`vector`, `algorithm`, `iostream`).
* **Paradygmat OOP**: dziedziczenie, polimorfizm, enkapsulacja, abstrakcja typów.
* **Zarządzanie pamięcią**: wskaźniki, inteligentne wskaźniki (`unique_ptr`).
* **Obsługa plików**: operacje na strumieniach (`fstream`) dla zapisu i odczytu stanu świata.
* **Wzorce projektowe**: front controller w `Swiat`, fabryka organizmów, singleton dla zarządcy świata.
* **Testowanie**: procedury manualne poprzez konsolowe scenariusze gry.

---

## Architektura OOP

* **`Swiat`**: zarządza wektorem `Organizm*`; metody: `wykonajTure()`, `rysujSwiat()`, prywatne pola planszy.
* **`Organizm`** (abstrakcyjna): pola: `int sila, inicjatywa, x, y`; metody wirtualne: `akcja(Swiat&)`, `kolizja(Organizm&, Swiat&)`, `rysowanie()`.
* **`Zwierze`** / **`Roslina`** (abstrakcyjne) → konkretne klasy: `Wilk`, `Owca`, `Lis`, `Zolw`, `Antylopa`, `CyberOwca`; `Trawa`, `Mlecz`, `Guarana`, `WilczeJagody`, `Barszcz`.
* **`Czlowiek`**: dziedziczy po `Zwierze`, obsługa klawiatury i umiejętność.

---

## Struktura katalogów

```
VirtualWorldCpp/
├── .idea/
├── .VS/
├── cmake-build-cmd/
├── cmake-build-debug/
├── out/
├── Antylopa.{cpp,h}
├── Barszcz\ sosnowskiego.{cpp,h}
├── Czlowiek.{cpp,h}
├── Gra.{cpp,h}
├── Guarana.{cpp,h}
├── Lis.{cpp,h}
├── main.cpp
├── Mlecz.{cpp,h}
├── Organizm.{cpp,h}
├── Owca.{cpp,h}
├── Roslina.{cpp,h}
├── Swiat.{cpp,h}
├── trawa.{cpp,h}
├── wilcze_jagody.{cpp,h}
├── wilk.{cpp,h}
├── zolw.{cpp,h}
├── zwierze.{cpp,h}
└── CMakeLists.txt
```

---

## Sterowanie

* **Strzałki** – ruch Człowieka
* **Enter / Spacja** – następna tura
* **U** – aktywacja umiejętności Człowieka
* **Z** – zapis stanu, **L** – wczytanie stanu świata

---

## Autor

* **Igor Tomkowicz**
* GitHub: [npnpdev](https://github.com/npnpdev)
* LinkedIn: [Igor Tomkowicz](https://www.linkedin.com/in/igor-tomkowicz-a5760b358/)
* E-mail: npnpdev@gmail.com

---

## Licencja

MIT
