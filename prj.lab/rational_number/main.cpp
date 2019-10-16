// Copyright 2019 by Burkov Dmitrii under Free Public License 1.0.1

#include <iostream>
#include <sstream>
#include "rational.h"

int main() {
    std::cout << "Standart constructor Rational(): " << Rational() << std::endl;
    std::cout << "From one Int constructor Rational(2): " << Rational(2) << std::endl;
    std::cout << "From two Int constructor Rational(9, 21): " << Rational(9, 21) << std::endl;
    std::cout << "Constructor with `0` in denumenator Rational(123, 0): ";

    try {
        Rational(123, 0);
    } catch(const std::invalid_argument& ex) {
        std::cout << ex.what() << std::endl;
    }

    Rational test;

    std::cout << "\nAssign tests:\n";
    test = Rational(5, -3);
    std::cout << "test = Rational(5, -3): " << test << std::endl;
    test = Rational(-4, 2);
    std::cout << "test = Rational(-4, 2): " << test << std::endl;
    test = Rational(-12, -17);
    std::cout << "test = Rational(-12, -17): " << test << std::endl;


    std::cout << "\nReduce tests: " << std::endl;
    std::cout << "Rational(16, 24): " << Rational(16, 24) << std::endl;
    std::cout << "Rational(12, 63): " << Rational(12, 63) << std::endl;
    std::cout << "Rational(-16, 4): " << Rational(-16, 4) << std::endl;
    std::cout << "Rational(5): " << Rational(5) << std::endl;
    std::cout << "Rational(3, -5): " << Rational(3, -5) << std::endl;
    std::cout << "Rational(-16, -24): " << Rational(-16, -24) << std::endl;
    std::cout << "Rational(-28, 24): " << Rational(-28, 24) << std::endl;

    std::cout << "\nSum tests: " << std::endl;
    std::cout << "1/3 + 1/6 = "
              << Rational(3, 9) + Rational(5, 30) << std::endl;
    std::cout << "-2/3 + 1/6 = "
              << Rational(-6, 9) + Rational(1, 6) << std::endl;
    std::cout << "4/9 + (-1/4) = "
              << Rational(16, 36) + Rational(2, -8) << std::endl;
    std::cout << "1/2 + 1/2 = " << Rational(1, 2) + Rational(2, 4) << std::endl;
    std::cout << "1/2 + 0 = " << Rational(1, 2) + 0 << std::endl;
    std::cout << "1/2 + 5 = " << Rational(1, 2) + 5 << std::endl;

    std::cout << "\nDifference tests: " << std::endl;
    std::cout << "1/3 - 1/6 = "
              << Rational(3, 9) - Rational(5, 30) << std::endl;
    std::cout << "-2/3 - 1/6 = "
              << Rational(-6, 9) - Rational(1, 6) << std::endl;
    std::cout << "4/9 - (-1/4) = "
              << Rational(16, 36) - Rational(2, -8) << std::endl;
    std::cout << "1/2 - 1/2 = " << Rational(1, 2) - Rational(2, 4) << std::endl;
    std::cout << "1/2 - 0 = " << Rational(1, 2) - 0 << std::endl;
    std::cout << "1/2 - 5 = " << Rational(1, 2) - 5 << std::endl;

    std::cout << "\nMultiplication tests: " << std::endl;
    std::cout << "1/3 * 1/6 = "
              << Rational(3, 9) * Rational(5, 30) << std::endl;
    std::cout << "-2/3 * 1/6 = "
              << Rational(-6, 9) * Rational(1, 6) << std::endl;
    std::cout << "4/9 * (-1/4) = "
              << Rational(16, 36) * Rational(2, -8) << std::endl;
    std::cout << "1/2 * 1/2 = " << Rational(1, 2) * Rational(2, 4) << std::endl;
    std::cout << "1/2 * 0 = " << Rational(1, 2) * 0 << std::endl;
    std::cout << "1/2 * 5 = " << Rational(1, 2) * 5 << std::endl;

    std::cout << "\nDivision tests: " << std::endl;
    std::cout << "1/3 / 1/6 = "
              << Rational(3, 9) / Rational(5, 30) << std::endl;
    std::cout << "-2/3 / 1/6 = "
              << Rational(-6, 9) / Rational(1, 6) << std::endl;
    std::cout << "4/9 / (-1/4) = "
              << Rational(16, 36) / Rational(2, -8) << std::endl;
    std::cout << "1/2 / 1/2 = " << Rational(1, 2) / Rational(2, 4) << std::endl;
    std::cout << "1/2 / 5 = " << Rational(1, 2) / 5 << std::endl;

    std::cout << "1/2 / 0 = ";
    try {
        Rational(1/2) / 0;
    } catch(const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\nEqual tests: " << std::endl;
    std::cout << "1/3 == 1/6: "
              << (Rational(3, 9) == Rational(5, 30)) << std::endl;
    std::cout << "1/4 == -1/4: "
              << (Rational(16, 36) == Rational(2, -8)) << std::endl;
    std::cout << "1/2 == 1/2: "
              << (Rational(1, 2) == Rational(2, 4)) << std::endl;
    std::cout << "6/2 == 3: " << (Rational(6/2) == 3) << std::endl;
    std::cout << "1/3 != 1/6: "
              << (Rational(3, 9) != Rational(5, 30)) << std::endl;
    std::cout << "1/4 != -1/4: "
              << (Rational(16, 36) != Rational(2, -8)) << std::endl;
    std::cout << "1/2 != 1/2: "
              << (Rational(1, 2) != Rational(2, 4)) << std::endl;
    std::cout << "0/123 != 0: " << (Rational(0, 123) != 0) << std::endl;

    std::cout << "\nInput tests: "<< std::endl;
    std::istringstream ss("5/30 -1/3 0 3 4/-5 6/3 34t45/23sdf4 345/0");
    ss >> test;
    std::cout << "input: 5/30  --> " << test  << std::endl;
    ss >> test;
    std::cout << "input: -1/3  --> " << test  << std::endl;
    ss >> test;
    std::cout << "input: 0  --> " << test  << std::endl;
    ss >> test;
    std::cout << "input: 3  --> " << test  << std::endl;
    ss >> test;
    std::cout << "input: 4/-5  --> " << test  << std::endl;
    ss >> test;
    std::cout << "input: 6/3  --> " << test  << std::endl;

    std::cout << "input: 34t45/23sdf4  --> ";
    ss >> test;
    std::cout << "input: 345/0  --> ";
    ss >> test;

    std::cout << "\nOutput tests: " << std::endl;
    test = Rational(2, 3);
    std::cout << "Rational(2, 3): " << test << std::endl;
    test = Rational(3);
    std::cout << "Rational(3): " << test << std::endl;
    test = Rational(15, 3);
    std::cout << "Rational(15, 3): " << test << std::endl;
    test = Rational(6, -9);
    std::cout << "Rational(6, -9): " << test << std::endl;

    return 0;
}
