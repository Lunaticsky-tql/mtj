//
// Created by 田佳业 on 2023/8/16.
//
#include <iostream>
#include <memory>
using namespace std;

class B;

class A {
public:
    shared_ptr<B> b_;
    A() {
        cout << "A constructed!" << endl;
    }
    ~A() {
        cout << "A destructed!" << endl;
    }
};

class B {
public:
    shared_ptr<A> a_;
    B() {
        cout << "B constructed!" << endl;
    }
    ~B() {
        cout << "B destructed!" << endl;
    }
};

int main()
{
    auto classA = make_shared<A>();
    auto classB = make_shared<B>();
    classA->b_ = classB;
    classB->a_ = classA;
    cout << "A: " << classA.use_count() << endl;
    cout << "B: " << classB.use_count() << endl;
    return 0;
}
