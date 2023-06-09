//
// Created by LENOVO on 2023/6/7.
//
//MT2160 写程序 完全背包
//有 n 个程序员，每个程序员都可以写任意行代码，总共要编写 m 行代码，这 m 行代码可以由多个程序员来编写。但是第 i 个程序员在一行代码中会出现
// a_i个 bug。现在希望知道有多少种方案能使得这 m 行代码中的 bug 的数量不超过 bb 个。
//
//两个方案不同当且仅当某个程序员编写的代码量（行数）不同。
//这个题出的很蠢，找bug最少的程序员写不就行了(笑，不过作为板子题，写一下
#include<bits/stdc++.h>
using namespace std;
const int N=507;
int a[N],dp[N][N],n,m,b,mod,ans;
int main(){
    cin>>n>>m>>b>>mod;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    //dp[j][k] means j lines with k bugs
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=a[i];k<=b;k++){
                dp[j][k]+=dp[j-1][k-a[i]];
                dp[j][k]%=mod;
            }
        }
    }
    for(int i=0;i<=b;i++){
        ans=(ans+dp[m][i])%mod;
    }
    cout<<ans;
    return 0;
}
