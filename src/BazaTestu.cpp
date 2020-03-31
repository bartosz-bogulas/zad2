#include <iostream>
#include <cstring>
#include "BazaTestu.hh"

using namespace std;

static WyrazenieZesp TestLatwy[] = {
    {{2,1}, Op_Dodaj, {1,2}},
    {{1,0}, Op_Odejmij, {0,1}},
    {{3,0}, Op_Mnoz, {0,3}},
    {{4,8}, Op_Dziel, {1,0}}
};

static WyrazenieZesp TestTrudny[] = {
    {{2.7,1.3}, Op_Dodaj, {1.5,-2.5}},
    {{1,0.65}, Op_Odejmij, {0,1.7}},
    {{3.5,10}, Op_Mnoz, {0.3,3.7}},
    {{4.2,8.8}, Op_Dziel, {1.8,0.2}}
};

void UstawTest(BazaTestu* wskBazaTestu, WyrazenieZesp* wskTabTestu, unsigned int IloscPytan) {
    wskBazaTestu->wskTabTestu = wskTabTestu;
    wskBazaTestu->IloscPytan = IloscPytan;
    wskBazaTestu->IndeksPytania = 0;
}

bool InicjalizujTest(BazaTestu* wskBazaTestu, const char* sNazwaTestu) {
    if (!strcmp(sNazwaTestu,"latwy")) {
        UstawTest(wskBazaTestu, TestLatwy, sizeof(TestLatwy) / sizeof(WyrazenieZesp));
        return true;
    }

    if (!strcmp(sNazwaTestu, "trudny")) {
        UstawTest(wskBazaTestu, TestTrudny, sizeof(TestTrudny) / sizeof(WyrazenieZesp));
        return true;
    }

    cerr << "Otwarcie testu '" << sNazwaTestu << "' nie powiodlo sie." << endl;
    return false;
}

bool PobierzNastepnePytanie(BazaTestu* wskBazaTestu, WyrazenieZesp* wskWyrazenie) {
    if (wskBazaTestu->IndeksPytania >= wskBazaTestu->IloscPytan)
        return false;

    *wskWyrazenie = wskBazaTestu->wskTabTestu[wskBazaTestu->IndeksPytania];
    ++wskBazaTestu->IndeksPytania;
    return true;
}
