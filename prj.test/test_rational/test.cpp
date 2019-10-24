// Copyright 2019 by Burkov Dmitrii under Free Public License 1.0.1

#include <iostream>
#include <sstream>
#include <rational/rational.h>

int main() {
    std::cout << "Standart constructor Rational(): " << Rational() << std::endl;
    std::cout << "From one Int constructor Rational(5): " << Rational(5) << std::endl;
    std::cout << "From two Int constructor Rational(12, -63): " << Rational(12, -63) << std::endl;
    std::cout << "Constructor with `0` in denumenator Rational(123, 0): ";

    try {
        Rational(123, 0);
    } catch(const std::invalid_argument& ex) {
        std::cout << ex.what() << std::endl;
    }

    Rational test1(5, -3), test2(1, 2);

    std::cout << "\nAssign tests: test1(5, -3) and test2(1, 2)\n";
    std::cout << "test1 = test2; print test1: " << test1 << std::endl;

    std::cout << "\nSum tests: " << std::endl;
    std::cout << "1/3 + 1/6 = "
              << Rational(3, 9) + Rational(5, 30) << std::endl;
    std::cout << "-2/3 + 1/6 = "
              << Rational(-6, 9) + Rational(1, 6) << std::endl;
    std::cout << "4/9 + (-1/4) = "
              << Rational(16, 36) + Rational(2, -8) << std::endl;

    std::cout << "\nDifference tests: " << std::endl;
    std::cout << "1/3 - 1/6 = "
              << Rational(3, 9) - Rational(5, 30) << std::endl;
    std::cout << "-2/3 - 1/6 = "
              << Rational(-6, 9) - Rational(1, 6) << std::endl;
    std::cout << "4/9 - (-1/4) = "
              << Rational(16, 36) - Rational(2, -8) << std::endl;

    std::cout << "\nMultiplication tests: " << std::endl;
    std::cout << "1/3 * 1/6 = "
              << Rational(3, 9) * Rational(5, 30) << std::endl;
    std::cout << "-2/3 * 1/6 = "
              << Rational(-6, 9) * Rational(1, 6) << std::endl;
    std::cout << "4/9 * (-1/4) = "
              << Rational(16, 36) * Rational(2, -8) << std::endl;

    std::cout << "\nDivision tests: " << std::endl;
    std::cout << "1/3 / 1/6 = "
              << Rational(3, 9) / Rational(5, 30) << std::endl;
    std::cout << "-2/3 / 1/6 = "
              << Rational(-6, 9) / Rational(1, 6) << std::endl;
    std::cout << "4/9 / (-1/4) = "
              << Rational(16, 36) / Rational(2, -8) << std::endl;
    std::cout << "1/2 / 0 = ";
    try {
        Rational(1/2) / 0;
    } catch(const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\nEqual tests: " << std::endl;
    std::cout << "1/3 == 1/6: "
              << (Rational(3, 9) == Rational(5, 30)) << std::endl;
    std::cout << "1/2 == 1/2: "
              << (Rational(1, 2) == Rational(2, 4)) << std::endl;
    std::cout << "6/2 == 3: " << (Rational(6/2) == 3) << std::endl;

    std::cout << "\nInput tests: "<< std::endl;
    std::istringstream ss("5/30 0 4/-5 -6/3 34t45/23sdf4 345/0");
    ss >> test1;
    std::cout << "input: 5/30  --> " << test1 << std::endl;
    ss >> test1;
    std::cout << "input: 0  --> " << test1  << std::endl;
    ss >> test1;
    std::cout << "input: 4/-5  --> " << test1  << std::endl;
    ss >> test1;
    std::cout << "input: -6/3  --> " << test1  << std::endl;

    std::cout << "input: 34t45/23sdf4  --> ";
    ss >> test1;
    std::cout << "input: 345/0  --> ";
    ss >> test1;

    return 0;
}
