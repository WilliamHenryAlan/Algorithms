#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a = 10;
    int ret = [&](int x) ->int {
        return x + 10 + a; 
    } (1);
    cout << "ret = " << ret << endl;

    vector<int> arr {1,2,3,4,5};
    auto print = [&](int x) {
        cout << x << " ";
    };
    for_each(arr.begin(),arr.end(),[](int x) {
        cout << x << " ";
    });
    for_each(arr.begin(),arr.end(),print);
    cin.get();
}