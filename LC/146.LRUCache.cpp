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
3.put方法 
        1.如果存在 先修改value 再从原位置删除 添加到头部
        2.如果不存在 插入到头部 判断是否超容量 如果超过了 删除tail元素
tips:
1.很多细节要注意 释放内存要注意时机 不能直接在removeNode函数中
2.注意删除链表中Node 还要删除对应hashtable中的kv
*/
#include <set>
#include <list>
#include <unordered_map>


struct DLinkedNode {
    int _key, _value;
    DLinkedNode* _prev, * _next;
    DLinkedNode() : _key(0), _value(0), _prev(nullptr), _next(nullptr) {}
    DLinkedNode(int key, int value) : _key(key), _value(value), _prev(nullptr), _next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int,DLinkedNode*> _cache;
    DLinkedNode* _head,*_tail;
    int _size;
    int _capacity;
public:
    LRUCache(int capacity):
        _size(0),
        _capacity(capacity),
        _head(new DLinkedNode()),
        _tail(new DLinkedNode()) {
        _head->_next = _tail;
        _tail->_prev = _head;
    }
    
    int get(int key) {
        //不存在
        auto iter = _cache.find(key);
        if (iter == _cache.end()) return -1;
        //存在
        removeNode(iter->second);
        addToHead(iter->second);
        return iter->second->_value;
    }
    
    void put(int key, int value) {
        //找到了key
        auto iter = _cache.find(key);
        if (iter != _cache.end()) {
            iter->second->_value = value;
            removeNode(iter->second);
            addToHead(iter->second);
            return ;
        }
        //没找到key insert
        DLinkedNode* temp = new DLinkedNode(key,value);
        //插入hashtable
        _cache[key] = temp;
        addToHead(temp);
        if (++_size > _capacity) {
            DLinkedNode* removed = _tail->_prev;
            removeNode(removed);
            _cache.erase(removed->_key);
            delete removed;
            _size--;
        }
    }

    void removeNode(DLinkedNode* cur) {
        cur->_prev->_next = cur->_next;
        cur->_next->_prev = cur->_prev;
    }

    void addToHead(DLinkedNode* cur) {
        cur->_next = _head->_next;  
        cur->_prev = _head;
        _head->_next->_prev = cur;
        _head->_next = cur;
    }
};



/**template
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// struct DLinkedNode {
//     int key, value;
//     DLinkedNode* prev;
//     DLinkedNode* next;
//     DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
//     DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
// };

// class LRUCache {
// private:
//     unordered_map<int, DLinkedNode*> cache;
//     DLinkedNode* head;
//     DLinkedNode* tail;
//     int size;
//     int capacity;

// public:
//     LRUCache(int _capacity): capacity(_capacity), size(0) {
//         // 使用伪头部和伪尾部节点
//         head = new DLinkedNode();
//         tail = new DLinkedNode();
//         head->next = tail;
//         tail->prev = head;
//     }
    
//     int get(int key) {
//         if (!cache.count(key)) {
//             return -1;
//         }
//         // 如果 key 存在，先通过哈希表定位，再移到头部
//         DLinkedNode* node = cache[key];
//         moveToHead(node);
//         return node->value;
//     }
    
//     void put(int key, int value) {
//         if (!cache.count(key)) {
//             // 如果 key 不存在，创建一个新的节点
//             DLinkedNode* node = new DLinkedNode(key, value);
//             // 添加进哈希表
//             cache[key] = node;
//             // 添加至双向链表的头部
//             addToHead(node);
//             ++size;
//             if (size > capacity) {
//                 // 如果超出容量，删除双向链表的尾部节点
//                 DLinkedNode* removed = removeTail();
//                 // 删除哈希表中对应的项
//                 cache.erase(removed->key);
//                 // 防止内存泄漏
//                 delete removed;
//                 --size;
//             }
//         }
//         else {
//             // 如果 key 存在，先通过哈希表定位，再修改 value，并移到头部
//             DLinkedNode* node = cache[key];
//             node->value = value;
//             moveToHead(node);
//         }
//     }

//     void addToHead(DLinkedNode* node) {
//         node->prev = head;
//         node->next = head->next;
//         head->next->prev = node;
//         head->next = node;
//     }
    
//     void removeNode(DLinkedNode* node) {
//         node->prev->next = node->next;
//         node->next->prev = node->prev;
//     }

//     void moveToHead(DLinkedNode* node) {
//         removeNode(node);
//         addToHead(node);
//     }

//     DLinkedNode* removeTail() {
//         DLinkedNode* node = tail->prev;
//         removeNode(node);
//         return node;
//     }
// };