#include <iostream>
#include <typeinfo>

int main() {
    double num = 10.0;
    double value = 3.14;
    double out = num/value;
    std::cout << out << std::endl;
    std::cout << "Type of value: " << typeid(out).name() << std::endl;

    return 0;
}
