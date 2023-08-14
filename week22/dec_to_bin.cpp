//
// Created by 田佳业 on 2023/8/13.
//
//究极水题
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,t;
    string res;
    cin>>t;
    //n-1 numbers
    while(--t){
        cin>>n;
        while(n){
            res.push_back(((signed char)(n%2+'0')));
            n=n/2;
        }
        reverse(res.begin(),res.end());
        cout<<res<<endl;
        res.clear();
    }
    return 0;
}