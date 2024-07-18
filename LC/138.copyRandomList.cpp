/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> hash;//两个linkedlist对应存储
        //创建dummynode create用于创建新的list origin指向原list
        Node* dummy = new Node(-1);
        Node *origin = head,*create = dummy;
        while (origin != nullptr) {
            create->next = new Node(origin->val);
            hash[origin] = create->next;//两个linkedlist的node对应存储
            //两个链表的指针迭代
            create = create->next;
            origin = origin->next;
        }
        //reset两个链表的指针 再次遍历
        create = dummy->next;
        origin = head;
        while (origin != nullptr) {
            /*
            举例说明：
            list1->a->b
            list2->c->d
            hash表中kv对应为a:c,b:d
            */
            create->random = hash[origin->random];
            //两个链表的指针迭代
            create = create->next;
            origin = origin->next;
        }
        return dummy->next;
    }
};
