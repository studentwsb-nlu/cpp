/******************************************************************************

                              Zadanie 2 - Patryk Nowoszynski

Zadanie 2

Napisz program z wykorzystaniem klas Osoba, Student.Klasa Student dziedziczy publicznie po klasie Osoba.
W klasie osoba podaj następujące składowe klasy:
        imię,
        nazwisko,
        nr_indeksu,
    Rozszerz klasę Student o następujące składowe klasy:
        uczelnia,
        wydział,
        rok studiów


*******************************************************************************
Example output:
Jestem Jan Kowalski
Jestem Patryk Nowoszynski   
Studiuję na uczelni: WSB-NLU
Na wydziale: Informatyka    
Jestem na 3 roku studiów
*******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class Osoba {
protected:
    string imie;
    string nazwisko;

public:
    Osoba(const string& im, const string& naz) : imie(im), nazwisko(naz) {}

    void przedstawSie() {
        cout << "Jestem " << imie << " " << nazwisko << endl;
    }
};

class Student : public Osoba {
private:
    int nrIndeksu;
    string uczelnia;
    string wydzial;
    int rokStudiow;

public:
    Student(const string& im, const string& naz, int indeks, const string& ucz, const string& wydz, int rok)
        : Osoba(im, naz), nrIndeksu(indeks), uczelnia(ucz), wydzial(wydz), rokStudiow(rok) {}

    void przedstawSie() {
        Osoba::przedstawSie();
        cout << "Studiuję na uczelni: " << uczelnia << endl;
        cout << "Na wydziale: " << wydzial << endl;
        cout << "Jestem na " << rokStudiow << " roku studiów" << endl;
    }
};

int main() {
    Osoba osoba("Jan", "Kowalski");
    osoba.przedstawSie();

    Student student("Patryk", "Nowoszynski", 12345, "WSB-NLU", "Informatyka", 3);
    student.przedstawSie();

    return 0;
}
