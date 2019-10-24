#include <iostream>
#include <sstream>
#include <complex/complex.h>

int main() {

    std::cout << "Standart constructor Complex():" << Complex() << std::endl;
    std::cout << "From one Double constructor Complex(2,3): " << Complex(2.3) << std::endl;
    std::cout << "From two Double constructor Complex(9.45, 1.2): " << Complex(9.45, 1.2) << std::endl;

    Complex test1(3.4, 1.2), test2(3, 0.5);
    test1 = test2;
    std::cout << "Assign tests:\n test1(3.4, 1.2) and test2(3, 0.5);\n test1 = test2;\n print test1: "
                << test1 << std::endl;

    std::cout << "\nSum tests: " << std::endl;
    std::cout << "{3.4, 1.2} + {4.4, 0.3} = " << Complex(3.4, 1.2) + Complex(4.4, 0.3) << std::endl;
    std::cout << "{4, 9} + {-1, 0} = " << Complex(4, 9) + Complex(-1, 0) << std::endl;
    std::cout << "{2.1, 3} + 3 = " << Complex(2.1, 3) + 3 << std::endl;

    std::cout << "\nDifference tests: " << std::endl;
    std::cout << "{3.4, 1.2} - {4.4, 0.3} = " << Complex(3.4, 1.2) - Complex(4.4, 0.3) << std::endl;
    std::cout << "{4, 9} - {-1, 0} = " << Complex(4, 9) - Complex(-1, 0) << std::endl;
    std::cout << "{2.1, 3} - 3 = " << Complex(2.1, 3) - 3 << std::endl;

    std::cout << "\nMultiplication tests: " << std::endl;
    std::cout << "{3.4, 1.2} * {4.4, 0.3} = " << Complex(3.4, 1.2) * Complex(4.4, 0.3) << std::endl;
    std::cout << "{4, 9} * {-1, 0} = " << Complex(4, 9) * Complex(-1, 0) << std::endl;
    std::cout << "{2.1, 3} * 3 = " << Complex(2.1, 3) * 3 << std::endl;

    std::cout << "\nEqual tests: " << std::endl;
    std::cout << "{1, 3} == {1, 6}: " << (Complex(1, 3) == Complex(1, 6)) << std::endl;
    std::cout << "{1, 2} == {1, 2}: " << (Complex(1, 2) == Complex(1, 2)) << std::endl;

    std::cout << "\nInput tests: "<< std::endl;
    std::istringstream ss("{5,0.3} {-1,3} {0,0} {3.3, -1} {4.001, -5} {6.2, 0} {34t45/23sdf4");
    ss >> test1;
    std::cout << "input: {5,0.3}  --> " << test1 << std::endl;
    ss >> test1;
    std::cout << "input: {-1,3}  --> " << test1 << std::endl;
    ss >> test1;
    std::cout << "input: {3.3, -1}  --> " << test1 << std::endl;
    ss >> test1;
    std::cout << "input: {4.001, -5}  --> " << test1 << std::endl;

    std::cout << "input: {34t45/23sdf4  --> ";
    ss >> test1;
    if (!ss.good() || ss.failbit) {
        std::cout << "bad input" << std::endl;
    } else {
        std::cout << "???\n";
    }

    return 0;
}
