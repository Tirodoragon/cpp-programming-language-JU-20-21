#include <iostream>

// To jest definicja klasy. Prosze napisac definicje ponizszych funkcji.
// Definicje umiescic w plikach .cpp

class Liczba {
   public:
	Liczba(int l);
	Liczba(const Liczba& l);
	Liczba& operator=(const Liczba& l);
	Liczba operator+(const Liczba& l);
	
	friend std::ostream& operator<<(std::ostream& s, const Liczba& l);
	~Liczba();
   private:
     int v;
};

