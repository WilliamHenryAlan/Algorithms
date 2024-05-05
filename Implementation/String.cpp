#include <iostream>
using namespace std;

class MyString {
private:
    int m_len;
    char * m_str;
public:
    MyString():m_len(0),m_str(nullptr) {};
    MyString(const char* str) {
        m_len = 0;
        const char* tmp = str;
        while (*tmp != '\0') {
            tmp++;
            m_len++;
        }
        m_str = new char[m_len + 1];
        char *traverse = m_str;
        while (*str != '\0') {
            *traverse++ = *str++;
        }
        *traverse = '\0';
    }

    void print() {
        const char* temp = m_str;
        while (*temp != '\0') {
            std::cout << *temp;
            temp++;
        }
        std::cout << std::endl;
    }
};

int main() {
    MyString str("helloworld");
    str.print();
    return 0;
}

