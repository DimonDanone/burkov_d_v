#include <iostream>
#include "rational.h"
#include "test_runner.h"

void TestReduce() {
    Rational a(16, 24);
    Rational b(12, 63);
    ASSERT_EQUAL(a, Rational(2, 3))
    ASSERT_EQUAL(b, Rational(4,  21))

    a = -4;
    b = Rational(-5, -25);
    ASSERT_EQUAL(a, Rational(-16, 4))
    ASSERT_EQUAL(b, Rational(1, 5))
    ASSERT_EQUAL(Rational(0), 0)
    ASSERT_EQUAL(0, Rational(0))
    ASSERT_EQUAL(-4, Rational(28, -7))

    ASSERT(Rational(3, -5) == Rational(15, -25))
    ASSERT(Rational(-3, -5) == Rational(-15, -25))
    ASSERT(Rational(-3, 5) == Rational(-15, 25))
    ASSERT(Rational(3, -5) == Rational(-15, 25))
    ASSERT(Rational(-3, 5) == Rational(15, -25))

    ASSERT(Rational(12, -3) == Rational(64, -16))
    ASSERT(Rational(-12, -3) == Rational(-64, -16))
    ASSERT(Rational(-12, 3) == Rational(-64, 16))
    ASSERT(Rational(12, -3) == Rational(-64, 16))
    ASSERT(Rational(-12, 3) == Rational(64, -16))
}

void TestOperations() {
    Rational a(3, 9);
    Rational b(5, 30);

    ASSERT_EQUAL(a + b, Rational(1, 2))
    ASSERT_EQUAL(a - b, Rational(1, 6))
    ASSERT_EQUAL(b - a, Rational(-1, 6))
    ASSERT_EQUAL(3 - a, Rational(8, 3))
    ASSERT_EQUAL(a * b, Rational(1, 18))
    ASSERT_EQUAL(a / b, 2)
    ASSERT_EQUAL(a * 0, 0)

    a = 8;
    b = 3;
    ASSERT_EQUAL(a + b, 11)
    ASSERT_EQUAL(a + b, Rational(11))

    a = Rational(8, 3);
    b = Rational(5, 8);

    ASSERT_EQUAL(a * b, Rational(5, 3))
    ASSERT_EQUAL(a * Rational(3, 5) * b, 1)

}


int main() {
    TestRunner tester;

    RUN_TEST(tester, TestOperations);
    RUN_TEST(tester, TestReduce);

    Rational a, b;

    std::cin >> a >> b;

    std::cout << a << " " << b << endl;

    return 0;
}
