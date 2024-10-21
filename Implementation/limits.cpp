#include <iostream>
#include <limits>  // 包含 numeric_limits

int main() {
	int maxInteger = std::numeric_limits<int>::max();
    std::cout << "The maximum value for int is: " << maxInteger << std::endl;

    double maxDouble = std::numeric_limits<double>::max();
    std::cout << "The maximum value for double is: " << maxDouble << std::endl;
	
	double maxFloat = std::numeric_limits<float>::max();
    std::cout << "The maximum value for float is: " << maxFloat << std::endl;
    return 0;
}
