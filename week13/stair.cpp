//
// Created by 田佳业 on 2023/5/28.
//
//你能一分钟过一道题吗
#include<bits/stdc++.h>
using namespace std;
int n,m,num;
long long dp[100];
int main(){
    cin>>m>>n;
    num=(n-1)*m;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=num;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[num];
    return 0;
}