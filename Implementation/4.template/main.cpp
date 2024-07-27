#include <iostream>
#include <string>
#include "mytemplate.hpp"
using namespace std;

int main() {
    int a,b;
    cin >> a >> b;
    cout << my::max(a,b) << endl;
}