#include "WyrazenieZesp.hh"

void Wyswietl(const WyrazenieZesp& WyrZ) {
    std::cout << WyrZ.Arg1 << " ";

    switch (WyrZ.Op) {
        case Op_Dodaj : std::cout << "+"; break;
        case Op_Odejmij : std::cout << "-"; break;
        case Op_Mnoz : std::cout << "*"; break;
        case Op_Dziel : std::cout << "/"; break;
    }

    std::cout << " " << WyrZ.Arg2;
}

LZespolona Oblicz(const WyrazenieZesp& WyrZ) {
    switch (WyrZ.Op) {
        case Op_Dodaj : return WyrZ.Arg1 + WyrZ.Arg2;
        case Op_Odejmij : return WyrZ.Arg1 - WyrZ.Arg2;
        case Op_Mnoz: return WyrZ.Arg1 * WyrZ.Arg2;
        case Op_Dziel : return WyrZ.Arg1 / WyrZ.Arg2;
    }
}
