#pragma once

#include <iostream>
#include <string>

int FindGcd(int first, int second);

class Rational {
public:
    Rational() {}

    explicit Rational(const int num, const int denum);
    Rational(const int num);

    int GetNumerator() const { return Numerator; }
    int GetDenumerator() const { return Denumenator; }

    Rational& operator +=(const Rational& num);
    Rational& operator -=(const Rational& num);
    Rational& operator *=(const Rational& num);
    Rational& operator /=(const Rational& num);

    bool operator ==(const Rational& second);
    bool operator !=(const Rational& second);

private:
    int Numerator = 0;
    int Denumenator = 1;

    void Reduce();
};

Rational operator +(const Rational& first, const Rational& second);
Rational operator -(const Rational& first, const Rational& second);
Rational operator *(const Rational& first, const Rational& second);
Rational operator /(const Rational& first, const Rational& second);

std::istream& operator >>(std::istream& in, Rational& num);
std::ostream& operator <<(std::ostream& out, const Rational& num);

#ifndef RATIONAL_NUMBER_RATIONAL_H
#define RATIONAL_NUMBER_RATIONAL_H

#endif //RATIONAL_NUMBER_RATIONAL_H
