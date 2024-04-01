#include <iostream>
#include <vector>
using std::cout;
using std::endl;

int main() {
    std::vector<int> arr{10,100,2,3};
    for (int i = 0;i <= arr.size();i++) {
        cout << &arr[i] << " ";
    }
    cout << endl;
    cout << "&*(arr.begin()) = " << &*(arr.begin()) << endl;
    cout << "&*arr.end() = " << &*(arr.end()) << endl;
    cout << "&*arr.rbegin() = " << &*arr.rbegin() << endl;
    cout << "&*arr.rend() = " << &*(arr.rend()) << endl;
}