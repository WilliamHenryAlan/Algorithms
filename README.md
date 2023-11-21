# Data Structures and Algorithm

## Introduction
主要使用c++完成leetcode上的题目 包括基础数据结构 数组 链表 栈和队列


## Hash table
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