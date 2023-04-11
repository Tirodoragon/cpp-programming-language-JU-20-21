// 1 PKT
// Dla ponizszej klasy prosze napisac 
// operator indeksowy taki, zeby za argument przyjmowal "const char*"
// i rozumial lancuchy znakowe "imie" oraz "nazwisko" (jak w przykladzie ponizej)
// a zwracal typ "const char*", odpowiednio zawartosc pola imie czy nazwisko.
// W przypadku nieznanego argumentu niech wypisuje tekst "pole nieznane"

#include <iostream>
#include <string>

using namespace std;

class Obywatel {
    string imie;
    string nazwisko;

	public:
		Obywatel( const char* i, const char* n ) : imie{i}, nazwisko{n} {}
		// prosze napisac operator[]
		const char* operator[](const char* n) {
			string napis(n);

			if(napis == "imie") {
				return imie.c_str();
			}

			if(napis == "nazwisko") {
				return nazwisko.c_str();
			}

			else {
				return "pole nieznane";
			}
		}
};

// *** ponizszego kodu NIE zmieniamy ***
int main() {
   Obywatel man("Jan","Kowalski");
   cout << "Imie: " << man["imie"] << endl;
   cout << "Nazwisko: " << man["nazwisko"] << endl;
   cout << "Zly argument: " << man["costam"] << endl;
}

// Spodziewany wydruk na ekranie:
// Imie: Jan
// Nazwisko: Kowalski
// Zly argument: pole nieznane