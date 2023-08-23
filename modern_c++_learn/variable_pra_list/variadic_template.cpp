//
// Created by 田佳业 on 2023/8/20.
//
// 用来终止递归并处理包中最后一个元素
#include <iostream>
using namespace std;
template <typename T>
void print(const T &t)
{
    cout << t;
}

// 包中除了最后一个元素之外的其他元素都会调用这个版本的print
template <typename T, typename...Args>
void print(const T &t, const Args&...rest)
{
    cout << t << " ";     // 打印第一个实参
    print(rest...);       // 递归调用，打印其他实参
}

// 测试
int main()
{
    print("string1", 2, 3.14f, "string2", 42);
    cout << endl;
    return 0;
}