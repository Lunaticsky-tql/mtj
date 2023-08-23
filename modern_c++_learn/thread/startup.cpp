#include <iostream>
#include <thread>

void print_message(const std::string &message) { std::cout << message << std::endl; }

void increment(int &x) { ++x; }

int main() {
    std::string message = "Hello, world!";
    std::thread t(print_message, message);
    t.join();
    int x = 0;
    std::thread t2(increment, std::ref(x));
    t2.join();
    std::cout << x << std::endl;
    return 0;
}