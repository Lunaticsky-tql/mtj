//
// Created by 田佳业 on 2023/4/1.
//
#include<bits/stdc++.h>
using namespace std;
#define ll long long
string a0="IAKIOI";
string a1="WHENWILLSCORLLOFTAIWUCOMEOUT!!!";
ll len[85],n,c;
void fib(ll n,ll c){
    if(n==0){
        cout<<a0[c-1];
        return;
    }
    else if(n==1){
        cout<<a1[c-1];
    }
    else if(c<=len[n-2]){
        fib(n-2,c);
    }
    else {
        fib(n - 1, c - len[n - 2]);
    }
}
int main(){
    cin>>n>>c;
    len[0]=a0.length();
    len[1]=a1.length();
    for(int i=2;i<=n;i++){
        len[i]=len[i-1]+len[i-2];
    }
    fib(n,c);
}