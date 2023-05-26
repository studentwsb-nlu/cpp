/******************************************************************************

                              Zadanie 3 - Patryk Nowoszynski

 Zadanie 3

    Dopisać braujące klasy, kolo, trojkat.
    W mian wyswietlić pole oraz obwód figur.
    Dodatkowo stworzyć operatorem new jeszcze jedną figurę kolo 2 oraz trojakt 2  i powrównać który z nich ma większe pole i większy obwód.


*******************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

class Kolo {
private:
    double promien;

public:
    Kolo(double r) : promien(r) {}

    double obwod() const {
        return 2 * M_PI * promien;
    }

    double pole() const {
        return M_PI * pow(promien, 2);
    }
};

class Trojkat {
private:
    double a, b, c;

public:
    Trojkat(double sideA, double sideB, double sideC)
        : a(sideA), b(sideB), c(sideC) {}

    double obwod() const {
        return a + b + c;
    }

    double pole() const {
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
};

int main() {
    Kolo k1(5.0);
    Trojkat t1(3.0, 4.0, 5.0);

    cout << "Kolo:" << endl;
    cout << "Obwod: " << k1.obwod() << endl;
    cout << "Pole: " << k1.pole() << endl;

    cout << endl;

    cout << "Trojkat:" << endl;
    cout << "Obwod: " << t1.obwod() << endl;
    cout << "Pole: " << t1.pole() << endl;

    cout << endl;

    Kolo* k2 = new Kolo(7.0);
    Trojkat* t2 = new Trojkat(4.0, 5.0, 6.0);

    cout << "Kolo 2:" << endl;
    cout << "Obwod: " << k2->obwod() << endl;
    cout << "Pole: " << k2->pole() << endl;

    cout << endl;

    cout << "Trojkat 2:" << endl;
    cout << "Obwod: " << t2->obwod() << endl;
    cout << "Pole: " << t2->pole() << endl;

    cout << endl;

    if (k2->pole() > t2->pole()) {
        cout << "Kolo 2 ma wieksze pole" << endl;
    } else if (k2->pole() < t2->pole()) {
        cout << "Trojkat 2 ma wieksze pole" << endl;
    } else {
        cout << "Kolo 2 i Trojkat 2 maja rowne pole" << endl;
    }

    if (k2->obwod() > t2->obwod()) {
        cout << "Kolo 2 ma wiekszy obwod" << endl;
    } else if (k2->obwod() < t2->obwod()) {
        cout << "Trojkat 2 ma wiekszy obwod" << endl;
    } else {
        cout << "Kolo 2 i Trojkat 2 maja rowny obwod" << endl;
    }

    delete k2;
    delete t2;

    return 0;
}
