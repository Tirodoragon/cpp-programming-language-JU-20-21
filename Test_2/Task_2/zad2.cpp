// 2 PKT
// Utworz obiekt multimap z kluczem typu int i wartoscia typu string.
// Zainicjalizuj (w zapisie jednolitej inicjalizacji) kilkoma parami
// wielkosci. Wypisz te pary wielkosci za pomoca petli "for"
// w wersji "po calym zakresie".
// Nastepnie utworz drugi obiekt multimap z typami odwrotnymi, czyli
// klucz typu string, wartosc typu int. Przepisz pierwsza
// multimape do drugiej. Nastepnie wypisz, w dowolny sposob, wszystkie
// pary z drugiego obiektu multimap.

#include <iostream>
#include <map>
#include <string>

int main() {
	std::multimap<int, std::string> m {{0, "zero"}, {1, "jeden"}, {2, "dwa"}};

	std::cout << "m:" << std::endl;
	for(auto& a: m) {
		std::cout << a.first << " ma wartosc " << a.second << std::endl;
	}
	std::cout << std::endl;

	std::multimap<std::string, int> r;

	for(auto& b : m) {
		r.insert(std::make_pair(b.second, b.first));
	}

	std::cout << "r:" << std:: endl;
	for(auto& c: r) {
		std::cout << c.first << " ma wartosc " << c.second << std::endl;
	}
}