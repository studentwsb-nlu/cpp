/******************************************************************************

                              Zadanie 2 - Patryk Nowoszynski

Zadanie 2

    Zdefiniuj klasę Towar. Klasa powinna zawierać prywatne pola: nazwa, cena, waga.
    Napisz publiczną funkcję wypisz składową wypisująca dane o towarze na ekranie.
    Napisz publiczną funkcję wczytaj wczytująca dane o towarze z klawiatury.
    Napisz akcesory ustawiające i zwracające pola klasy.
    Napisz trzyargumentową funkcję ustawDaneTowaru zmieniające dane składowe towaru na dane składowe na wartości podanych argumentów.
    Napisz funkcję zwiekszCene powiększającą cenę towaru o kwotę podaną jako argument.
    W funkcji main utwórz kilka towarów i przetestuj utworzone funkcje.

*******************************************************************************
W poniższym programie zdefiniowana jest klasa Towar zawierająca prywatne pola: nazwa, cena i waga.
Funkcja wypisz wyświetla dane o towarze na ekranie.
Funkcja wczytaj pobiera dane o towarze z klawiatury.
Akcesory ustawNazwe, ustawCene i ustawWage służą do ustawiania wartości pól klasy.
Funkcja ustawDaneTowaru zmienia dane towaru na podane wartości.
Funkcja zwiekszCene zwiększa cenę towaru o podaną kwotę.
W funkcji main tworzone są trzy obiekty klasy Towar. Pierwszy (towar1) jest wczytywany z klaw
*******************************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Towar {
private:
    string nazwa;
    float cena;
    float waga;

public:
    void wypisz() const {
        cout << "Nazwa: " << nazwa << endl;
        cout << "Cena: " << cena << " PLN" << endl;
        cout << "Waga: " << waga << " kg" << endl;
    }

    void wczytaj() {
        cout << "Podaj nazwę towaru: ";
        cin.ignore();
        getline(cin, nazwa);
        cout << "Podaj cenę towaru (PLN): ";
        cin >> cena;
        cout << "Podaj wagę towaru (kg): ";
        cin >> waga;
    }

    void ustawNazwe(const string& n) {
        nazwa = n;
    }

    void ustawCene(float c) {
        cena = c;
    }

    void ustawWage(float w) {
        waga = w;
    }

    void ustawDaneTowaru(const string& n, float c, float w) {
        nazwa = n;
        cena = c;
        waga = w;
    }

    void zwiekszCene(float kwota) {
        cena += kwota;
    }
};

int main() {
    Towar towar1;
    towar1.wczytaj();
    cout << endl << "Dane towaru 1:" << endl;
    towar1.wypisz();

    Towar towar2;
    towar2.ustawNazwe("Telewizor");
    towar2.ustawCene(1999.99);
    towar2.ustawWage(15.5);
    cout << endl << "Dane towaru 2:" << endl;
    towar2.wypisz();

    Towar towar3;
    towar3.ustawDaneTowaru("Laptop", 3999.99, 2.5);
    cout << endl << "Dane towaru 3:" << endl;
    towar3.wypisz();

    towar3.zwiekszCene(500);
    cout << endl << "Po zwiększeniu ceny towaru 3 o 500 PLN:" << endl;
    towar3.wypisz();

    return 0;
}
