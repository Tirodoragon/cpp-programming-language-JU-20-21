// 2 PKT
// Mamy klase bazowa Rodzic, prosze ja uzupelnic o brakujaca rzecz.
// Prosze napisac tez klasy potomne, o nazwie Syn i Corka
// tak zeby dzialal program na koncu

#include <iostream>
#include <string>

class Rodzic {
	protected:
		std::string nazwa;

	public:
		Rodzic(std::string n) : nazwa(n) {}
		virtual void mowi() = 0;

		// czegos istotnego dla klasy bazowej tu jeszcze brakuje:
		virtual ~Rodzic(){};

	protected:
		std::string getNazwa(){
			return nazwa;
		}
};

// napisz klasy dziedziczace publicznie z klasy bazowej Rodzic
// zdefiniuj w nich konstruktor oraz metode skladowa mowi - wypisujaca na ekran
// zupelnie dowolny tekst ORAZ nazwe (za pomoca metody skladowej)

// class Syn
class Syn : public Rodzic {
	public:
		Syn(std::string n) : Rodzic(n) {}
		virtual void mowi() override final {
			std::cout << "Najpierw mowi " << getNazwa() << std::endl;
		}
};

// class Corka
class Corka : public Rodzic {
	public:
		Corka(std::string n) : Rodzic(n) {}
		virtual void mowi() override final {
			std::cout << "A potem mowi " << getNazwa() << std::endl;
		}
};

// UWAGA: w ponizszym programie nalezy TYLKO uzupelnic brakujaca czesc na koncu
int main() {
   Rodzic *ptr1 = new Syn("Maly Jas");
   Rodzic *ptr2 = new Corka("Rezolutna Zosia");
   ptr1->mowi();
   ptr2->mowi();
   // tu czegos brakuje na koniec:
   delete ptr1;
   delete ptr2;
}