#include <iostream>
using namespace std;
//review 2024.6.7
//Double linked list node
struct Node {
    int m_key,m_value;  //kv真实存储在这里
    Node* m_prev,*m_next;
    Node(int k = 0,int v = 0) : //默认参数
        m_key(k),m_value(v),
        m_prev(nullptr),m_next(nullptr) {} 
};
//lru cache
class LRUCache {
private:
    //切记 cache只负责存储node的指针和保证O(1)的查找 不存储真实data 真实data存储在node中
    unordered_map<int,Node*> m_cache; 
    Node* m_tail,* m_head;            //头尾哨兵node 按照从头到尾 调用最多使用递减
    int m_capacity;                 //最大容量
    int m_size;                     //实际大小
public:
    LRUCache(int capacity) :
        m_capacity(capacity),
        m_tail(new Node()),m_head(new Node()),//建立哨兵node
        m_size(0) {
            m_tail->m_prev = m_head;
            m_head->m_next = m_tail;
    }
    int get(int key) {
        auto iter = m_cache.find(key);
        if (iter == m_cache.end()) {
            return -1;   //没找到 不用作修改 直接return -1
        }
        /*
        找到了之后要做两件事
        1.因为get调用后 当前iter指向的node为最新调用 应该插入到list的head
        2.返回value
        */
        removeNode(iter->second);
        addToHead(iter->second);
        return iter->second->m_value;
    }
    /*
    */
    void put(int key, int value) {
        auto iter = m_cache.find(key);
        //存在 1.变更value 2.插入头部
        if(iter != m_cache.end()) {
            iter->second->m_value =value;
            removeNode(iter->second);
            addToHead(iter->second);
            return ;
        }
        //不存在 进行插入 插入的时候 考虑size的问题
        Node* temp = new Node(key,value);
        m_cache[key] = temp;
        addToHead(temp);
        //如果不超出capacity 到这里就结束了
        if (++m_size > m_capacity) { //容量超出
            Node* release = m_tail->m_prev; //记录待删除node
            removeNode(release);    //移除但不delete
            m_cache.erase(release->m_key);  //把hashtable中对应的value先删除
            delete release; //再delete
            m_size--;   //恢复原来大小
        }
    }
    //双向链表头插法
    void addToHead(Node* x) {
        x->m_next = m_head->m_next;
        x->m_prev = m_head;
        m_head->m_next->m_prev = x;
        m_head->m_next = x;
    }
    //双向链表删除
    void removeNode(Node* x) {
        x->m_prev->m_next = x->m_next;
        x->m_next->m_prev = x->m_prev;
    }
};




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