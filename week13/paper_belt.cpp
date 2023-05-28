//
// Created by 田佳业 on 2023/5/28.
//
#include<bits/stdc++.h>
//不是很喜欢这个题，构造痕迹有些严重，没啥实际价值
//不过前缀和优化的思路还是很重要的
using namespace std;
#define ll long long
const int N = 4e6 + 5;
int n, mod;
ll dp[N], sum[N];

int main() {
    cin >> n >> mod;
    dp[n] = sum[n] = 1;
    for (int i = n - 1; i >= 1; i--) {
        dp[i] = sum[i + 1];
        for (int j = 2; j * i <= n; j++) {
            int r=min(n,i*j+j-1);
            dp[i]=(dp[i]+sum[i*j]-sum[r+1])%mod;
        }
        sum[i] = (sum[i + 1] + dp[i]) % mod;
    }
    cout<<dp[1];
    return 0;
}