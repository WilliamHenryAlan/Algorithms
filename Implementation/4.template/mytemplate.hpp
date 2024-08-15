#pragma once
#include <iostream>
#include <string>
namespace my {
template<typename T>
    T max(T& a,T& b) {
        return a > b ? a : b;
    }
}
