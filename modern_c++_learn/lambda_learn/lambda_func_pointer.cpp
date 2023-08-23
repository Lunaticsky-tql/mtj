#include <iostream>

int main() {
    // Lambda函数没有捕获列表，可以隐式转换为函数指针
    auto lambda = [](int x, int y) -> int {
        return x + y;
    };

    // 隐式转换为函数指针并调用
    int result = lambda(3, 4);
    std::cout << "Result: " << result << std::endl;

    // 使用函数指针调用Lambda函数
    int (*funcPtr)(int, int) = lambda;
    int result2 = funcPtr(5, 6);
    std::cout << "Result via function pointer: " << result2 << std::endl;

    return 0;
}
