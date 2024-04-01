#include <iostream>
int main() {
    int input;
    scanf("%d",&input);
    int ret = 0;
    while (input > 0) {
       input -= 5;
       ret++;
    }
    printf("%d",ret);
}
