//
// Created by 田佳业 on 2023/4/21.
//
#include<iostream>
using namespace std;
class B{
public:
    B(){
        cout<<"B::B()"<<endl;
    }
};

class D1:virtual public B{
public:
    D1(){
        cout<<"D1::D1()"<<endl;
    }
};
class D2:virtual public B{
public:
    D2(){
        cout<<"D2::D2()"<<endl;
    }
};
class E:public D1,public D2{
public:
    E(){
        cout<<"E::E()"<<endl;
    }
};

class Empty{};
int main(){
    E e;
    Empty empty;
    cout<<sizeof(Empty)<<endl;
    cout<<sizeof(empty)<<endl;
    return 0;
}