/*
LRU（Least Recently Used，最近最少使用）是一种常用的缓存替换策略，用于在缓存已满时选择要淘汰的缓存项。它的核心思想是淘汰最久没有被使用过的缓存项，以便为新的数据腾出空间。LRU在操作系统的虚拟内存管理、数据库缓冲区管理、网页缓存等领域有广泛应用。

### 1. **LRU的基本原理**

- **目标**：在缓存容量有限的情况下，最大化缓存的命中率。
- **策略**：每次访问缓存时，更新该项的最近使用时间。当需要淘汰缓存项时，选择最近最少使用的项（即使用时间最久的项）进行淘汰。

### 2. **LRU实现方法**

LRU可以通过多种方法实现，其中两种常见的方法是基于链表和基于哈希表的双向链表。

#### **链表实现**

使用双向链表来维护缓存项的访问顺序。

- **操作**：
  - **访问**：将访问的项移到链表头部。
  - **插入**：将新项插入到链表头部。
  - **淘汰**：从链表尾部移除最久未使用的项。

- **时间复杂度**：
  - 访问、插入、淘汰操作的时间复杂度均为O(1)。
#### **哈希表加双向链表实现**

使用哈希表和双向链表的组合来提高访问和更新效率。

- **哈希表**：用于快速定位缓存项。
- **双向链表**：用于维护缓存项的访问顺序。

- **操作**：
  - **访问**：在哈希表中找到节点后，将其移动到链表头部。
  - **插入**：在哈希表中添加新项，同时将其插入到链表头部。
  - **淘汰**：从链表尾部移除最久未使用的项，并在哈希表中删除该项。

- **时间复杂度**：
  - 访问、插入、淘汰操作的时间复杂度均为O(1)。

### 3. **LRU的应用**

#### **操作系统**

在操作系统的内存管理中，LRU策略用于管理虚拟内存页面的调度。当物理内存满时，系统会使用LRU策略淘汰最久未使用的页面，确保物理内存中存放的是最有可能被再次访问的页面。

#### **数据库**

数据库系统使用LRU策略管理缓冲区（buffer pool），优化数据块的缓存，提高数据访问速度。

#### **网页缓存**

浏览器和代理服务器使用LRU策略管理缓存的网页和资源，以提升网页加载速度和用户体验。

### 4. **LRU的优缺点**

#### **优点**

- **简单有效**：LRU策略相对简单且容易实现，能够有效提升缓存命中率。
- **自适应性强**：能够适应各种访问模式，自动调整缓存内容。

#### **缺点**

- **开销较大**：在某些实现中，维护访问顺序可能需要较高的时间和空间开销。
- **局限性**：在某些特定的访问模式下，LRU可能不如其他替换策略（如LFU，Least Frequently Used）有效。

### 5. **其他替换策略对比**

- **FIFO（First In First Out）**：淘汰最早进入缓存的项，不考虑使用频率和最近使用时间。
- **LFU（Least Frequently Used）**：淘汰使用频率最低的项，适用于访问频率较固定的场景。

LRU（Least Recently Used）是一种常用的缓存替换策略，通过淘汰最久未使用的缓存项，来优化缓存命中率。
其实现方式多样，包括链表和哈希表结合的方式。
LRU在操作系统、数据库和网页缓存中有广泛应用，虽然在某些情况下存在开销和局限性，但其简单有效的特性使其成为一种广泛使用的缓存替换策略。
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