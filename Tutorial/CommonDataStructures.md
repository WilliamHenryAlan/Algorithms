## 1.LinkedList
-   #707 - ****[设计链表](https://leetcode.cn/problems/design-linked-list/)****
-   #142 - ****[环形链表 II](https://leetcode.cn/problems/linked-list-cycle-ii/)****
-   #160 - ****[相交链表](https://leetcode.cn/problems/intersection-of-two-linked-lists/)****
-   #203 - ****[移除链表元素](https://leetcode.cn/problems/remove-linked-list-elements/)****
-   #328 - ****[奇偶链表](https://leetcode.cn/problems/odd-even-linked-list/)****
-   #234 - ****[回文链表](https://leetcode.cn/problems/palindrome-linked-list/)****
-   #2 - ****[两数相加](https://leetcode.cn/problems/add-two-numbers/)****
-   #430 - ****[扁平化多级双向链表](https://leetcode.cn/problems/flatten-a-multilevel-doubly-linked-list/)****
-   #138 - ****[复制带随机指针的链表](https://leetcode.cn/problems/copy-list-with-random-pointer/)****
-   #61 - ****[旋转链表](https://leetcode.cn/problems/rotate-list/)****

## 2.双指针
>

## Monotone Stack（单调栈）
> 单调栈适合处理**下一个更大元素类的问题**

代码模版(Golang)
```
stack := make([]int, 0)
for i, v := range arr {
    // 当前元素比栈顶大，视为找到下一个更大元素，就弹出栈顶，更新结果
    for len(stack) > 0 && v > arr[stack[len(stack)-1]] {
        topIndex := stack[len(stack)-1]
        stack = stack[:len(stack)-1]
        // 更新结果
    }
    // 当前元素比栈顶小，直接把下标入栈
    stack = append(stack, i)
}
```
