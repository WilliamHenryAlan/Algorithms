#include <iostream>
using namespace std;
/*
(c - '0')的这个括号不能省略，否则可能造成整型溢出。
因为变量c是一个 ASCII 码，如果不加括号就会先加后减，想象一下s如果接近 INT_MAX，就会溢出。所以用括号保证先减后加才行。
*/
int my_stoi(string& str) {
        int ret = 0;
        for (char c:str) {
                ret = ret*10+(c-'0');
        }
        return ret;
}
int main() {
        // char str[10];
        // int num = 123;
        // sprintf(str,"%d",num);  //c语言中的sprintf可以把整形转化为string
        // printf("%s\n",str);
        //cout << (int)('0') << endl;   '0'的ASCII为48

        string str = "489";
        cout << my_stoi(str) << endl;
        cout << isdigit('0') << endl;
}
//C++
//stoi 
//to_string