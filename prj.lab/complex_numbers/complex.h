#include <iostream>
#include <cmath>


struct Complex {
    Complex() {}
    explicit Complex(const double real);
    Complex(const double real, const double imaginary);
    Complex(const Complex& rhs);
    Complex& operator=(const Complex& rhs);
    bool operator==(const Complex& rhs) const;
    bool operator!=(const Complex& rhs) const { return !operator==(rhs); }
    Complex& operator+=(const Complex& rhs);
    Complex& operator+=(const double rhs) { return operator+=(Complex(rhs)); }
    Complex& operator-=(const Complex& rhs);
    Complex& operator-=(const double rhs) { return operator-=(Complex(rhs)); }
    Complex& operator*=(const Complex& rhs);
    Complex& operator*=(const double rhs);
    Complex& operator/=(const Complex& rhs);
    Complex& operator/=(const double rhs);
    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);

    double re{0.0};
    double im{0.0};

    static const char leftBrace{'{'};
    static const char separator{','};
    static const char rightBrace{'}'};
private:
    double EPS = 1e-7;
};

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const Complex& rhs);
Complex operator+(const Complex& lhs, const double rhs);
Complex operator-(const Complex& lhs, const double rhs);
Complex operator*(const Complex& lhs, const double rhs);
Complex operator/(const Complex& lhs, const double rhs);

inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) {
    return rhs.writeTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Complex& rhs) {
    return rhs.readFrom(istrm);
}

#ifndef COMPLEX_COMPLEX_H
#define COMPLEX_COMPLEX_H

#endif
