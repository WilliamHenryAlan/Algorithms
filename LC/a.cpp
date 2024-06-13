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

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */