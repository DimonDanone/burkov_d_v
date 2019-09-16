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

bool operator ==(const Rational& first, const Rational& second) {
    return first.Numerator == second.Numerator && first.Denumenator == second.Denumenator;
}

bool operator !=(const Rational& first, const Rational& second) {
    return !(first == second);
}

std::istream& operator >>(std::istream& in, Rational& num) {
    std::string st;
    in >> st;

    int pos = st.find('/');
    if (pos != std::string::npos) {
       num.Numerator = stoi(st.substr(0, pos));
       num.Denumenator = stoi(st.substr(pos + 1, st.size() - pos));
    } else {
        num.Numerator = stoi(st);
    }

    num.Reduce();

    return in;
}

std::ostream& operator <<(std::ostream& out, const Rational& num) {
    out << num.Numerator;
    if (num.Denumenator != 1) {
        out << "/" << num.Denumenator;
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
