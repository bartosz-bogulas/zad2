#include "LZespolona.hh"

#include <cmath>

#define EPSILON 0.1

double abs(const LZespolona& Skl) {
    return std::sqrt(std::pow(Skl.re, 2) + std::pow(Skl.im, 2));
}

LZespolona conjugate(const LZespolona& Skl) {
    return LZespolona{Skl.re, Skl.im * (-1)};
}


LZespolona operator / (const LZespolona& Skl, const double x) {
    return LZespolona{Skl.re / x, Skl.im / x};
}


LZespolona operator + (const LZespolona& Skl1, const LZespolona& Skl2) {
    return LZespolona{Skl1.re + Skl2.re, Skl1.im + Skl2.im};
}

LZespolona operator - (const LZespolona& Skl1, const LZespolona& Skl2) {
    return LZespolona{Skl1.re - Skl2.re, Skl1.im - Skl2.im};
}

LZespolona operator * (const LZespolona& Skl1, const LZespolona& Skl2) {
    return LZespolona{Skl1.re * Skl2.re - Skl1.im * Skl2.im, Skl1.re * Skl2.im + Skl1.im * Skl2.re};
}

LZespolona operator / (const LZespolona& Skl1, const LZespolona& Skl2) {
    return (Skl1 * conjugate(Skl2)) / std::pow(abs(Skl2), 2);
}


std::ostream& operator << (std::ostream& out, const LZespolona& Skl) {
    out << "(" << Skl.re;

    if (Skl.im >= 0)
        out << "+";

    out << Skl.im << "i)";
    return out;
}

std::istream& operator >> (std::istream& in, LZespolona& Skl) {
    char outer, inner, sign;

    if (!(in >> outer)) {
        return in;
    }

    if (outer != '(') {
        in.setstate(std::ios::failbit);
        return in;
    }

    if (!(in >> Skl.re)) {
        return in;
    }

    if (!(in >> Skl.im)) {
        return in;
    }

    if (!(in >> sign)) {
        return in;
    }

    if (sign != 'i') {
        in.setstate(std::ios::failbit);
        return in;
    }

    if (!(in >> inner)) {
        return in;
    }

    if (inner != ')') {
        in.setstate(std::ios::failbit);
    }

    return in;
}

bool epsilon(const double x, const double y) {
    return fabs(x - y) < EPSILON;
}

bool operator == (const LZespolona& Skl1, const LZespolona& Skl2) {
    return epsilon(Skl1.re, Skl2.re) && epsilon(Skl1.im, Skl2.im);
}
