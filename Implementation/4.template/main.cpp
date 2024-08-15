#include "mytemplate.hpp"
using namespace std;

int main() {
    cout << "Please enter two numbers" << endl;
    int a,b;
    cin >> a >> b;
    cout << my::max(a,b) << endl;
}