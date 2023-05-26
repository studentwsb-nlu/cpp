#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Klient {
private:
    string imie;
    string nazwisko;
    string adres;
    string marka;
    int rocznik;
    int przebieg;

public:
    Klient() {}

    Klient(const string& imie, const string& nazwisko, const string& adres, const string& marka, int rocznik, int przebieg) {
        this->imie = imie;
        this->nazwisko = nazwisko;
        this->adres = adres;
        this->marka = marka;
        this->rocznik = rocznik;
        this->przebieg = przebieg;
    }

    string getImie() const {
        return imie;
    }

    string getNazwisko() const {
        return nazwisko;
    }

    string getAdres() const {
        return adres;
    }

    string getMarka() const {
        return marka;
    }

    int getRocznik() const {
        return rocznik;
    }

    int getPrzebieg() const {
        return przebieg;
    }
};

class Warsztat {
private:
    vector<Klient> klienci;

public:
    Warsztat() {}

    void dodajKlienta(const Klient& klient) {
        klienci.push_back(klient);
    }

    void wyswietlKlientow() const {
        for (const auto& klient : klienci) {
            cout << "Imie: " << klient.getImie() << endl;
            cout << "Nazwisko: " << klient.getNazwisko() << endl;
            cout << "Adres: " << klient.getAdres() << endl;
            cout << "Marka auta: " << klient.getMarka() << endl;
            cout << "Rocznik auta: " << klient.getRocznik() << endl;
            cout << "Przebieg auta: " << klient.getPrzebieg() << endl;
            cout << endl;
        }
    }

    const vector<Klient>& getKlienci() const {
        return klienci;
    }
};

int main() {
    Warsztat warsztat;

    int wybor;
    do {
        cout << "===== MENU =====" << endl;
        cout << "1. Dodaj klienta" << endl;
        cout << "2. Wyswietl klientow" << endl;
        cout << "3. Zapisz dane do pliku" << endl;
        cout << "4. Wczytaj dane z pliku" << endl;
        cout << "0. Wyjdz" << endl;
        cout << "Wybor: ";
        cin >> wybor;
        cin.ignore();

        switch (wybor) {
            case 1: {
                string imie, nazwisko, adres, marka;
                int rocznik, przebieg;

                cout << "Podaj imie: ";
                getline(cin, imie);
                cout << "Podaj nazwisko: ";
                getline(cin, nazwisko);
                cout << "Podaj adres: ";
                getline(cin, adres);
                cout << "Podaj marke auta: ";
                getline(cin, marka);
                cout << "Podaj rocznik auta: ";
                cin >> rocznik;
                cout << "Podaj przebieg auta: ";
                cin >> przebieg;
                cin.ignore();

                Klient klient(imie, nazwisko, adres, marka, rocznik, przebieg);
                warsztat.dodajKlienta(klient);
                cout << "Klient zostal dodany." << endl;
                break;
            }
            case 2: {
                cout << "Klienci:" << endl;
                warsztat.wyswietlKlientow();
                break;
            }
            case 3: {
                string nazwaPliku;
                cout << "Podaj nazwe pliku: ";
                getline(cin, nazwaPliku);

                ofstream file(nazwaPliku);
                if (file.is_open()) {
                    file << "Imie,Nazwisko,Adres,Marka,Rocznik,Przebieg" << endl;
                    for (const auto& klient : warsztat.getKlienci()) {
                        file << klient.getImie() << "," << klient.getNazwisko() << "," << klient.getAdres() << ","
                             << klient.getMarka() << "," << klient.getRocznik() << "," << klient.getPrzebieg() << endl;
                    }
                    file.close();
                    cout << "Dane zostaly zapisane do pliku." << endl;
                } else {
                    cout << "Blad podczas otwierania pliku." << endl;
                }
                break;
            }
            case 4: {
                string nazwaPliku;
                cout << "Podaj nazwe pliku: ";
                getline(cin, nazwaPliku);

                ifstream file(nazwaPliku);
                if (file.is_open()) {
                    string line;
                    getline(file, line);  // Skip the header line
                    while (getline(file, line)) {
                        stringstream ss(line);
                        string imie, nazwisko, adres, marka;
                        int rocznik, przebieg;

                        getline(ss, imie, ',');
                        getline(ss, nazwisko, ',');
                        getline(ss, adres, ',');
                        getline(ss, marka, ',');
                        ss >> rocznik;
                        ss.ignore();
                        ss >> przebieg;

                        Klient klient(imie, nazwisko, adres, marka, rocznik, przebieg);
                        warsztat.dodajKlienta(klient);
                    }
                    file.close();
                    cout << "Dane zostaly wczytane z pliku." << endl;
                } else {
                    cout << "Blad podczas otwierania pliku." << endl;
                }
                break;
            }
            case 0:
                cout << "Koniec programu." << endl;
                break;
            default:
                cout << "Niepoprawny wybor." << endl;
        }

        cout << endl;
    } while (wybor != 0);

    return 0;
}
