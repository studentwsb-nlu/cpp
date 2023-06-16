/******************************************************************************

                              Zadanie 3 - Patryk Nowoszynski

Zadanie 3

Napisz program z wykorzystaniem klas Osoba z zadania 2,dodatkowo użyj klasy Przedmioty, Oceny.
Wykorzystaj dziedziczenie wielokrotne. Przedmioty dziedziczy publicznie z klasy Osoba, a Oceny dziedziczy publicznie z klasy Przedmioty. Jako składowe klasy Osoba podaj:
        imię,
        nazwisko,
        nr_indeksu,

    Jako składowe klasy Przedmiot podaj:
        matematyka
        programowanie

    Jako składowe klasy Oceny podaj:
          zaliczenie,
          brak_zaliczenia


*******************************************************************************

*******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class Osoba {
protected:
    string imie;
    string nazwisko;
    int nrIndeksu;

public:
    Osoba(const string& im, const string& naz, int indeks)
        : imie(im), nazwisko(naz), nrIndeksu(indeks) {}

    void przedstawSie() {
        cout << "Jestem " << imie << " " << nazwisko << endl;
        cout << "Mój numer indeksu to: " << nrIndeksu << endl;
    }
};

class Przedmioty : public Osoba {
protected:
    int matematyka;
    int programowanie;

public:
    Przedmioty(const string& im, const string& naz, int indeks, int mat, int prog)
        : Osoba(im, naz, indeks), matematyka(mat), programowanie(prog) {}

    void przedstawSie() {
        Osoba::przedstawSie();
        cout << "Moje oceny z matematyki: " << matematyka << endl;
        cout << "Moje oceny z programowania: " << programowanie << endl;
    }
};

class Oceny : public Przedmioty {
protected:
    int zaliczenie;
    int brak_zaliczenia;

public:
    Oceny(const string& im, const string& naz, int indeks, int mat, int prog, int zalicz, int brak)
        : Przedmioty(im, naz, indeks, mat, prog), zaliczenie(zalicz), brak_zaliczenia(brak) {}

    void przedstawSie() {
        Przedmioty::przedstawSie();
        cout << "Liczba zaliczeń: " << zaliczenie << endl;
        cout << "Liczba braków zaliczenia: " << brak_zaliczenia << endl;
    }
};

int main() {
    Oceny student("Patryk", "Nowoszynski", 12345, 4, 5, 2, 0);
    student.przedstawSie();

    return 0;
}
