#include "rational.h"

int FindGcd(int first, int second) {
    if (second == 0) {
        return first;
    }

    return FindGcd(second, first % second);
}

int FindLcm(int first, int second) {

    return first * second / FindGcd(first, second);
}

Rational::Rational(const int num, const int denum)
        : Numerator(num)
        , Denumenator(denum)
{
    if (Denumenator == 0) {
        throw std::invalid_argument("bad value in constructor");
    }
    Reduce();
}

Rational::Rational(const int num)
        : Rational(num, 1)
{}

void Rational::Reduce() {
    int gcd = FindGcd(Numerator, Denumenator);

    Numerator = Numerator / gcd;
    Denumenator = Denumenator / gcd;

    if (Denumenator < 0) {
        Numerator *= -1;
        Denumenator *= -1;
    }
}

bool Rational::operator ==(const Rational& second) {
    return Numerator == second.Numerator && Denumenator == second.Denumenator;
}

bool Rational::operator !=(const Rational &second) {
    return !operator==(second);
}

std::istream& operator >>(std::istream& in, Rational& num) {
    std::string input;
    int numerator, denumenator = 1;
    in >> input;

    int pos = -1;

    for (size_t i = 0; i < input.size(); ++i) {
        if ((input[i] > '9' || input[i] < '0') && input[i] != '/' && input[i] != '-') {
            throw std::invalid_argument("invalid input");
        } else if (input[i] == '/') {
            pos = i;
        }
    }

    if (pos != -1) {
        numerator = stoi(input.substr(0, pos));
        denumenator = stoi(input.substr(pos + 1, input.size() - pos));
    } else {
        numerator = stoi(input);
    }

    num = Rational(numerator, denumenator);

    return in;
}

std::ostream& operator <<(std::ostream& out, const Rational& num) {
    out << num.GetNumerator();
    if (num.GetDenumerator() != 1) {
        out << "/" << num.GetDenumerator();
    }

    return out;
}

Rational& Rational::operator *=(const Rational &num) {
    Numerator *= num.Numerator;
    Denumenator *= num.Denumenator;
    Reduce();

    return *this;
}

Rational& Rational::operator /=(const Rational &num) {
    Numerator *= num.Denumenator;
    Denumenator *= num.Numerator;
    Reduce();

    return *this;
}

Rational& Rational::operator +=(const Rational &num) {
    int lcm = FindLcm(Denumenator, num.Denumenator);
    Numerator = Numerator * lcm / Denumenator + num.Numerator * lcm / num.Denumenator;
    Denumenator = lcm;
    Reduce();

    return *this;
}

Rational& Rational::operator -=(const Rational &num) {
    int lcm = FindLcm(Denumenator, num.Denumenator);
    Numerator = Numerator * lcm / Denumenator - num.Numerator * lcm / num.Denumenator;
    Denumenator = lcm;
    Reduce();

    return *this;
}

Rational operator +(const Rational& first, const Rational& second) {
    Rational res = first;
    res += second;

    return res;
}

Rational operator -(const Rational& first, const Rational& second) {
    Rational res = first;
    res -= second;

    return res;
}

Rational operator *(const Rational& first, const Rational& second) {
    Rational res = first;
    res *= second;

    return res;
}

Rational operator /(const Rational& first, const Rational& second) {
    Rational res = first;
    res /= second;

    return res;
}
