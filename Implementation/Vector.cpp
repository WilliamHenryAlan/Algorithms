#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
struct Print {
    void operator() (int elem) const {
        std::cout << elem << " ";
    }
};
int main() {
    std::vector<int> arr {10,100,2,3};
    for (int i = 0;i <= arr.size();i++) {
        cout << &arr[i] << " ";
    }
    cout << endl;
    cout << "&*(arr.begin()) = " << &*(arr.begin()) << endl;
    cout << "&*arr.end() = " << &*(arr.end()) << endl;
    cout << "&*arr.rbegin() = " << &*arr.rbegin() << endl;
    cout << "&*arr.rend() = " << &*(arr.rend()) << endl;
    
    std::for_each(arr.rbegin(),arr.rend(),Print()); //函数对象+反向迭代器+for_each实现逆向遍历

    cout << endl;
}
