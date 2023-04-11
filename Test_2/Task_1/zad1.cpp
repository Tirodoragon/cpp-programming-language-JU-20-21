// 3 PKT
/*
Wlacz potrzebne naglowki.
Uzupelnij ponizsza klaste Int, tzn. napisz definicje
konstruktora, a w nim dynamiczna alokacje jednego int.
W destruktorze zrob to co nalezy - czyli usun alokacje.
Dopisz przeciazone operatory tak, aby poprawnie dzialal ponizszy program.
Prosze tak obslugiwac klase jak by reprezentowala
typ int, pomimo tego ze ma w srodku zaszyty wskaznik int*
*/

#include <iostream>

using namespace std;

class Int {
	public:
		// napisz konstruktor (inicjalizujacy n !) oraz destruktor
		Int() {
		    n = new int();
		    *n = 0;
		}
		Int(int i) {
		    n = new int();
		    *n = i;
		}
		~Int() {
			n = nullptr;
		}
		// przeciazyc ponizsze operatory
		// dwuargumnetowy operator+=
		friend Int& operator+=(Int &l1, const int &l2) {
			int t = (*l1.n) + l2;
			Int sum{t};
			l1 = t;
			return l1;
		}
		// dwuargumnetowy operator-=
		friend Int& operator-=(Int &l1, const int &l2) {
			int t = (*l1.n) - l2;
			Int sum{t};
			l1 = t;
			return l1;
		}
		// operator= kopiujacy i przenoszacy
		Int& operator=(const Int& l) {
			if(this == &l) {
				return *this;
			}
			n = l.n;
			return *this;
		}
		Int(const Int& l) {
			n = new int(*(l.n));
		}
		Int& operator=(Int&& l) {
			if(this == &l) {
				return *this;
			}
			delete n;
			n = l.n;
			l.n = nullptr;
			return *this;
		}
		// operator==
		bool operator==(const Int &l1) {
			if(*n == (*l1.n)) {
				return true;
			}
			else {
				return false;
			}
		}
		// oraz metode wypisz()
		void wypisz() {
			cout << *n << endl;
		}

	private:
		int* n;
};

// NIE ZMIENIAC KODU PONIZEJ
int main() {
   Int t{1};
   t.wypisz(); // ma wypisac wartosc t na ekran
   t += 2;
   t.wypisz();
   t -= 3;
   t.wypisz();
   Int t2; // niech konstruktor domyslny ma wartosc 0
   t2 = t;
   if (t2 == t) cout << "rowne liczby\n";
   Int t3 = move(t2);
   t3.wypisz();
   t2.wypisz();
}