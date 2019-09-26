#include <iostream>
#include <sstream>
#include "complex.h"

int main() {

    std::cout << "Standart constructor: " << Complex() << std::endl;
    std::cout << "From one Double constructor: " << Complex(2.3) << std::endl;
    std::cout << "From two Double constructor: " << Complex(9.45, 1.2) << std::endl;

    try {
        Complex(123, 0);
    } catch (std::invalid_argument& ex) {
        std::cout << ex.what() << std::endl;
    }

    std::cout << "\nReduce tests: " << std::endl;
    std::cout << "Complex(16.45, 24.12): " << Complex(16.45, 24.12) << std::endl;
    std::cout << "Complex(12, 63.3): " << Complex(12, 63.3) << std::endl;
    std::cout << "Complex(-16.12, 4.1): " << Complex(-16.12, 4.1) << std::endl;
    std::cout << "Complex(5.43): " << Complex(5.43) << std::endl;
    std::cout << "Complex(3.32, -5.12): " << Complex(3.32, -5.12) << std::endl;
    std::cout << "Complex(-16.34, -24.535): " << Complex(-16.34, -24.535) << std::endl;
    std::cout << "Complex(-28.004, 24.676): " << Complex(-28.004, 24.676) << std::endl;

    std::cout << "\nSum tests: " << std::endl;
    std::cout << "{3.4, 1.2} + {4.4, 0.3} = " << Complex(3.4, 1.2) + Complex(4.4, 0.3) << std::endl;
    std::cout << "{-2.3, 1} + {1.01, 2} = " << Complex(-2.3, 1) + Complex(1.01, 2) << std::endl;
    std::cout << "{4, 9} + {-1, 0} = " << Complex(4, 9) + Complex(-1, 0) << std::endl;
    std::cout << "{1, 2} + {1, 2} = " << Complex(1, 2) + Complex(1, 2) << std::endl;

    std::cout << "\nDifference tests: " << std::endl;
    std::cout << "{3.4, 1.2} - {4.4, 0.3} = " << Complex(3.4, 1.2) - Complex(4.4, 0.3) << std::endl;
    std::cout << "{-2.3, 1} - {1.01, 2} = " << Complex(-2.3, 1) - Complex(1.01, 2) << std::endl;
    std::cout << "{4, 9} - {-1, 0} = " << Complex(4, 9) - Complex(-1, 0) << std::endl;
    std::cout << "{1, 2} - {1, 2} = " << Complex(1, 2) - Complex(1, 2) << std::endl;

    std::cout << "\nMultiplication tests: " << std::endl;
    std::cout << "{3.4, 1.2} * {4.4, 0.3} = " << Complex(3.4, 1.2) * Complex(4.4, 0.3) << std::endl;
    std::cout << "{-2.3, 1} * {1.01, 2} = " << Complex(-2.3, 1) * Complex(1.01, 2) << std::endl;
    std::cout << "{4, 9} * {-1, 0} = " << Complex(4, 9) * Complex(-1, 0) << std::endl;
    std::cout << "{1, 2} * {1, 2} = " << Complex(1, 2) * Complex(1, 2) << std::endl;
    std::cout << "{1, 0} * {0, 2} = " << Complex(1, 0) * Complex(0, 2) << std::endl;

    std::cout << "\nEqual tests: " << std::endl;
    std::cout << "{1, 3} == {1, 6}: " << (Complex(1, 3) == Complex(1, 6)) << std::endl;
    std::cout << "{1, 4} == {1, -4}: " << (Complex(1, 4) == Complex(1, -4)) << std::endl;
    std::cout << "{1, 2} == {1, 2}: " << (Complex(1, 2) == Complex(1, 2)) << std::endl;
    std::cout << "{0, 0} != {0, 0}: " << (Complex(1, 3) != Complex(1, 3)) << std::endl;
    std::cout << "{1, 4} != {-1, 4}: " << (Complex(1, 4) != Complex(-1, 4)) << std::endl;
    std::cout << "{1, 2} != {1, 2}: " << (Complex(1, 2) != Complex(1, 2)) << std::endl;

    Complex test;

    std::cout << "\nInput tests: "<< std::endl;
    std::istringstream ss("{5,0.3} {-1,3} {0,0} {3.3, -1} {4.001, -5} {6.2, 0} {34t45/23sdf4");
    ss >> test;
    std::cout << "input: {5,0.3}  --> " << test  << std::endl;
    ss >> test;
    std::cout << "input: {-1,3}  --> " << test  << std::endl;
    ss >> test;
    std::cout << "input: {0,0}  --> " << test  << std::endl;
    ss >> test;
    std::cout << "input: {3.3, -1}  --> " << test  << std::endl;
    ss >> test;
    std::cout << "input: {4.001, -5}  --> " << test  << std::endl;
    ss >> test;
    std::cout << "input: {6.2, 0}  --> " << test  << std::endl;

    std::cout << "input: {34t45/23sdf4  --> ";
    ss >> test;
    if (ss.fail()) {
        std::cout << "bad input" << std::endl;
    }

    std::cout << "\nOutput tests: " << std::endl;
    test = Complex(2.5, -3);
    std::cout << "Complex(2.5, -3): " << test << std::endl;
    test = Complex(3);
    std::cout << "Complex(3): " << test << std::endl;
    test = Complex(0.1, -2.1);
    std::cout << "Complex(0.1, -2.1): " << test << std::endl;
    test = Complex(6, -9);
    std::cout << "Complex(6, -9): " << test << std::endl;


    return 0;
}
