// Copyright 2019 by Burkov Dmitrii under Free Public License 1.0.1

#include <iostream>
#include <string>

int FindGcd(int first, int second);

class Rational {
public:
    Rational() = default;
    Rational(const int num, const int denum);
    explicit Rational(const int num);
    Rational(const Rational& new_num);

    int GetNumerator() const { return Numerator; }
    int GetDenumerator() const { return Denumenator; }

    Rational& operator +=(const Rational& num);
    Rational& operator -=(const Rational& num);
    Rational& operator *=(const Rational& num);
    Rational& operator /=(const Rational& num);
    Rational& operator +=(const int num);
    Rational& operator -=(const int num);
    Rational& operator *=(const int num);
    Rational& operator /=(const int num);

    bool operator ==(const Rational& second) const;
    bool operator !=(const Rational& second) const;
    bool operator >(const Rational& second) const;
    bool operator <(const Rational& second) const;
    bool operator <=(const Rational& second) const;
    bool operator >=(const Rational& second) const;
    bool operator ==(const int second) const;
    bool operator !=(const int second) const;

    Rational& operator =(const Rational& num);

private:
    int Numerator = 0;
    int Denumenator = 1;

    void Reduce();
};

Rational operator +(const Rational& first, const Rational& second);
Rational operator -(const Rational& first, const Rational& second);
Rational operator *(const Rational& first, const Rational& second);
Rational operator /(const Rational& first, const Rational& second);

Rational operator +(const Rational& first, const int second);
Rational operator -(const Rational& first, const int second);
Rational operator *(const Rational& first, const int second);
Rational operator /(const Rational& first, const int second);

Rational operator-(const Rational& rhs);

std::istream& operator >>(std::istream& in, Rational& num);
std::ostream& operator <<(std::ostream& out, const Rational& num);

#ifndef RATIONAL_NUMBER_RATIONAL_H
#define RATIONAL_NUMBER_RATIONAL_H

#endif
