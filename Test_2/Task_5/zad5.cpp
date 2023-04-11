// 1 PKT
/*
Prosze utworzyc liste z obiektami typu string i *zainicjalizowac* kilkoma poczatkowymi
wartosciami (czyli slowami). Prosze utworzyc wektor od size_t lub string::size_t (pusty).
Prosze za pomoca algorytmu transform przepisac z listy do wektora (tu wstawiac
za pomoca odpowiedniego adaptora wstawiajacego) dlugosc kazdego slowan - w tym celu
uzyc odpowiedniego wiazadla/adaptora uzywajacego metode size jako czwarty argument transform.
*/

// tu twoja implementacja...

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

size_t size(std::string s) {
    return s.size();
}

int main() {
	std::list<std::string> l {"zero", "jeden", "dwa"};

	std::vector<size_t> v;

	v.resize(l.size());

	std::transform(l.begin(), l.end(), v.begin(), size);

	std::cout << "l:" << std::endl;
	for(auto a: l) {
		std::cout << a << std::endl;
	}
	std::cout << std::endl;

	std::cout << "v:" << std::endl;
	for(auto b: v) {
		std::cout << b << std::endl;
	}
}