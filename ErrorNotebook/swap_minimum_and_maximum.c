//c语言实现 输入正整数n 再输入n个数 找出最大值最小值index 再swap min and arr[0] swap max arr[n-1]

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
int is_prime(int n) {
    if (n <= 1) return 0;
    if (n == 2) return 2;
    if (n % 2 == 0) return 0;
    int x = sqrt(n);
    for (int i = 3;i <= x;i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}
void swap(int* arr,int len,int maxIdx,int minIdx) {
    int temp = arr[0];
    arr[0] = arr[minIdx];
    arr[minIdx] = temp;
    if (maxIdx == 0) maxIdx = minIdx;
    temp = arr[len - 1];
    arr[len - 1] = arr[maxIdx];
    arr[maxIdx] = temp;
}
int main() {
    int arr[10];
    int n;
    scanf("%d",&n);
    for (int i = 0;i < n;i++) scanf("%d",&arr[i]);
    int maxIdx = 0,minIdx = 0;
    for (int i = 1;i < n;i++) {
        if (arr[maxIdx] < arr[i]) maxIdx = i;
        if (arr[minIdx] > arr[i]) minIdx = i;
    }
    printf("max = %d,index = %d\n",arr[maxIdx],maxIdx);
    swap(arr,n,maxIdx,minIdx);
    for (int i = 0;i < n;i++) {
        printf("%d ",arr[i]);
    }
}

