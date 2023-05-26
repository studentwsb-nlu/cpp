/******************************************************************************

                              Zadanie 1 - Patryk Nowoszynski

Zadanie 1

    Stworzyć struktrę klient
    Przekazać stukturę do funkcji
    Przekazanie argumentów przez wartość, referencje i wskaźnik
    zaimplementuj strukturę klient , która powinna zawierać pola, imie, nazwisko, towar jaki został kupiony, adres do wsyłki,
    Stworzyć funkcje wczytaj klienta oraz funkcje wypisz
    Stworzyc drugie i trzeciego klienta (przez new)
    Usuwanie ostatniego klienta oepratorem delete


*******************************************************************************
W powyższym programie zdefiniowana jest struktura Klient, która zawiera pola: imie, nazwisko, towar i adres.
Funkcja wczytajKlienta pobiera dane od użytkownika i przypisuje je do struktury Klient przekazanej przez referencję.
Funkcja wypiszKlienta wyświetla informacje o kliencie na ekranie, korzystając z przekazanej struktury Klient jako argumentu przez wartość (aby zapewnić tylko odczyt danych, nie zmieniając ich).
W funkcji main tworzone są trzy instancje struktury Klient. Pierwsza (klient1) jest zwykłą zmienną, druga (klient2) jest dynamicznie alokowana przy użyciu operatora new, a trzecia (klient3) również jest dynamicznie alokowana. Po użyciu trzeciego klienta, jest usuwany za pomocą operatora delete.
Program wczytuje dane trzech klientów, a następnie wypisuje je na ekranie.
*******************************************************************************/

#include <iostream>
#include <string>
using namespace std;

struct Klient {
    string imie;
    string nazwisko;
    string towar;
    string adres;
};

void wczytajKlienta(Klient& klient) {
    cout << "Podaj imie klienta: ";
    cin >> klient.imie;
    cout << "Podaj nazwisko klienta: ";
    cin >> klient.nazwisko;
    cout << "Podaj zakupiony towar: ";
    cin.ignore();
    getline(cin, klient.towar);
    cout << "Podaj adres dostawy: ";
    getline(cin, klient.adres);
}

void wypiszKlienta(const Klient& klient) {
    cout << "Imie: " << klient.imie << endl;
    cout << "Nazwisko: " << klient.nazwisko << endl;
    cout << "Towar: " << klient.towar << endl;
    cout << "Adres dostawy: " << klient.adres << endl;
}

int main() {
    Klient klient1;
    wczytajKlienta(klient1);
    cout << endl << "Dane klienta 1:" << endl;
    wypiszKlienta(klient1);
    
    Klient* klient2 = new Klient;
    wczytajKlienta(*klient2);
    cout << endl << "Dane klienta 2:" << endl;
    wypiszKlienta(*klient2);
    
    Klient* klient3 = new Klient;
    wczytajKlienta(*klient3);
    cout << endl << "Dane klienta 3:" << endl;
    wypiszKlienta(*klient3);
    
    delete klient3;
    
    return 0;
}
