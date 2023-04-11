#include <iostream>
#include "klasa.h"
using namespace std;

// ZADANIE 4. za 3 PUNKTY
// W pliku klasa.h jest zdefiniowana klasa o nazwie Liczba
// Prosze tak rozwinac zawartosc plikow, aby dzialal ponizszy kod.


// ---------------- ponizej nic nie zmieniac -----------------
int main() {
   Liczba k1 { 3 };
   Liczba k2 = k1;
   Liczba k3 = k1 + k2;
   cout << k1 << " " << k2 << " " << k3 << endl;
}
