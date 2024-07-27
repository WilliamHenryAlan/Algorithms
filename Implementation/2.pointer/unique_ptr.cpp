#include <iostream>
#include <memory>

int main() {
    int a = 20;
    std::unique_ptr<int> ptr(&a);
    std::unique_ptr<int> ptr2(&a);
    return 0;
}
