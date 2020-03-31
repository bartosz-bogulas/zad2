#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH

#include "LZespolona.hh"

enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };

struct WyrazenieZesp {
    LZespolona Arg1;
    Operator Op;
    LZespolona Arg2;
};

void Wyswietl(const WyrazenieZesp& WyrZ);
LZespolona Oblicz(const WyrazenieZesp& WyrZ);

#endif
