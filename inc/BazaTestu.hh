#ifndef BAZATESTU_HH
#define BAZATESTU_HH

#include "WyrazenieZesp.hh"

struct BazaTestu {
    WyrazenieZesp *wskTabTestu;
    unsigned int IloscPytan;
    unsigned int IndeksPytania;
};

bool InicjalizujTest(BazaTestu* wskBazaTestu, const char* sNazwaTestu);
bool PobierzNastepnePytanie(BazaTestu* wskBazaTestu, WyrazenieZesp* wskWyr);

#endif
