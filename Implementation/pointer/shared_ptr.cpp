#include <iostream>
#include <memory>
class Myclass {
    int x,y;
public:
    Myclass() {std::cout << "constructor" << std::endl;}
    ~Myclass() {std::cout << "destructor" << std::endl;}
    void print() const{std::cout << "print" << std::endl;}
};
int main() {
    std::shared_ptr<Myclass> ptr(new Myclass());
}

void function(std::shared_ptr<MyClass> ptr) {
    std::cout << "In function: ";
    ptr->display();
}

int main() {
    // 创建一个std::shared_ptr
    std::shared_ptr<MyClass> ptr1 = std::make_shared<MyClass>();
    ptr1->display();

    // 传递std::shared_ptr
    function(ptr1);

    std::cout << "Use count: " << ptr1.use_count() << std::endl;

    // 离开作用域时，ptr1会自动销毁对象
    return 0;
}
