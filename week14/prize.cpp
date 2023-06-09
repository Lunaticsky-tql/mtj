//
// Created by LENOVO on 2023/6/4.
//
//MT2152
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,dp[40][160],sum1,sum2,denominator=1,tmp;
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
signed main(){
    cin>>n;
    dp[1][1]=dp[1][2]=dp[1][3]=dp[1][4]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=4*n;j++){
            for(int k=1;k<=4;k++){
                if(j>k){
                    dp[i][j]+=dp[i-1][j-k];
                }
            }
        }
    }
    for(int i=n;i<2*n;i++){
        sum1+=dp[n][i];
    }
    for(int i=3*n+1;i<=4*n;i++){
        sum2+=dp[n][i];
    }
    for(int i=1;i<=n;i++){
        denominator*=4;
    }
    tmp=gcd(sum1,denominator);
    cout<<sum1/tmp<<"/"<<denominator/tmp<<endl;
    tmp=gcd(sum2,denominator);
    cout<<sum2/tmp<<"/"<<denominator/tmp<<endl;
    return 0;
}