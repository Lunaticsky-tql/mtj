//
// Created by 田佳业 on 2023/4/13.
//
#include<bits/stdc++.h>
using namespace std;
stack<int> stack_value;
stack<int> stack_min;
void push(int x){
    stack_value.push(x);
    if(stack_min.empty()||stack_min.top()>=x){
        stack_min.push(x);
    }
}
void pop(){
    if(stack_min.top()==stack_value.top()){
        stack_min.pop();
    }
    stack_value.pop();
}
int top(){
    return stack_value.top();
}
int get_min(){
    return stack_min.top();
}
int main(){
    int n;
    int x;
    cin>>n;
    while(n--){
        int a;
        cin>>a;
        switch(a){
            case 1:
                cin>>x;
                push(x);
                break;
            case 2:
                pop();
                break;
            case 3:
                cout<<top()<<endl;
                break;
            case 4:
               cout<<get_min()<<endl;
               break;
            default:
                break;
        }
    }
    return 0;
}