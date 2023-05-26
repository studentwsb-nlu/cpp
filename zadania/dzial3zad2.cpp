/******************************************************************************

                              Zadanie 2 - Patryk Nowoszynski
 Zadanie 2

    Zaprojektuj klasę Towar do  przechowywania informacji o danych towarach.
    Definicje funkcji składowych umieszczaj poza klasą. W klasie pozostaw tylko prototyp funkcji składowych;
    Klasa powinna przechowywać następujące informacje:
     prywatne pola nazwa cenaNetto towaru;
    konstruktor wypełniający pola klasy(nazwa i cena) oraz wypisujący komunikat o tworzeniu towaru
    destruktor wypisujący komunikat o usuwaniu towaru
    funkcja drukuj (typu const) wświetlająca dane towaru
    prywatna statyczna składowa licznik do przechowywania liczby towaru
    zainicjalizuj (np. liczbę 0) sładową przechwywującą liczbę towarów
    zmodyfikuj klasę tak, aby przy toworzeniu i usuwaniu zmieniała się wartość zmiennej przechowywującje liczbie towarów
    statyczna funkcja LiczbaTowarów wracająca liczbę towarów
    utwórz akcesory dla pół sładowych nazwa i cenaNetto

Opisz kiedy wywoływany jest konstruktor , a kiedy destruktor.

*******************************************************************************
W klasie Towar dodano prywatne pola nazwa (typu string) oraz cenaNetto (typu double). Dodano również prywatną statyczną składową licznik (typu int), która przechowuje liczbę towarów.
W konstruktorze Towar inicjalizowane są pola nazwa i cenaNetto na podstawie przekazanych argumentów, a także zwiększany jest licznik towarów. Dodano komunikat o tworzeniu towaru.
W destruktorze Towar zmniejszany jest licznik towarów. Dodano komunikat o usuwaniu towaru.
Funkcja drukuj wyświetla informacje o towarze (nazwa i cena netto).
Funkcja statyczna LiczbaTowarow zwraca wartość licznika towarów.
Dodano akcesory (ustawNazwe, ustawCene, pobierzNazwe, pobierzCene) do manipulacji polami nazwa i cenaNetto.
W funkcji main utworzono dwa obiekty klasy Towar (t1 i t2) i wywołano na nich funkcję drukuj. Następnie wyświetlono liczbę towarów za pomocą funkcji statycznej LiczbaTowarow.
Konstruktor klasy Towar jest wywoływany podczas tworzenia obiektu (np. Towar t1("Laptop", 2500.0)). 
Destruktor jest wywoływany podczas usuwania obiektu (np. gdy obiekt wychodzi poza zakres lub zostaje wywołana funkcja delete na dynamicznie zaalokowanym obiekcie). 
W przykładzie powyżej destruktory są wywoływane na końcu programu, gdy obiekty t1 i t2 wychodzą poza zakres.

*******************************************************************************/


#include <iostream>
#include <string>
using namespace std;

class Towar {
private:
    string nazwa;
    double cenaNetto;
    static int licznik;

public:
    Towar(const string& n, double cena);
    ~Towar();

    void drukuj() const;

    static int LiczbaTowarow();

    // Akcesory
    void ustawNazwe(const string& n);
    void ustawCene(double cena);
    string pobierzNazwe() const;
    double pobierzCene() const;
};

int Towar::licznik = 0;

Towar::Towar(const string& n, double cena) : nazwa(n), cenaNetto(cena) {
    licznik++;
    cout << "Tworzenie towaru o nazwie " << nazwa << endl;
}

Towar::~Towar() {
    licznik--;
    cout << "Usuwanie towaru o nazwie " << nazwa << endl;
}

void Towar::drukuj() const {
    cout << "Nazwa: " << nazwa << endl;
    cout << "Cena netto: " << cenaNetto << endl;
}

int Towar::LiczbaTowarow() {
    return licznik;
}

void Towar::ustawNazwe(const string& n) {
    nazwa = n;
}

void Towar::ustawCene(double cena) {
    cenaNetto = cena;
}

string Towar::pobierzNazwe() const {
    return nazwa;
}

double Towar::pobierzCene() const {
    return cenaNetto;
}

int main() {
    Towar t1("Laptop", 2500.0);
    Towar t2("Telewizor", 1500.0);

    t1.drukuj();
    t2.drukuj();

    cout << "Liczba towarów: " << Towar::LiczbaTowarow() << endl;

    return 0;
}
