#include <iostream>
using namespace std;
struct DNode {
    DNode* prev,* next;
    int data;
    DNode():data(0),prev(nullptr),next(nullptr) {}
    DNode(int val,DNode* p,DNode* n):data(val),prev(p),next(n) {}
};
struct Node {
    Node* next;
    int data;
    Node():data(0),next(nullptr) {}
    Node(int val):data(val),next(nullptr) {}
    Node(int val,Node* x):data(val),next(x) {}
};
class DLinkedList {
    DNode* dummy;
public:
    DLinkedList():dummy(new DNode()) {}
    ~DLinkedList() {
        while (dummy) {
            DNode* release = dummy;
            dummy = dummy->next;
            delete release;
        }
    }
};

class LinkedList {
    Node* dummy;
public:
    LinkedList():dummy(new Node(-1)) {}
    ~LinkedList() {
        while (dummy) {
            Node* release = dummy;
            dummy = dummy->next;
            delete release;
        }
    }
};
int main() {
    DLinkedList L1;
    LinkedList L2;
}