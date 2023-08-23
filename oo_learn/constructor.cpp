//
// Created by 田佳业 on 2023/8/15.
//
#include<iostream>
using namespace std;
class point {
public:
    point() {
        cout << "C";
    }
    ~point() {
        cout << "D";
    }
};

int main() {
    point *ptr;
    point A, B;
    auto *ptr_point = new point[3];
//    for(int i=0;i<2;i++){
//        delete[] ptr_point;
//    }
    delete[] ptr_point;
    return 0;
}