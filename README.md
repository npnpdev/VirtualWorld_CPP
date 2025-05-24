# Virtual World Simulator (C++)

[English](#english-version) | [Polski](#wersja-polska)

---

## English Version

### Description

Virtual World Simulator is a console-based, turn-driven application where plants and animals live on a 2D board of size N×M (default 20×20). Each cell holds at most one organism. Every turn, each organism executes its `action()`, and collisions are handled by `collision()`.

### Scoring

Players earn points for actions such as eating other organisms and surviving rounds. Detailed scoring rules are implemented in the `Game` module.

### Features

* **Resizable Board**: customizable N×M grid (minimum 20×20)
* **Organism Hierarchy**: abstract `Organism` class with attributes `strength`, `initiative`, position `(x,y)`, and reference to the world
* **Animals**: random movement and combat by strength (special rules for Turtle and Cyber-Sheep)
* **Plants**: probabilistic spreading for five species
* **Human**: player-controlled via arrow keys, special ability activated by `U` (5 turns active + 5 turns cooldown)
* **Event Log**: console output of events (eating, fighting)

### OOP Architecture

* **`World`**: manages vector of `Organism*`; methods: `executeTurn()`, `drawWorld()`, internal board state
* **`Organism`** (abstract): fields `int strength, initiative, x, y`; virtual methods: `action(World&)`, `collision(Organism&, World&)`, `draw()`
* **`Animal`/`Plant`**: abstract parents for concrete classes (`Wolf`, `Sheep`, `Fox`, `Turtle`, `Antelope`, `CyberSheep`, `Grass`, `Dandelion`, `Guarana`, `Nightshade`, `SosnowskyHogweed`)
* **`Human`**: inherits from `Animal`, handles input and special ability

### Directory Structure

```text
VirtualWorldCpp/
├── src/
│   ├── Antelope.cpp/h
│   ├── BarszczSosnowskiego.cpp/h
│   ├── Human.cpp/h
│   ├── Game.cpp/h
│   ├── Guarana.cpp/h
│   ├── Fox.cpp/h
│   ├── main.cpp
│   ├── Dandelion.cpp/h
│   ├── Organism.cpp/h
│   ├── Sheep.cpp/h
│   ├── Plant.cpp/h
│   ├── World.cpp/h
│   ├── Grass.cpp/h
│   ├── Nightshade.cpp/h
│   ├── Wolf.cpp/h
│   ├── Turtle.cpp/h
│   └── Animal.cpp/h
├── CMakeLists.txt
└── README.md
```

### Controls

* **Arrow Keys**: move Human
* **Enter/Space**: advance to next turn
* **`U`**: activate Human’s special ability
* **`Z`**: save state
* **`L`**: load world state

---

## Wersja polska

### Opis

Symulator Wirtualnego Świata to konsolowa aplikacja turowa, w której rośliny i zwierzęta żyją na planszy 2D o wymiarach N×M (domyślnie 20×20). Na każdym polu może być maksymalnie jeden organizm. W każdej turze każdy organizm wykonuje `akcja()`, a kolizje obsługuje `kolizja()`.

### Punktacja

Gracz zdobywa punkty za jedzenie innych organizmów i przetrwanie tur. Szczegółowe zasady punktacji zawarte są w module `Gra`.

### Funkcjonalności

* **Konfigurowalna plansza**: dowolny rozmiar NxM (min. 20×20)
* **Hierarchia organizmów**: abstrakcyjna klasa `Organizm` z atrybutami `sila`, `inicjatywa`, pozycja `(x,y)` i referencją do świata
* **Zwierzęta**: losowy ruch, walka wg siły (wyjątki: Żółw i Cyber-Owca)
* **Rośliny**: probabilistyczne rozmnażanie pięciu gatunków
* **Człowiek**: sterowanie strzałkami, umiejętność specjalna `U` (5 tur aktywna + 5 tur odnowienia)
* **Log zdarzeń**: konsolowe wypisywanie wydarzeń (jedzenie, walka)

### Architektura OOP

* **`Swiat`**: zarządza wektorem `Organizm*`; metody: `wykonajTure()`, `rysujSwiat()`, stan planszy prywatnie
* **`Organizm`** (abstrakcyjna): pola `int sila, inicjatywa, x, y`; metody wirtualne: `akcja(Swiat&)`, `kolizja(Organizm&, Swiat&)`, `rysuj()`
* **`Zwierze`/`Roslina`**: klasy abstrakcyjne dla `Wilk`, `Owca`, `Lis`, `Zolw`, `Antylopa`, `CyberOwca`, `Trawa`, `Mlecz`, `Guarana`, `WilczeJagody`, `BarszczSosnowskiego`
* **`Czlowiek`**: dziedziczy po `Zwierze`, obsługuje wejście i umiejętność

### Struktura katalogów

```text
VirtualWorldCpp/
├── src/
│   ├── Antylopa.cpp/h
│   ├── BarszczSosnowskiego.cpp/h
│   ├── Czlowiek.cpp/h
│   ├── Gra.cpp/h
│   ├── Guarana.cpp/h
│   ├── Lis.cpp/h
│   ├── main.cpp
│   ├── Mlecz.cpp/h
│   ├── Organizm.cpp/h
│   ├── Owca.cpp/h
│   ├── Roslina.cpp/h
│   ├── Swiat.cpp/h
│   ├── Trawa.cpp/h
│   ├── WilczeJagody.cpp/h
│   ├── Wilk.cpp/h
│   ├── Zolw.cpp/h
│   └── Zwierze.cpp/h
├── CMakeLists.txt
└── README.md
```

### Sterowanie

* **Strzałki**: ruch Człowieka
* **Enter/Spacja**: przejście do następnej tury
* **`U`**: aktywacja umiejętności Człowieka
* **`Z`**: zapis stanu gry
* **`L`**: wczytanie stanu świata

---

## Kontakt / Contact

* **Igor Tomkowicz**
* GitHub: [npnpdev](https://github.com/npnpdev)
* LinkedIn: [Igor Tomkowicz](https://www.linkedin.com/in/igor-tomkowicz-a5760b358/)
* E-mail: [npnpdev@gmail.com](mailto:npnpdev@gmail.com)

---

## Licencja / License

Project available under the **MIT** license. See [LICENSE](LICENSE) for details.
