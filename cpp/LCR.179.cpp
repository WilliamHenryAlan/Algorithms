#include <iostream>
#include <vector>
using namespace std;
/*
这段代码的详细解释如下：

1. `static const auto io_sync_off = []() { ... }();`
   - 这行代码定义了一个静态常量 `io_sync_off`，并使用了一个匿名的 lambda 表达式来初始化它。Lambda 表达式被立即执行（因为在后面有 `()`），并且返回了 `nullptr`。

2. `[ ]() { ... }`
   - 这是一个 Lambda 表达式的开始，`[ ]` 表示捕获列表为空（即不捕获任何外部变量），`() { ... }` 是 Lambda 函数体。

3. `std::ios::sync_with_stdio(false);`
   - 这条语句关闭了 C++ 的输入流和输出流之间的同步，这样可以提高程序的性能。默认情况下，C++ 的输入流和输出流是同步的，关闭同步后可以避免在每次切换输入输出时都进行不必要的同步操作。

4. `std::cin.tie(nullptr);`
   - 这条语句将 `std::cin` 和 `std::cout` 解绑定，这样在读取输入时不会自动刷新输出缓冲区。通常情况下，当从标准输入流 `std::cin` 读取数据时，`std::cout` 的输出缓冲区会被自动刷新，但通过将其设置为 `nullptr`，可以禁用这种自动刷新，提高程序的性能。

总的来说，这段代码的作用是在程序开始时通过 Lambda 表达式立即执行一些操作，包括关闭输入输出流的同步以提高性能，并解绑定输入流和输出流以避免不必要的刷新操作。这样可以在程序运行时提高效率和性能。
*/
static const auto io_sync_off = []()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
    vector<int> twoSum(vector<int>& price, int target) {
        int l = 0;
        int r = price.size()-1;
        while (l < r) {
            int sum = price[l] + price[r];
            if (target == sum) {
                return {price[l],price[r]};
            }else if (target > sum) {
                l++;
            }else {
                r--;
            }
        }
        return {};
    }
};