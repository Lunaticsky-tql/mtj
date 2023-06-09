//
// Created by LENOVO on 2023/6/4.
//
//MT2157 迷宫
#include<bits/stdc++.h>
using namespace std;
const int N=3007;
const int mod=2333;
int n,m,a[N][N],dp[N][N];
int main(){
    cin>>m>>n;
    for(int i=m;i>=1;i--){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    dp[1][1]=1;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(!a[i][j]){
                // why +=? the loop includes dp[i][j] itself
                dp[i][j]+=(dp[i-1][j]+dp[i][j-1]);
                dp[i][j]%=mod;
            }
        }
    }
    cout<<dp[m][n];
}