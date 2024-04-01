/*
LRUCache
*/
#include <iostream>
#include <set>
#include <list>
#include <unordered_map>
using namespace std;

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