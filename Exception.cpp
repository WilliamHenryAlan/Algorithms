#include <iostream>

int main() {
    try {
        // 可能会引发异常的代码
        int a = 10, b = 0;
        if (b == 0) {
            throw "除数不能为0";
        }
        int result = a / b;
        std::cout << "结果：" << result << std::endl;
    }
    catch (const char* msg) {
        std::cerr << "捕获到异常: " << msg << std::endl;
    }
    return 0;
}
