#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class MozeWykBadania {
    public:
        MozeWykBadania(string b = "nie bada") : badanie(b) {}

        virtual ~MozeWykBadania() {}

        virtual string CoBada() {
            return badanie;
        }

    private:
        string badanie;
};

class MozeNauczac {
    public:
        MozeNauczac(string p = "nie naucza") : przedmiot(p) {}

        virtual ~MozeNauczac() {}

        virtual string CoNaucza() {
            return przedmiot;
        }

    private:
        string przedmiot;
};

class TOsoba {
    public:
        TOsoba(string i = "Jan", string n = "Kowalski", int nr = 0) : imie(i), nazwisko(n), id(nr) {}

        virtual ~TOsoba() {}

        virtual string PokazImie() {
            return imie;
        }
        virtual string PokazNazwisko() {
            return nazwisko;
        }
        virtual int PokazID() {
            return id;
        }

    private:
        string imie;
        string nazwisko;
        int id;
};

class MozeBycStudentem {
    public:
        MozeBycStudentem(string r = "nie studiuje") : rok{r} {}

        virtual ~MozeBycStudentem() {}

        virtual string KtoryRok() {
            return rok;
        }

    private:
        string rok;
};

class TAsystentBadan : public TOsoba, public MozeWykBadania {
    public:
        TAsystentBadan(string imie, string nazwisko, int id, string badanie) : TOsoba(imie, nazwisko, id), MozeWykBadania(badanie) {}

        virtual void InfoAsystentBadan() {
            cout << "Imie: " << PokazImie() << endl
            << "Nazwisko: " << PokazNazwisko() << endl
            << "Numer ID: " << PokazID() << endl
            << "Bada: " << CoBada() << endl;
        }
};

class TNauczyciel :  public TOsoba, public MozeNauczac {
    public:
        TNauczyciel(string imie, string nazwisko, int id, string przedmiot) : TOsoba(imie, nazwisko, id), MozeNauczac(przedmiot) {}

        void InfoNauczyciel() {
            cout << "Imie: " << PokazImie() << endl
            << "Nazwisko: " << PokazNazwisko() << endl
            << "Numer ID: " << PokazID() << endl
            << "Naucza: " << CoNaucza() << endl;
        }
};

class TStudent: public TOsoba, public MozeBycStudentem {
    public:
        TStudent(string imie, string nazwisko, int id, string rok) : TOsoba(imie, nazwisko, id), MozeBycStudentem(rok) {}

        virtual void InfoStudentDoktorant() {
            cout << "Imie: " << PokazImie() << endl
            << "Nazwisko: " << PokazNazwisko() << endl
            << "Numer ID: " << PokazID() << endl
            << "Rok: " << KtoryRok() << endl;
        }
};

class TDoktorant : public TStudent {
    public:
        TDoktorant(string imie, string nazwisko, int id, string rok) : TStudent(imie, nazwisko, id, rok) {}
};

class TDoktorantBadacz : public TDoktorant, public TAsystentBadan {
    public:
        TDoktorantBadacz(string imie, string nazwisko, int id, string badanie, string rok) : TDoktorant (imie, nazwisko, id, rok), TAsystentBadan(imie, nazwisko, id, badanie) {}
        
        void DoktorantBadacz() {
            InfoAsystentBadan();
            cout << "Rok: " << KtoryRok() << endl;
        }
};

class TDoktorantNaucz : public TDoktorant, public MozeNauczac {
    public:
        TDoktorantNaucz(string imie, string nazwisko, int id, string rok, string przedmiot) : TDoktorant(imie, nazwisko, id, rok), MozeNauczac(przedmiot) {}

        void InfoStudentDoktorant() override {
            cout << "Imie: " << PokazImie() << endl
            << "Nazwisko: " << PokazNazwisko() << endl
            << "Numer ID: " << PokazID() << endl
            << "Rok: " << KtoryRok() << endl
            << "Naucza: " << CoNaucza() << endl;
        }
};

int main() {
    TNauczyciel n1("Alina", "Jankowska", 1523100, "Język C - I rok");
    TNauczyciel n2("Gniewomir", "Lis", 3460846, "Język Java - II rok");
    TNauczyciel n3("Oktawia", "Sawicka", 4070504, "Język Python - III rok");

    TAsystentBadan ab1("Ryszard", "Głowacki", 4263232 , "Informatyka afektywna");
    TAsystentBadan ab2("Regina", "Jasinska", 4803405, "Inteligentne systemy");
    TAsystentBadan ab3("Mateusz", "Czerwiński", 5044704, "Wytlumaczalna sztuczna inteligencja (XAI)");

    TDoktorantBadacz db1("Boguslawa", "Stepien", 5318100, "Rzeczywistosc wirtualna i poszerzona", "I rok");
    TDoktorantBadacz db2("Miron", "Szewczyk", 5603173, "Sieci neuronowe", "II rok");
    TDoktorantBadacz db3("Barbara", "Czarnecka", 5919012, "Programowanie procesorow graficznych", "III rok");

    TDoktorantNaucz dn1("Karol", "Pawlak", 6159669, "I", "Podstawy informatyki - I rok");
    TDoktorantNaucz dn2("Monika", "Szulc", 6300397, "II", "Inzynieria oprogramowania - II rok");
    TDoktorantNaucz dn3("Kamil", "Kaczmarczyk", 633725, "III", "Teoria jezykow formalnych i metody translacji - III rok");

    TStudent s1("Marysia", "Kwiatkowska", 9576217, "I");
    TStudent s2("Kordian", "Wasilewski", 8794958, "II");
    TStudent s3("Martyna", "Jankowska", 7695519, "III");

    n1.InfoNauczyciel();
    cout << endl;
    n2.InfoNauczyciel();
    cout << endl;
    n3.InfoNauczyciel();
    cout << endl;

    ab1.InfoAsystentBadan();
    cout << endl;
    ab2.InfoAsystentBadan();
    cout << endl;
    ab3.InfoAsystentBadan();
    cout << endl;

    db1.DoktorantBadacz();
    cout << endl;
    db2.DoktorantBadacz();
    cout << endl;
    db3.DoktorantBadacz();
    cout << endl;

    dn1.InfoStudentDoktorant();
    cout << endl;
    dn2.InfoStudentDoktorant();
    cout << endl;
    dn3.InfoStudentDoktorant();
    cout << endl;

    s1.InfoStudentDoktorant();
    cout << endl;
    s2.InfoStudentDoktorant();
    cout << endl;
    s3.InfoStudentDoktorant();
    cout << endl;
}