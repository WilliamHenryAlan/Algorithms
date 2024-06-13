#pragma once
#include <iostream>
const int MAX_SIZE = 11;//stack max capacity

class stack {
private:
    int* m_data;
    int m_size; //stack.size()
    int m_top;
public:
    stack() : m_size(0),m_top(0) {m_data = new int[MAX_SIZE];} //constructor 1
    stack(int s,int val); //constructor 2
    ~stack();
    void push(int& val);
    void pop();
    int size()const {return this->m_size;}
    stack& operator=(const stack& other); //有pointer overload operation =
    stack(const stack& other); //有pointer copy constructor
    void print() const; //print stack data
    bool empty() const;
    //exception
    class underflow{};
    class overflow{};
    class isempty{};
};