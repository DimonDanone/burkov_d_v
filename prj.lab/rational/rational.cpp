// Copyright 2019 by Burkov Dmitrii under Free Public License 1.0.1

#include "rational.h"
#include <sstream>

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
        , Denumenator(denum) {
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

Rational& Rational::operator =(const Rational& num) {
    Numerator = num.Numerator;
    Denumenator = num.Denumenator;

    return *this;
}

bool Rational::operator ==(const Rational& second) const {
    return Numerator == second.Numerator && Denumenator == second.Denumenator;
}

bool Rational::operator ==(const int second) const {
    return operator==(Rational(second));
}

bool Rational::operator !=(const Rational& second) const {
    return !operator==(second);
}

bool Rational::operator !=(const int second) const {
    return !operator==(second);
}

std::istream& operator >>(std::istream& in, Rational& num) {
    std::string input;
    int numerator, denumenator = 1;
    char sep;
    in >> input;
    std::stringstream ss(input);

    std::string st_num = "";
    std::string st_denum = "";

    int start = 0;
    if (input[0] == '-') {
        start = 1;
        st_num += "-";
    }

    bool is_now_num = true;

    for (size_t i = start; i < input.size(); ++i) {
        if (input[i] <= '9' && input[i] >= '0') {
            if (is_now_num) {
                st_num += input[i];
            } else {
                st_denum += input[i];
            }
        } else if (input[i] == '/') {
            is_now_num = false;
        } else if (!is_now_num && input[i - 1] == '/' && input[i] == '-') {
            st_denum += input[i];
        } else {
            std::cout << "wrong input\n";
            return in;
        }
    }

    numerator = std::stoi(st_num);
    if (st_denum != "" && st_denum != "-") {
        denumenator = std::stoi(st_denum);
    }

    if (!denumenator) {
        std::cout << "0 in input\n";
        return in;
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

Rational& Rational::operator *=(const Rational& num) {
    Numerator *= num.Numerator;
    Denumenator *= num.Denumenator;
    Reduce();

    return *this;
}

Rational& Rational::operator *=(const int num) {
    return operator*=(Rational(num));
}

Rational& Rational::operator /=(const Rational& num) {
    if (num == 0) {
        throw std::invalid_argument("0 division");
    }

    Numerator *= num.Denumenator;
    Denumenator *= num.Numerator;
    Reduce();

    return *this;
}

Rational& Rational::operator /=(const int num) {
    return operator/=(Rational(num));
}

Rational& Rational::operator +=(const Rational &num) {
    int lcm = FindLcm(Denumenator, num.Denumenator);
    Numerator = Numerator * lcm / Denumenator
                + num.Numerator * lcm / num.Denumenator;
    Denumenator = lcm;
    Reduce();

    return *this;
}

Rational& Rational::operator +=(const int num) {
    return operator+=(Rational(num));
}

Rational& Rational::operator -=(const Rational &num) {
    int lcm = FindLcm(Denumenator, num.Denumenator);
    Numerator = Numerator * lcm / Denumenator
                - num.Numerator * lcm / num.Denumenator;
    Denumenator = lcm;
    Reduce();

    return *this;
}

Rational& Rational::operator -=(const int num) {
    return operator-=(Rational(num));
}

Rational operator +(const Rational& first, const Rational& second) {
    Rational res = first;
    res += second;

    return res;
}

Rational operator +(const Rational& first, const int second) {
    return first + Rational(second);
}

Rational operator -(const Rational& first, const Rational& second) {
    Rational res = first;
    res -= second;

    return res;
}

Rational operator -(const Rational& first, const int second) {
    return first - Rational(second);
}

Rational operator *(const Rational& first, const Rational& second) {
    Rational res = first;
    res *= second;

    return res;
}

Rational operator *(const Rational& first, const int second) {
    return first * Rational(second);
}

Rational operator /(const Rational& first, const Rational& second) {
    Rational res = first;
    res /= second;

    return res;
}

Rational operator /(const Rational& first, const int second) {
    return first / Rational(second);
}
