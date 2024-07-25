
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

#include <iostream>

// 递归实现
int gcd1(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// 迭代实现
int gcd2(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a = 56, b = 98;
    std::cout << "GCD of " << a << " and " << b << " is " << gcd1(a, b) << std::endl;
    std::cout << "GCD of " << a << " and " << b << " is " << std::gcd(a, b) << std::endl;
    return 0;
}
