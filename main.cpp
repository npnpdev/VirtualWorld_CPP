#include "Gra.h"
#include <iostream>

using namespace std;

int main() {
    int wiersze, kolumny;
    cout << "Podaj liczbe wierszy kraty: ";
    cin >> wiersze;
    cout << "Podaj liczbe kolumn kraty: ";
    cin >> kolumny;

    if (wiersze <= 0 || kolumny <= 0) {
        cout << "Podane wymiary muszą być dodatnie." << endl;
        return 1;
    }

    Gra gra(wiersze, kolumny);
    gra.run();

    return 0;
}
