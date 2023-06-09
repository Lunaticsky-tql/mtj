//
// Created by LENOVO on 2023/6/7.
//
//MT2163 构造字符串
//用a，b，ca，b，c三种元素构造一个长度为nn的字符串，要求：这个字符串中不能有三个相邻的元素，元素值相同，即aaaaaa，这种数列不可以出现；
//问可以构造出多少种符合条件的字符串?
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int f,n,dp[100005][2];
//dp[i][j] means the number of strings with length i and the last two elements are different or not
// j=0 :same j=1:different
signed main(){
    dp[1][0]=0;dp[1][1]=3;
    for(int i=2;i<=100000;i++){
        // if we want the last two elements same, we can only add a same element
        //eg: xxxa -> xxxaa
        dp[i][0]=dp[i-1][1];
        // if we want the last two elements different, we can add a different element
        //eg: xxxa -> xxxab xxxac
        dp[i][1]=2*(dp[i-1][0]+dp[i-1][1])%mod;
    }
    cin>>f;
    while(f--){
        cin>>n;
        cout<<(dp[n][0]+dp[n][1])%mod<<endl;
    }
    return 0;
}