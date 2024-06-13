#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    std::cin >> n;
    while (n--) {
        string str;
        cin >> str;
        if (str.size() > 10) {
            cout << str.substr(0,1) + to_string(str.size() - 2) + str.substr(str.size() - 1,1) << endl;
        }else {
            cout << str << endl;
        }
    }
}
