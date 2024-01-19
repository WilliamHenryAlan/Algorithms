# Data Structures and Algorithm

## Introduction
主要使用c++完成leetcode上的题目 包括基础数据结构 数组 链表 栈和队列

---
## 1.Hash table
## 常见的三种哈希结构
---
- 数组
- set（集合）
- map（映射）

### set
c++的STL中，set分为std::unordered_set, std::set, std::multiset
|集合|底层实现|是否有序|数值是否可以重复|能否更改数值|查询效率|增删效率|
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|std::set|红黑树|有序|不可重复|不可更改|O(logn)|O(logn)|
|std::multiset|红黑树|有序|可重复|不可更改|O(logn)|O(logn)|
|std::unordered_set|哈希表|无序|不可重复|不可更改|O(1)|O(1)|

std::unordered_set底层实现为哈希表，std::set和std::multiset为红黑树，是一种平衡二叉树，所以key是有序的，不可修改，只能删除和增加

### map
|映射|底层实现|是否有序|数值是否可以重复|能否更改数值|查询效率|增删效率|
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|std::map|红黑树|有序|不可重复|不可更改|O(logn)|O(logn)|
|std::multimap|红黑树|有序|可重复|不可更改|O(logn)|O(logn)|
|std::unordered_map|哈希表|无序|不可重复|不可更改|O(1)|O(1)|

std::unordered_map 底层实现为哈希表，std::map 和std::multimap 的底层实现是红黑树。同理，std::map 和std::multimap 的key也是有序的

当我们要使用集合来解决哈希问题的时候，优先使用unordered_set，因为它的查询和增删效率是最优的，如果需要集合是有序的，那么就用set，如果要求不仅有序还要有重复数据的话，那么就用multiset。

那么再来看一下map ，在map 是一个key value 的数据结构，map中，对key是有限制，对value没有限制的，因为key的存储方式使用红黑树实现的。

虽然std::set、std::multiset 的底层实现是红黑树，不是哈希表，std::set、std::multiset 使用红黑树来索引和存储，不过给我们的使用方式，还是哈希法的使用方式，即key和value。所以使用这些数据结构来解决映射问题的方法，我们依然称之为哈希法。 map也是一样的道理。

unordered_set在C++11的时候被引入标准库了，而hash_set并没有，所以建议还是使用unordered_set比较好，这就好比一个是官方认证的，hash_set，hash_map 是C++11标准之前民间高手自发造的轮子。

---
## Stack and Queue
stack和queue归为container adapter（容器适配器）
C++标准库是有多个版本的，有三个个最为普遍的STL版本  

1. HP STL 其他版本的C++ STL，一般是以HP STL为蓝本实现出来的，HP STL是C++ STL的第一个实现版本，而且开放源代码
2. P.J.Plauger STL 由P.J.Plauger参照HP STL实现出来的，被Visual C++编译器所采用，不是开源的。
3. SGI STL 由Silicon Graphics Computer Systems公司参照HP STL实现，被Linux的C++编译器GCC所采用，SGI STL是开源软件，源码可读性甚高。

如果没有指定底层实现 一般是用双端队列dequeue 开通一端可实现stack

### 优先队列

---
## 二叉树
![二叉树结构框图](https://code-thinking-1253855093.file.myqcloud.com/pics/20210219190809451.png)

二叉树的两种主要形式：满二叉树和完全二叉树

#### 满二叉树：
如果一棵二叉树只有**度为0的结点和度为2的结点**，并且度为0的结点在同一层上，则这棵二叉树为满二叉树。
#### 完全二叉树的定义如下：
在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层（h从1开始），则该层包含 1~ 2^(h-1) 个节点。
![满二叉树](https://code-thinking-1253855093.file.myqcloud.com/pics/20200920221638903.png)

上节的优先队列就是堆 堆就是满二叉树 [跳转到优先队列](#优先队列)

#### 二叉搜索树
前面介绍的树，都没有数值的，而二叉搜索树是有数值的了，二叉搜索树是一个有序树。
    若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值；
    若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值；
    它的左、右子树也分别为二叉排序树
![binary search tree](https://code-thinking-1253855093.file.myqcloud.com/pics/20200806190304693.png)
上面这两棵树都是搜索树

#### 平衡二叉搜索树

平衡二叉搜索树：又被称为AVL（Adelson-Velsky and Landis）树，且具有以下性质：它是一棵空树或它的左右两个子树的高度差的绝对值不超过1，并且左右两个子树都是一棵平衡二叉树。

![balanced binary search tree](https://code-thinking-1253855093.file.myqcloud.com/pics/20200806190511967.png)

最后一棵 不是平衡二叉树，因为它的左右两个子树的高度差的绝对值超过了1。

C++中map、set、multimap，multiset的底层实现都是平衡二叉搜索树，所以map、set的增删操作时间时间复杂度是O(logn)，unordered_map、unordered_set，unordered_map、unordered_set底层实现是哈希表。

---
####二叉树的遍历
1. preorder
2. inorder
3. postorder
4. levelorder




