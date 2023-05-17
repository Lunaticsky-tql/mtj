//
// Created by 田佳业 on 2023/4/21.
//
#include<iostream>
using namespace std;
class Sample{
    int n;
public:
    Sample():n(0){}
    explicit Sample(int m){n=m;};
    int& operator--(int){
        n--;
        return n;
    }
    void disp(){
        cout<<n<<endl;
    }
};
int main(){
    Sample s(10);
    (s--)++;
    s.disp();
    return 0;
}