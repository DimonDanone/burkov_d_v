#include "complex.h"

Complex::Complex(const double real)
        : Complex(real, 0.0) {
}

Complex::Complex(const double real, const double imaginary)
        : re(real)
        , im(imaginary)
{}

Complex::Complex(const Complex& rhs)
        : re(rhs.re)
        , im(rhs.im)
{}

Complex& Complex::operator=(const Complex& rhs) {
    re = rhs.re;
    im = rhs.im;

    return *this;
}

bool Complex::operator==(const Complex& rhs) const {
    return fabs(re - rhs.re) <= eps && fabs(im - rhs.im) <= eps;
}

Complex& Complex::operator+=(const Complex& rhs) {
    re += rhs.re;
    im += rhs.im;
    return *this;
}

Complex operator+(const Complex& lhs, const Complex& rhs) {
    Complex sum(lhs);
    sum += rhs;
    return sum;
}

Complex& Complex::operator-=(const Complex& rhs) {
    re -= rhs.re;
    im -=rhs.im;

    return *this;
}

Complex operator-(const Complex& lhs, const Complex& rhs) {
    Complex res(lhs);
    res -= rhs;

    return res;
}

Complex& Complex::operator*=(const double rhs) {
    re *= rhs;
    im *= rhs;
    return *this;
}

Complex& Complex::operator*=(const Complex& rhs) {
    double new_re = re * rhs.re - im * rhs.im;
    im = re * rhs.im + im * rhs.re;
    re = new_re;

    return *this;
}

Complex operator*(const Complex& lhs, const Complex& rhs) {
    Complex res(lhs);
    res *= rhs;

    return res;
}

Complex& Complex::operator/=(const Complex& rhs) {
    double denum = rhs.re*rhs.re + rhs.im*rhs.im;
    double num_re = re*rhs.re + im*rhs.im;
    double num_im = rhs.re*im - re*rhs.im;
    re = num_re / denum;
    im = num_im / denum;

    return *this;
}

Complex operator/(const Complex& lhs, const Complex& rhs) {
    Complex res(lhs);
    res /= rhs;

    return res;
}

Complex& Complex::operator/=(const double rhs) {
    return operator/=(Complex(rhs));
}

Complex operator+(const Complex& lhs, const double rhs) {
    return operator+(lhs, Complex(rhs));
}

Complex operator-(const Complex& lhs, const double rhs) {
    return operator-(lhs, Complex(rhs));
}

Complex operator*(const Complex& lhs, const double rhs) {
    return operator*(lhs, Complex(rhs));
}

Complex operator/(const Complex& lhs, const double rhs) {
    return operator/(lhs, Complex(rhs));
}

Complex operator+(const double lhs, const Complex& rhs) {
    return operator+(Complex(lhs), rhs);
}

Complex operator-(const double lhs, const Complex& rhs) {
    return operator-(Complex(lhs), rhs);
}

Complex operator*(const double lhs, const Complex& rhs) {
    return operator*(Complex(lhs), rhs);
}

Complex operator/(const double lhs, const Complex& rhs) {
    return operator/(Complex(lhs), rhs);
}

std::ostream& Complex::writeTo(std::ostream& ostrm) const {
    ostrm << leftBrace << re << separator << " " << im << rightBrace;
    return ostrm;
}

std::istream& Complex::readFrom(std::istream& istrm) {
    char leftBrace(0);
    double real(0.0);
    char comma(0);
    double imaganary(0.0);
    char rightBrace(0);
    istrm >> leftBrace >> real >> comma >> imaganary >> rightBrace;
    if (istrm.good()) {
        if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma) &&
            (Complex::rightBrace == rightBrace)) {
            re = real;
            im = imaganary;
        } else {
            istrm.setstate(std::ios_base::failbit);
        }
    }

    return istrm;
}
