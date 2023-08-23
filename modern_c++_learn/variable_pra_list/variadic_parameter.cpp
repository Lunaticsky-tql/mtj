//
// Created by 田佳业 on 2023/8/20.
//
#include <iostream>
#include <cstdarg> // 头文件用于可变参数的支持
using namespace std;

double average(int count, ...) {
    va_list args; // 定义可变参数列表
    va_start(args, count); // 初始化可变参数列表

    double sum = 0;
    for (int i = 0; i < count; ++i) {
        double num = va_arg(args, double); // 从可变参数列表中获取参数
        sum += num;
    }

    va_end(args); // 结束可变参数列表

    return sum / count;
}

int main() {
    cout << "Average: " << average(4, 2.5, 3.5, 4.5, 5.5) << endl;
    cout << "Average: " << average(3, 10.0, 20.0, 30.0) << endl;
    return 0;
}
