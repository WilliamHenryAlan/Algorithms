#include <iostream>
using namespace std;

/*
请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
实现 LRUCache 类：
LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key-value 。
如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。

1.因为put()需要O(1) 所以选用linkedList 但是linkedList不符合get()为O(1) 所以选用set和LinkedList
2.get方法
        1.如果不存在 return -1
        2.如果存在 要把node从原位置删除 再添加到头部 return value
3.put方法 如果存在 先修改value 再从原位置删除 添加到头部
         如果不存在 插入到头部
*/
#include <set>
#include <list>
#include <unordered_map>
struct DLinkedNode {
    int _key,_value;
    DLinkedNode* _prev,* _next;
    DLinkedNode ():_key(0),_value(0),_prev(nullptr),_next(nullptr) {}
    DLinkedNode (int key,int value):_key(key),_value(value),_prev(nullptr),_next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int,DLinkedNode*> _cache;
    DLinkedNode* _head,*_tail;
    int _size;
    int _capacity;
public:
    LRUCache(int capacity):
         _head(new DLinkedNode()),
         _tail(new DLinkedNode()),
         _size(0),
         _capacity(capacity) {
        _head->_next = _tail;
        _tail->_prev = _head;
    }
    
    int get(int key) {
        auto iter = _cache.find(key);
        iter == _cache.end()?-1:iter->second->_value;
    }
    
    void put(int key, int value) {

    }
};

class LRUCache {
public:
    LRUCache(int capacity) {
        list<int> cache;
        
    }
    
    int get(int key) {

    }
    
    void put(int key, int value) {

    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */