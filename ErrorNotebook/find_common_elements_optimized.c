#include <stdio.h>


void findCommonElementsOptimized(int* arr1, int n1, int* arr2, int n2) {
    int hash[MAX] = {0};

    // 将 arr1 中的元素存入哈希表
    for (int i = 0; i < n1; i++) {
        hash[arr1[i]] = 1;
    }

    // 遍历 arr2，检查是否在哈希表中
    printf("Common elements are: ");
    for (int i = 0; i < n2; i++) {
        if (hash[arr2[i]]) {
            printf("%d ", arr2[i]);
            hash[arr2[i]] = 0; // 防止重复输出
        }
    }
    printf("\n");
}

int main() {
    int arr1[100], arr2[100];
    int n1, n2;

    // 输入第一个数组
    printf("Enter the number of elements in the first array: ");
    scanf("%d", &n1);
    printf("Enter the elements of the first array: ");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    // 输入第二个数组
    printf("Enter the number of elements in the second array: ");
    scanf("%d", &n2);
    printf("Enter the elements of the second array: ");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    // 查找共有元素
    findCommonElementsOptimized(arr1, n1, arr2, n2);
   differenceSet (arr1, n1, arr2, n2);
   differenceSet (arr2, n1, arr1, n2);
	

    return 0;
}

