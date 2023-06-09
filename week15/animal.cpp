//
// Created by LENOVO on 2023/6/7.
//
//MT2158 零1背包
#include<bits/stdc++.h>
using namespace std;
int ani[1005],dp[100005],n,x;
int main(){
    cin>>n>>x;
    for(int i=1;i<=n;i++){
        cin>>ani[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=x;j>=ani[i];j--){
            dp[j]=max(dp[j],dp[j-ani[i]]+1);
        }
    }
    cout<<dp[x];
    return 0;
}