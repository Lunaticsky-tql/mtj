//
// Created by 田佳业 on 2023/8/21.
//
#include <iostream>
template<unsigned n>            // Factorial<n> = n * Factorial<n-1>
struct Factorial {
    enum { value = n * Factorial<n-1>::value };
};

template<>
struct Factorial<0> {           // 处理特殊情况：Factorial<0> = 1
    enum { value = 1 };
};
int main(){
    std::cout<<Factorial<5>::value;
}

