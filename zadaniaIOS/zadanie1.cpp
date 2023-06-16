/******************************************************************************

                              Zadanie 2 - Patryk Nowoszynski

Zadanie 1

Napisz program z wykorzystaniem klasy figura.
Umieść w niej 3 czyste funkcje wirtualne do obliczania:

    obwodu, pola powierzchni, dla następujących figur geometrycznych
    (trójkąt równoboczny, kwadrat, kolo, trapez).
    Napisz klasy dla wyżej wymienionych figur wraz z funkcjami wirtualnymi, które wykonują obliczenia dla obwodu, pola powierzchni, dla konkretnej figury.



*******************************************************************************
Zdefiniowano klasę Figura jako klasę bazową, która posiada dwie czyste funkcje wirtualne obwod() i polePowierzchni(). 
Klasy pochodne, takie jak TrojkatRownoboczny, Kwadrat, Kolo i Trapez, dziedziczą po klasie Figura i implementują te funkcje wirtualne zgodnie 
z odpowiednimi wzorami matematycznymi dla każdej figury.
W funkcji main() tworzone są obiekty poszczególnych klas i wywoływane są funkcje obwod() i polePowierzchni() dla każdej figury, aby wyświetlić wyniki na ekranie.
Przykładowy wynik działania programu:

Obwod trojkata rownobocznego: 15
Pole powierzchni trojkata rownobocznego: 10.8253
Obwod kwadratu: 16
Pole powierzchni kwadratu: 16
Obwod kola: 18.8496
Pole powierzchni kola: 28.2743
Obwod trapezu: 15.2195
Pole powierzchni trapezu: 16

*******************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

class Figura {
public:
    virtual float obwod() = 0;
    virtual float polePowierzchni() = 0;
};

class TrojkatRownoboczny : public Figura {
private:
    float dlugoscBoku;

public:
    TrojkatRownoboczny(float dlugosc) : dlugoscBoku(dlugosc) {}

    float obwod() {
        return 3 * dlugoscBoku;
    }

    float polePowierzchni() {
        return (sqrt(3) / 4) * dlugoscBoku * dlugoscBoku;
    }
};

class Kwadrat : public Figura {
private:
    float dlugoscBoku;

public:
    Kwadrat(float dlugosc) : dlugoscBoku(dlugosc) {}

    float obwod() {
        return 4 * dlugoscBoku;
    }

    float polePowierzchni() {
        return dlugoscBoku * dlugoscBoku;
    }
};

class Kolo : public Figura {
private:
    float promien;

public:
    Kolo(float r) : promien(r) {}

    float obwod() {
        return 2 * M_PI * promien;
    }

    float polePowierzchni() {
        return M_PI * promien * promien;
    }
};

class Trapez : public Figura {
private:
    float podstawa1;
    float podstawa2;
    float wysokosc;

public:
    Trapez(float p1, float p2, float h) : podstawa1(p1), podstawa2(p2), wysokosc(h) {}

    float obwod() {
        return podstawa1 + podstawa2 + 2 * sqrt((wysokosc * wysokosc) + ((podstawa2 - podstawa1) / 2) * ((podstawa2 - podstawa1) / 2));
    }

    float polePowierzchni() {
        return ((podstawa1 + podstawa2) / 2) * wysokosc;
    }
};

int main() {
    Figura* figura;

    figura = new TrojkatRownoboczny(5.0);
    cout << "Obwod trojkata rownobocznego: " << figura->obwod() << endl;
    cout << "Pole powierzchni trojkata rownobocznego: " << figura->polePowierzchni() << endl;

    figura = new Kwadrat(4.0);
    cout << "Obwod kwadratu: " << figura->obwod() << endl;
    cout << "Pole powierzchni kwadratu: " << figura->polePowierzchni() << endl;

    figura = new Kolo(3.0);
    cout << "Obwod kola: " << figura->obwod() << endl;
    cout << "Pole powierzchni kola: " << figura->polePowierzchni() << endl;

    figura = new Trapez(3.0, 5.0, 4.0);
    cout << "Obwod trapezu: " << figura->obwod() << endl;
    cout << "Pole powierzchni trapezu: " << figura->polePowierzchni() << endl;

    delete figura;

    return 0;
}
