#include <stdio.h>
int main() {
        char str[10];
        int num = 123;
        sprintf(str,"%d",num);  //c语言中的sprintf可以把整形转化为string
        printf("%s\n",str);
}
//C++
//stoi 
//to_string