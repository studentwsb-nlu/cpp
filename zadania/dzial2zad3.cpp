/******************************************************************************

                              Zadanie 3 - Patryk Nowoszynski

 Zadanie 3

    Napisz program Rezerwacje, obsługujące zezerwacje stolików w restauracji.
    W pogramie użyj Klasy Czas zrealizowanej na lab (lub zaproponuj własną)
    Zdefiniuj klasę rezerwacje w której użyjesz jako pola składowe obiekty klasy Czas.
    Zaproponuj własne pola i funkcje obsługi obiektów.
    W funkcji main utwórz obiekty klasy Rezerwacje i przetestuj na ich działanie funkcji składowych.

*******************************************************************************
W powyższym programie zdefiniowane są dwie klasy: Czas i `Rezerwacje
*******************************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Czas {
private:
    int godzina;
    int minuta;

public:
    Czas() {
        godzina = 0;
        minuta = 0;
    }

    Czas(int h, int m) {
        godzina = h;
        minuta = m;
    }

    void ustawCzas(int h, int m) {
        godzina = h;
        minuta = m;
    }

    void wypiszCzas() const {
        cout << godzina << ":" << minuta;
    }
};

class Rezerwacje {
private:
    Czas czasRozpoczecia;
    Czas czasZakonczenia;
    string imie;
    string nazwisko;
    int numerStolika;

public:
    void ustawCzasRozpoczecia(int h, int m) {
        czasRozpoczecia.ustawCzas(h, m);
    }

    void ustawCzasZakonczenia(int h, int m) {
        czasZakonczenia.ustawCzas(h, m);
    }

    void ustawImie(const string& i) {
        imie = i;
    }

    void ustawNazwisko(const string& n) {
        nazwisko = n;
    }

    void ustawNumerStolika(int numer) {
        numerStolika = numer;
    }

    void wypiszRezerwacje() const {
        cout << "Rezerwacja dla: " << imie << " " << nazwisko << endl;
        cout << "Numer stolika: " << numerStolika << endl;
        cout << "Czas rozpoczęcia: ";
        czasRozpoczecia.wypiszCzas();
        cout << endl;
        cout << "Czas zakończenia: ";
        czasZakonczenia.wypiszCzas();
        cout << endl;
    }
};

int main() {
    Rezerwacje rezerwacja1;
    rezerwacja1.ustawCzasRozpoczecia(18, 30);
    rezerwacja1.ustawCzasZakonczenia(20, 0);
    rezerwacja1.ustawImie("Jan");
    rezerwacja1.ustawNazwisko("Kowalski");
    rezerwacja1.ustawNumerStolika(3);

    Rezerwacje rezerwacja2;
    rezerwacja2.ustawCzasRozpoczecia(19, 0);
    rezerwacja2.ustawCzasZakonczenia(21, 30);
    rezerwacja2.ustawImie("Anna");
    rezerwacja2.ustawNazwisko("Nowak");
    rezerwacja2.ustawNumerStolika(2);

    cout << "Rezerwacja 1:" << endl;
    rezerwacja1.wypiszRezerwacje();

    cout << endl;

    cout << "Rezerwacja 2:" << endl;
    rezerwacja2.wypiszRezerwacje();

    return 0;
}
