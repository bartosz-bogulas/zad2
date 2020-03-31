#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include <iostream>

struct LZespolona {
    double re;
    double im;
};

double abs(const LZespolona& Skl);
LZespolona conjugate(const LZespolona& Skl);

LZespolona operator / (const LZespolona& Skl, double x);

LZespolona operator + (const LZespolona& Skl1, const LZespolona& Skl2);
LZespolona operator - (const LZespolona& Skl1, const LZespolona& Skl2);
LZespolona operator * (const LZespolona& Skl1, const LZespolona& Skl2);
LZespolona operator / (const LZespolona& Skl1, const LZespolona& Skl2);

std::ostream& operator << (std::ostream& out, const LZespolona& Skl);
std::istream& operator >> (std::istream& in, LZespolona& Skl);

bool operator == (const LZespolona& Skl1, const LZespolona& Skl2);

#endif
