#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::istream;
using std::ostream;

class Konwerter {
    unsigned long skladowa;

    public:
        void operator=(char znak) {
            skladowa = znak;
        }
        void operator=(const char* slowo) {
            skladowa = 0;
            string lancuch_znakow(slowo);
            for (auto znak : lancuch_znakow) {
                skladowa += znak;
            }
        }
        void operator=(string lancuch_znakow) {
            skladowa = 0;
            for (auto znak : lancuch_znakow) {
                skladowa += znak;
            }
        }

        friend istream& operator>>(istream& i, Konwerter& k) {
            string wejscie;
            i >> wejscie;
            k.skladowa = 0;
            for (char znak : wejscie) {
                if (!isdigit (znak)) {
                    for (auto znak : wejscie) {
                        k.skladowa += znak;
                    }
                    return i;
                }
            }
            k.skladowa = stoi (wejscie);
            return i;
        }
        friend ostream& operator<<(ostream& o, Konwerter k) {
            return o << k.skladowa;
        }

};

int main () {
    Konwerter k;
    k = 13;
    cout << k << endl;
    k = 't';
    cout << k << endl;
    k = "trywialne";
    cout << k << endl;

    cout << "Wczytaj wartosc calkowita, znak lub lancuch znakow:" << endl;
    cin >> k;
    cout << k << endl;
}