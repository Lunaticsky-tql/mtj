//
// Created by 田佳业 on 2023/7/19.
//
#include <iostream>
#include <queue>
#include <vector>

int main() {
    // 定义存放std::pair<int>的小顶堆
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<>> minHeap;

    // 添加元素到小顶堆
    minHeap.emplace(3, 100);
    minHeap.emplace(1, 200);
    minHeap.emplace(5, 50);
    minHeap.emplace(2, 300);

    // 输出小顶堆中的元素
    while (!minHeap.empty()) {
        std::pair<int,int> topElement = minHeap.top();
        std::cout << "First: " << topElement.first << ", Second: " << topElement.second << std::endl;
        minHeap.pop();
    }

    return 0;
}