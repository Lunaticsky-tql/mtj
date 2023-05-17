//
// Created by 田佳业 on 2023/4/21.
//
#include<iostream>
using namespace std;
class B{
    static int b;
public:
    B(){b++;}
    int getB(){return b;}
};
int B::b=0;
class C1:virtual public B{
    int b=0;
public:
    C1(){b++;}
    int getB(){return b;}

};
class C2:virtual public B{
    int b=0;
public:
    C2(){b++;}
    int getB(){
        return b;
    }
};
class D:public C2,public C1{
    int b=0;
    C1 c1;
    C2 c2;
public:
    D(){b=5;}
    int getB(){
        return b;
    }
};
int main(){
    B b, *p;
    C1 *p1;
    C2 *p2;
    p=new C1[5];
    p1=new D[2];
    p2=new D[3];
    cout<<b.getB()<<endl;
    cout<<p->getB()<<endl;
    cout<<p1->getB()<<endl;
    cout<<p2->getB()<<endl;
    return 0;
}