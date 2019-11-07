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

Rational::Rational(const Rational& new_num) {
    *this = new_num;
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

Rational& Rational::operator=(const Rational& num) {
    Numerator = num.Numerator;
    Denumenator = num.Denumenator;

    return *this;
}

bool Rational::operator==(const Rational& second) const {
    return Numerator == second.Numerator && Denumenator == second.Denumenator;
}

bool Rational::operator==(const int second) const {
    return operator==(Rational(second));
}

bool Rational::operator!=(const Rational& second) const {
    return !operator==(second);
}

bool Rational::operator!=(const int second) const {
    return !operator==(Rational(second));
}

bool Rational::operator>(const Rational& second) const {
    int lcm = FindLcm(Denumenator, second.Denumenator);
    return Numerator * lcm / Denumenator > second.Numerator * lcm / second.Denumenator;
}

bool Rational::operator>=(const Rational& second) const {
    return operator==(second) || operator>(second);
}

bool Rational::operator<(const Rational& second) const {
    return !operator>=(second);
}

bool Rational::operator<=(const Rational& second) const {
    return !operator>(second);
}

Rational operator-(const Rational& rhs) {
    return Rational(-rhs.GetNumerator(), rhs.GetDenumerator());
}

std::istream& operator>>(std::istream& in, Rational& num) {
    if (in.good()) {
      int numerator, denumenator = 1;
      char sep;
      in >> numerator;
      if (in.peek() == '/') {
        in >> sep;
      } else {
        in.setstate(std::ios_base::failbit);
        return in;
      }
      if (in.peek() >= '0' && in.peek() <= '9') {
        in >> denumenator;
      } else {
        in.setstate(std::ios_base::failbit);
        return in;
      }
      
      if (sep == '/' && denumenator > 0) {
          num = Rational(numerator, denumenator);
      } else {
          in.setstate(std::ios_base::failbit);
      }
  }

    return in;
}

std::ostream& operator<<(std::ostream& out, const Rational& num) {
    out << num.GetNumerator() << "/" << num.GetDenumerator();

    return out;
}

Rational& Rational::operator*=(const Rational& num) {
    Numerator *= num.Numerator;
    Denumenator *= num.Denumenator;
    Reduce();

    return *this;
}

Rational& Rational::operator*=(const int num) {
    return operator*=(Rational(num));
}

Rational& Rational::operator/=(const Rational& num) {
    if (num == 0) {
        throw std::invalid_argument("0 division");
    }

    Numerator *= num.Denumenator;
    Denumenator *= num.Numerator;
    Reduce();

    return *this;
}

Rational& Rational::operator/=(const int num) {
    return operator/=(Rational(num));
}

Rational& Rational::operator+=(const Rational &num) {
    int lcm = FindLcm(Denumenator, num.Denumenator);
    Numerator = Numerator * lcm / Denumenator
                + num.Numerator * lcm / num.Denumenator;
    Denumenator = lcm;
    Reduce();

    return *this;
}

Rational& Rational::operator+=(const int num) {
    return operator+=(Rational(num));
}

Rational& Rational::operator-=(const Rational &num) {
    int lcm = FindLcm(Denumenator, num.Denumenator);
    Numerator = Numerator * lcm / Denumenator
                - num.Numerator * lcm / num.Denumenator;
    Denumenator = lcm;
    Reduce();

    return *this;
}

Rational& Rational::operator-=(const int num) {
    return operator-=(Rational(num));
}

Rational operator+(const Rational& first, const Rational& second) {
    Rational res = first;
    res += second;

    return res;
}

Rational operator+(const Rational& first, const int second) {
    return first + Rational(second);
}

Rational operator-(const Rational& first, const Rational& second) {
    Rational res = first;
    res -= second;

    return res;
}

Rational operator-(const Rational& first, const int second) {
    return first - Rational(second);
}

Rational operator*(const Rational& first, const Rational& second) {
    Rational res = first;
    res *= second;

    return res;
}

Rational operator*(const Rational& first, const int second) {
    return first * Rational(second);
}

Rational operator/(const Rational& first, const Rational& second) {
    Rational res = first;
    res /= second;

    return res;
}

Rational operator/(const Rational& first, const int second) {
    return first / Rational(second);
}
