//
// Created by 田佳业 on 2023/8/16.
//
#include <iostream>

int main() {
    int x = 10;

    // Lambda函数使用mutable关键字，允许修改捕获的变量x，如果修改以引用方式捕获的变量，不用加mutable关键字
    auto lambda = [x]() mutable -> int{
        x += 5;  // 修改捕获的变量x，不会影响外部的x
        return x;
    };
    //这是为甚么呢，因为值捕获捕获的变量本质上是匿名函数对象的一个数据成员，而不是一个普通的变量，所以修改它不会影响外部的值。

    int result1 = lambda();  // 调用Lambda函数，修改了捕获的x的副本
    int result2 = lambda();  // 再次调用Lambda函数，修改了新的捕获副本

    std::cout << "Result 1: " << result1 << std::endl;  // 输出：15
    std::cout << "Result 2: " << result2 << std::endl;  // 输出：20

    std::cout << "Outer x: " << x << std::endl;  // 输出：10，外部x的值未受影响

    return 0;
}
