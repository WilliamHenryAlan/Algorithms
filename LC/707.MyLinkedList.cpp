// 你可以选择使用单链表或者双链表，设计并实现自己的链表。

// 单链表中的节点应该具备两个属性：val 和 next 。val 是当前节点的值，next 是指向下一个节点的指针/引用。

// 如果是双向链表，则还需要属性 prev 以指示链表中的上一个节点。假设链表中的所有节点下标从 0 开始。

// 实现 MyLinkedList 类：

//     MyLinkedList() 初始化 MyLinkedList 对象。
//     int get(int index) 获取链表中下标为 index 的节点的值。如果下标无效，则返回 -1 。
//     void addAtHead(int val) 将一个值为 val 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。
//     void addAtTail(int val) 将一个值为 val 的节点追加到链表中作为链表的最后一个元素。
//     void addAtIndex(int index, int val) 将一个值为 val 的节点插入到链表中下标为 index 的节点之前。如果 index 等于链表的长度，那么该节点会被追加到链表的末尾。如果 index 比长度更大，该节点将 不会插入 到链表中。
//     void deleteAtIndex(int index) 如果下标有效，则删除链表中下标为 index 的节点。
#include <iostream>
class MyLinkedList {
private:
    struct LinkedNode
    {
        int val;
        LinkedNode* next;
        LinkedNode(int val=0):val(val),next(nullptr){}
    };
    LinkedNode* _dummyHead;
    int _size;

public:
    MyLinkedList() {
        _size=0;
        _dummyHead = new LinkedNode(-1);
    }
    
    int get(int index) {
        if (index < 0 or index > _size-1) return -1;
        LinkedNode* temp = _dummyHead->next;
        for (;index>0;index--,temp = temp->next){}
        return temp->val;
    }
    
    void addAtHead(int val) {
        LinkedNode* temp = new LinkedNode(val);
        temp->next = _dummyHead->next;
        _dummyHead->next = temp;
        _size++;
    }
    
    void addAtTail(int val) {
        LinkedNode* temp = new LinkedNode(val);
        LinkedNode* traversal = _dummyHead;
        while (traversal->next != nullptr)
        {
            traversal = traversal->next;
        }
        // for (int i = 0; i < _size-1; i++)
        // {
        //     traversal = traversal->next;
        // }
        traversal->next = temp;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 or index > _size) return;
        LinkedNode* traversal = _dummyHead;
        // while (traversal->next != nullptr)
        // {
        //     traversal = traversal->next;
        // }
        for (;index > 0;index--)
        {
            traversal = traversal->next;
        }
        LinkedNode* temp = new LinkedNode(val);
        temp->next = traversal->next;
        traversal->next = temp;
        _size++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 or index > _size-1) return;
        LinkedNode* traversal = _dummyHead;
        for (;index > 0;index--)
        {
            traversal = traversal->next;
        }
        LinkedNode* temp = traversal->next;
        traversal->next = temp->next;
        delete temp;
        _size--;
    }
    void print() const
    {
        LinkedNode* temp = _dummyHead->next;
        std::cout << "LinkedList is ";
        for (int i = 0;i < _size;i++)
        {
            std::cout << temp->val << " ";
        }
        std::cout << std::endl;
    }
};
int main()
{
    MyLinkedList *head = new MyLinkedList();
    head->addAtIndex(0,1);
    head->print();
    head->deleteAtIndex(0);
    head->print();
}
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
