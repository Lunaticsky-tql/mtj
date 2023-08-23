//
// Created by 田佳业 on 2023/8/16.
//
#include <iostream>
#include <array>
using namespace std;

constexpr int sqr1(int arg){
    return arg*arg;
}
//const 用于为修饰的变量添加“只读”属性；而 constexpr 关键字则用于指明其后是一个常量（或者常量表达式）
//编译器在编译程序时可以顺带将其结果计算出来，而无需等到程序运行阶段，这样的优化极大地提高了程序的执行效率。

const int sqr2(int arg){
    return arg*arg;
}

int main()
{
    array<int,sqr1(10)> mylist1{};//可以，因为sqr1时constexpr函数
    array<int,sqr1(20)> mylist2{};//可以，因为sqr2时constexpr函数
//    array<int,sqr2(10)> mylist1;//不可以，因为sqr2不是constexpr函数
    return 0;
}
