## System aplikacji konsolowej dla warsztatu samochodowego

### Opis projektu
Ten projekt to system aplikacji konsolowej, który umożliwia zarządzanie klientami w warsztacie samochodowym. Program został napisany w języku C++ z wykorzystaniem obiektowego podejścia, co zapewnia modularność i łatwość rozbudowy. Aplikacja oferuje menu, które umożliwia dodawanie, wyświetlanie, aktualizację i usuwanie klientów, a także zapisywanie i odczytywanie danych z pliku w formacie CSV.

### Funkcje programu
- Dodawanie nowych klientów do bazy danych warsztatu
- Wyświetlanie informacji o klientach
- Aktualizacja danych klientów, takich jak imię, nazwisko, marka auta, rocznik, przebieg
- Usuwanie klientów z bazy danych
- Zapisywanie danych klientów do pliku w formacie CSV
- Odczytywanie danych klientów z pliku CSV
- Przejrzyste menu umożliwiające nawigację po różnych operacjach

### Instrukcje użytkowania
1. Sklonuj repozytorium lub pobierz pliki projektu na swój komputer.
2. Skompiluj program przy użyciu kompilatora C++.
3. Uruchom skompilowany program.

Po uruchomieniu programu zostanie wyświetlone menu główne, w którym można wybrać jedną z opcji. Naciśnij odpowiedni klawisz na klawiaturze, aby wybrać odpowiednią operację.

- **1. Dodaj klienta**: Wybierz tę opcję, aby dodać nowego klienta do bazy danych. Postępuj zgodnie z instrukcjami wyświetlanymi na ekranie i podaj wszystkie wymagane informacje.
- **2. Wyświetl klientów**: Wybierz tę opcję, aby wyświetlić informacje o wszystkich klientach z bazy danych.
- **3. Aktualizuj dane klienta**: Wybierz tę opcję, aby zaktualizować dane istniejącego klienta. Podaj identyfikator klienta oraz nowe dane.
- **4. Usuń klienta**: Wybierz tę opcję, aby usunąć klienta z bazy danych. Podaj identyfikator klienta, którego chcesz usunąć.
- **5. Zapisz dane do pliku**: Wybierz tę opcję, aby zapisać dane klientów do pliku w formacie CSV.
- **6. Odczytaj dane z pliku**: Wybierz tę opcję, aby odczytać dane klientów z pliku CSV.
- **0. Wyjście**: Wybierz tę opcję, aby zakończyć program.

### Zalecenia techniczne
- Język programowania: C++
- Kompilator: Dowolny kompilator C++ obsługujący standard C++11 lub nowszy.
- System operacyjny: Program powinien działać na dowolnym systemie operacyjnym, na którym zainstalowany jest kompilator C++.

### Licencja
Ten projekt jest udostępniany na licencji MIT. Szczegółowe informacje można znaleźć w pliku LICENSE.

### Autorzy
Ten projekt został stworzony przez: Patryk Nowoszynski.

### Przykłady
```cpp
// Kod przykładowy w celu demonstracji użycia programu
#include <iostream>
#include "Warsztat.h"

int main() {
    Warsztat warsztat;
    warsztat.wyswietlMenu();

    return 0;
}
```

### Wsparcie
Jeśli masz jakiekolwiek pytania, sugestie lub problemy dotyczące tego projektu, skontaktuj się z nami.

Dziękuję za skorzystanie z systemu aplikacji konsolowej dla warsztatu samochodowego!