//
// Created by 田佳业 on 2023/8/17.
//
#include <iostream>

int main()
{
    // 定义一个 lambda 表达式
    auto fib = [](auto && fib, int n)  -> int {
        if(n <= 2) return 1;
        else return fib(fib, n - 1) + fib(fib, n - 2);
    };
    std::cout<<fib(fib,6);
}
