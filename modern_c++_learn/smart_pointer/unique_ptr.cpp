//
// Created by 田佳业 on 2023/8/16.
//
#include <iostream>
using namespace std;
#include <memory>

class Rectangle {
    int length;
    int breadth;

public:
    Rectangle(int l, int b){
        length = l;
        breadth = b;
    }

    constexpr int area(){
        return length * breadth;
    }
};

int main(){
    unique_ptr<Rectangle> P1(new Rectangle(10, 5));
    cout << P1->area() << endl; // This'll print 50

    unique_ptr<Rectangle> P2;
    // unique_ptr<Rectangle> P2(P1); // 无法拷贝构造
    // P2 = P1;   // 无法赋值构造
    P2 = std::move(P1);

    cout << P2->area() << endl;

//     cout<<P1->area()<<endl; // 已经传递，P1 无所有权
     //Clang-Tidy: 'P1' used after it was moved
    return 0;
}
