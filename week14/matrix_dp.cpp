//
// Created by LENOVO on 2023/6/4.
//
//MT2156 矩阵取数,是一个背包问题
#include<bits/stdc++.h>
using namespace std;
int n, m, mod, a[75][75], dp[75][75][75],ans;
int INF=0x3f3f3f3f;
int main() {
    cin >> n >> m >> mod;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    memset(dp, -INF, sizeof(dp));
    dp[0][0][0]=0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j == 1) {
                for (int k = 0; k <= m / 2; k++) {
                    for (int l = 0; l < mod; l++) {
                        dp[i][0][l] = max(dp[i][0][l], dp[i - 1][k][l]);
                    }
                }
            }
                for (int k = m / 2 - 1; k >= 0; k--) {
                    for (int l = 0; l < mod; l++) {
                        dp[i][k + 1][(l + a[i][j]) % mod] = max(dp[i][k + 1][(l + a[i][j]) % mod],
                                                                dp[i][k][l] + a[i][j]);
                    }
                }

        }
    }
    for(int j=0;j<=m/2;j++){
        ans=max(ans,dp[n][j][0]);
    }
    cout<<ans;
    return 0;
}