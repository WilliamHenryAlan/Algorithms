#include "stack.hpp"

stack::stack(int s, int val) {
    if (s > MAX_SIZE) {
        std::cerr << "overflow" << std::endl;
        return;
    }
    m_data = new int[MAX_SIZE];
    std::fill(m_data,m_data + s,val);
    m_size = s;
    m_top = s;
}

stack::~stack() {
    delete [] m_data;
}

void stack::push(int &val){
    if (m_size >= MAX_SIZE) {
        throw overflow();
    }
    m_data[m_top++] = val;
    m_size++;
}
bool stack::empty() const {
    if (m_size <= 0) return true;
    return false;
}
void stack::pop() {

    if (this->empty()) {
        throw underflow();
    }
    m_top--;
    m_size--;
}

stack::stack(const stack & other) :m_size(other.m_size), m_top(other.m_size){
    if (other.m_size > 0) {
        m_data = new int[MAX_SIZE];
        memcpy(m_data,other.m_data,m_size * sizeof(int));
    }else {
        this->m_data = nullptr;
    }
}

void stack::print() const {
    if (this->empty()) {
        throw isempty();
    }
    std::cout << std::endl;
    std::cout << "index    data   " << std::endl;
    for (size_t i = 0;i < m_size;i++) {
        std::cout << "  " << i << "      " << m_data[i] << std::endl;
    }
    std::cout << std::endl;
}
