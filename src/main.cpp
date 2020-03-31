#include <iostream>
#include <limits>
#include "BazaTestu.hh"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << std::endl;
        std::cout << "Brak opcji okreslajacej rodzaj testu." << std::endl;
        std::cout << "Dopuszczalne nazwy to: latwy, trudny." << std::endl;
        std::cout << std::endl;
        return 1;
    }

    BazaTestu BazaT = {nullptr,0,0};

    if (!InicjalizujTest(&BazaT,argv[1])) {
        std::cerr << "Inicjalizacja testu nie powiodla sie." << std::endl;
        return 1;
    }

    std::cout << std::endl;
    std::cout << "Start testu arytmetyki zespolonej: " << argv[1] << std::endl;
    std::cout << std::endl;

    WyrazenieZesp WyrZ_PytanieTestowe;
    LZespolona Skl_Testowa;

    while (PobierzNastepnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
        std::cout << ":? Podaj wynik operacji: ";
        Wyswietl(WyrZ_PytanieTestowe);
        std::cout << " =" << std::endl;

        bool repeat;
        do {
            std::cout << "   Twoja odpowiedz: ";
            std::cin >> Skl_Testowa;

            repeat = std::cin.fail();

            if (repeat) {
                std::cout << ":! Blad zapisu liczby zespolonej. Sprobuj jeszcze raz." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while(repeat);

        LZespolona Skl_PytanieTestowe = Oblicz(WyrZ_PytanieTestowe);

        if (Skl_PytanieTestowe == Skl_Testowa) {
            std::cout << ":) Odpowiedz poprawna";
        } else {
            std::cout << ":( Blad. Poprawnym wynikiem jest: " << Skl_PytanieTestowe;
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Koniec testu" << std::endl;
    std::cout << std::endl;
}
