//
// Created by 田佳业 on 2023/5/28.
//
//最大子序列，力扣经典题目
#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 7;
int n, dp[N], ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> dp[i];
    }
    ans = dp[1];
    for (int i = 2; i <= n; i++) {
        dp[i] = max(dp[i], dp[i - 1] + dp[i]);
        ans = max(ans, dp[i]);
    }
    cout<<ans;
    return 0;
}