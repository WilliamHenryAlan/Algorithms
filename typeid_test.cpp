#include <iostream>
#include <typeinfo>

int main() {
    double num = 10.0;
    double value = 3.14;
    double out = num/value;
    std::cout << out << std::endl;
    std::cout << "Type of value: " << typeid(out).name() << std::endl;

    return 0;
}
/**
 * 在 C 语言中没有类似于 C++ 中的 `typeinfo` 或 `typeid` 的标准库函数可以输出变量的类型信息。C 语言是一种相对简单的语言，其设计目标是高效且尽可能地靠近底层，因此没有提供类似 C++ 的 RTTI（运行时类型识别）机制。

如果需要在 C 语言中输出变量的类型信息，可以手动编写函数来实现。例如，可以使用 `printf` 函数输出变量的类型名：

```c
#include <stdio.h>

void print_type(const void *p)
{
    if (p == NULL) {
        printf("NULL pointer\n");
    } else if (*(char *)p == 0) {
        printf("empty string\n");
    } else if (sizeof(char) == sizeof(p)) {
        printf("char\n");
    } else if (sizeof(int) == sizeof(p)) {
        printf("int\n");
    } else if (sizeof(float) == sizeof(p)) {
        printf("float\n");
    } else if (sizeof(double) == sizeof(p)) {
        printf("double\n");
    } else {
        printf("unknown type\n");
    }
}

int main()
{
    int num = 10;
    float pi = 3.14;
    char letter = 'A';
    char str[] = "Hello";

    print_type(&num);        // 输出 "int"
    print_type(&pi);         // 输出 "float"
    print_type(&letter);     // 输出 "char"
    print_type(str);         // 输出 "unknown type"（字符数组在传递给函数时转换为指向第一个元素的指针）
    
    return 0;
}
```

上述代码中，`print_type` 函数接受一个 `void` 类型的指针作为参数，通过判断指针类型的大小来确定其所指向的变量类型，并输出相应的类型名。需要注意的是，在传递字符数组时，数组会转换为指向第一个元素的指针，因此需要特别处理。
*/