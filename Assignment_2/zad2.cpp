#include <iostream>

using std::cout;
using std::endl;

class B1 {
    public:
        B1() {
            cout << "Obiekt klasy B1 jest budowany." << endl;
        }

        ~B1() {
            cout << "Obiekt klasy B1 jest niszczony." << endl;
        }
};
class B2 {
    public:
        B2() {
            cout << "Obiekt klasy B2 jest budowany." << endl;
        }

        ~B2() {
            cout << "Obiekt klasy B2 jest niszczony." << endl;
        }
};
class B3 {
    public:
        B3() {
            cout << "Obiekt klasy B3 jest budowany." << endl;
        }

        ~B3() {
            cout << "Obiekt klasy B3 jest niszczony." << endl;
        }
};

class V1 : public B1 {
    public:
        V1() {
            cout << "Obiekt klasy V1 jest budowany." << endl;
        }

        ~V1() {
            cout << "Obiekt klasy V1 jest niszczony." << endl;
        }
};
class V2 : public B1, public B2 {
    public:
        V2() {
            cout << "Obiekt klasy V2 jest budowany." << endl;
        }

        ~V2() {
            cout << "Obiekt klasy V2 jest niszczony." << endl;
        }
};

class D1 : virtual public V1 {
    public:
        D1() {
            cout << "Obiekt klasy D1 jest budowany." << endl;
        }

        ~D1() {
            cout << "Obiekt klasy D1 jest niszczony." << endl;
        }
};
class D2 : virtual public V2, public B3 {
    public:
        D2() {
            cout << "Obiekt klasy D2 jest budowany." << endl;
        }

        ~D2() {
            cout << "Obiekt klasy D2 jest niszczony." << endl;
        }
};

class M1 {
    public:
        M1() {
            cout << "Obiekt klasy M1 jest budowany." << endl;
        }

        ~M1() {
            cout << "Obiekt klasy M1 jest niszczony." << endl;
        }
};
class M2 {
    public:
        M2() {
            cout << "Obiekt klasy M2 jest budowany." << endl;
        }

        ~M2() {
            cout << "Obiekt klasy M2 jest niszczony." << endl;
        }
};

class X : public D1, public D2 {
    public:
        M1 m1;
        M2 m2;

        X() {
           cout << "Obiekt klasy X jest budowany." << endl;
        }

        ~X() {
            cout << "Obiekt klasy X jest niszczony." << endl;
        }
};

int main() {
    X x;
}