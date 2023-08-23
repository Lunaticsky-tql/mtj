//
// Created by 田佳业 on 2023/8/16.
//
#include <iostream>
#include <cstring>
#include <functional>

auto GetFunc(){
    std::string s = "112234234234";
    return [&](){ std::cout << s << std::endl; };
    //Address of stack memory associated with local variable
    // 's' returned implicitly captured by reference due to use here
    //当 GetFunc 返回时，s 的对象已经被销毁，此时 s 的引用则会出现问题，应将其修改为值传递。
}

int main(int, char*[]){
    auto func = GetFunc();
    func();
    return 0;
}
