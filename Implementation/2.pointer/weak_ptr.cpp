#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass() { std::cout << "MyClass Constructor" << std::endl; }
    ~MyClass() { std::cout << "MyClass Destructor" << std::endl; }
    void display() { std::cout << "MyClass::display()" << std::endl; }
};

int main() {
    std::shared_ptr<MyClass> ptr1 = std::make_shared<MyClass>();
    std::weak_ptr<MyClass> weakPtr = ptr1;

    if (auto sharedPtr = weakPtr.lock()) {
        sharedPtr->display();
        std::cout << "Use count: " << sharedPtr.use_count() << std::endl;
    } else {
        std::cout << "Object has been destroyed." << std::endl;
    }

    // 释放ptr1，导致对象销毁
    ptr1.reset();

    if (auto sharedPtr = weakPtr.lock()) {
        sharedPtr->display();
    } else {
        std::cout << "Object has been destroyed." << std::endl;
    }

    return 0;
}
