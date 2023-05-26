/******************************************************************************

                              Zadanie 1 - Patryk Nowoszynski

Zadanie 1

Utwórz klasę Warsztat
    Prywatne pola składowe:
    czas_rozpoczecia, czas_zakonczenia, nazwa_warsztatu, nazwisko_mechanika, rodzajusterki.
    Publiczne funkcje składowe:
    wyświetl (typu const) wyświetlającą informację o warsztacie
    konstruktor - wypełniający pola składowe. Użyj listy inicjalizacyjnej konstruktora
    Napisz program warsztat.cpp, który utworzy obiekt klasy Warsztat ustawiając konstruktorem wartości pól oraz używając funkcji składowej wyswietl wypisze na ekranie informacje o warsztacie.

Modyfikacje:
    Utwórz funkcję wczytaj, która pobierze i zmieni informacje o warsztacie.
    Utwórz klasę czas i  dodaj pola godziny, minuty, sekundy.
    Zmodyfikuj funkcję wczytująca i wypisujące czas oraz konstruktor tak, aby wczytywały i wypisywały godziny, minuty, sekundy.
    Zmodyfikuj tak funkcje wczytujące czas, aby sekundy były argumentem opcjonalnym(z domyślną wartością 1
    Zmodyfikuj funkcje wyświetlającą czas, aby  w przypadku, gdy minuty i sekundy są mniejsze od 10 dodawały przed liczbą cyfrę 0

Uwaga:Wprowadź modyfiacje i oznacz komentarzami.
*******************************************************************************
W poniższym programie dodano klasę Czas, która reprezentuje czas w formacie godziny:minuty:sekundy.
W klasie Czas dodano konstruktor, który pozwala na inicjalizację godzin, minut i sekund. Sekundy mają wartość domyślną równą 1.
Dodano funkcję wczytajCzas, która pobiera od użytkownika godziny, minuty i sekundy.
W funkcji wypiszCzas dodano formatowanie, aby w przypadku, gdy minuty i sekundy są mniejsze od 10, dodawało się przed nimi zero.
W klasie Warsztat dodano funkcję wczytaj, która pobiera od użytkownika informacje o warsztacie, w tym czasy rozpoczęcia i zakończenia naprawy.
W funkcji wyswietl dodano wyświetlanie informacji o czasach w formacie godziny:minuty:sekundy.
W funkcji main utworzono obiekt Warsztat zainicjalizowany przy użyciu konstruktora. Następnie wyświetlono informacje o warsztacie przed modyfikacjami, 
wczytano nowe dane od użytkownika i ponownie wyświetlono informacje o warsztacie po modyfikacjach.
*******************************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Czas {
private:
    int godziny;
    int minuty;
    int sekundy;

public:
    Czas(int h, int m, int s = 1) {
        godziny = h;
        minuty = m;
        sekundy = s;
    }

    void wczytajCzas() {
        cout << "Podaj godziny: ";
        cin >> godziny;
        cout << "Podaj minuty: ";
        cin >> minuty;
        cout << "Podaj sekundy: ";
        cin >> sekundy;
    }

    void wypiszCzas() const {
        cout << (godziny < 10 ? "0" : "") << godziny << ":"
             << (minuty < 10 ? "0" : "") << minuty << ":"
             << (sekundy < 10 ? "0" : "") << sekundy;
    }
};

class Warsztat {
private:
    Czas czasRozpoczecia;
    Czas czasZakonczenia;
    string nazwaWarsztatu;
    string nazwiskoMechanika;
    string rodzajUsterki;

public:
    Warsztat(const Czas& rozpoczecie, const Czas& zakonczenie, const string& nazwa, const string& nazwisko, const string& usterka)
        : czasRozpoczecia(rozpoczecie), czasZakonczenia(zakonczenie), nazwaWarsztatu(nazwa), nazwiskoMechanika(nazwisko), rodzajUsterki(usterka) {}

    void wczytaj() {
        cout << "Podaj czas rozpoczęcia naprawy:" << endl;
        czasRozpoczecia.wczytajCzas();

        cout << "Podaj czas zakończenia naprawy:" << endl;
        czasZakonczenia.wczytajCzas();

        cout << "Podaj nazwę warsztatu: ";
        cin.ignore();
        getline(cin, nazwaWarsztatu);

        cout << "Podaj nazwisko mechanika: ";
        getline(cin, nazwiskoMechanika);

        cout << "Podaj rodzaj usterki: ";
        getline(cin, rodzajUsterki);
    }

    void wyswietl() const {
        cout << "Informacje o warsztacie:" << endl;
        cout << "Czas rozpoczęcia: ";
        czasRozpoczecia.wypiszCzas();
        cout << endl;

        cout << "Czas zakończenia: ";
        czasZakonczenia.wypiszCzas();
        cout << endl;

        cout << "Nazwa warsztatu: " << nazwaWarsztatu << endl;
        cout << "Nazwisko mechanika: " << nazwiskoMechanika << endl;
        cout << "Rodzaj usterki: " << rodzajUsterki << endl;
    }
};

int main() {
    Czas rozpoczecie(9, 30, 0);
    Czas zakonczenie(11, 0, 0);
    Warsztat warsztat(rozpoczecie, zakonczenie, "MotoService", "Kowalski", "Awaria silnika");

    cout << "Przed modyfikacjami:" << endl;
    warsztat.wyswietl();

    cout << endl;

    warsztat.wczytaj();

    cout << endl << "Po modyfikacjach:" << endl;
    warsztat.wyswietl();

    return 0;
}
