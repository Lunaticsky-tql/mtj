//
// Created by 田佳业 on 2023/8/19.
//
#include <iostream>
#include <thread>

void print_message(const std::string &message) {
    std::cout << message << std::endl;
}

int main() {
    std::thread t(print_message, "Thread 1");
    t.detach();
    std::cout << "Thread detached" << std::endl;
    return 0;
}