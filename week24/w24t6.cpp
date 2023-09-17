//
// Created by 田佳业 on 2023/8/31.
//
//两字符串数字大小比较
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s1,s2;
    cin>>s1>>s2;
    if(s1.size()>s2.size()){
        cout<<'>'<<endl;
    }
    else if(s1.size()<s2.size()){
        cout<<'<'<<endl;
    }
    else{
        if(s1>s2){
            cout<<'>'<<endl;
        }
        else if(s1<s2){
            cout<<'<'<<endl;
        }
        else{
            cout<<'='<<endl;
        }
    }
}