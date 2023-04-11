// 2 PKT
/*
Dodaj potrzebne naglowki.
Mamy liste (z typem double), napisz kryterium sortowania w postaci
wyrazenia lambda, ktore posortuja wartosci (w kolejnosci od najwiekszej do najmniejszej)
ale bez uwzglednienia znakow liczb, czyli -3.14 i 3.14 to samo.
Wypisz na ekran po operacji sortowania.
*/

#include <iostream>
#include <list>

int main() {
   std::list<double> ld {3.14, -1.0, 2.45, -3.14, 3.13, 1.11, 5.21, -4.19};

   ld.sort([] (double a, double b) {
	   return std::abs(a) > std::abs(b);
   });

   for(auto& a : ld) {
	   std::cout << a << ", ";
   }
   std::cout << std::endl;
}