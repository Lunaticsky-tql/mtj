//
// Created by LENOVO on 2023/6/4.
//
//MT2154 海龟
// 这个题是真没什么思路,直接看题解了,还是需要多领会状态转移方程如何设计
#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
// dp[command_pos][flip_times][direction]
int dp[101][51][2],n;
signed main(){
    cin>>s>>n;
    int size=s.size();
    // convert string to start at index 1
    s=" "+s;
    for(int i=0;i<=size;i++){
        for(int j=0;j<=n;j++){
            // the result may be negative, so initialize to -inf
            dp[i][j][0]=dp[i][j][1]=INT32_MIN;
        }
    }
    dp[0][0][0]=dp[0][0][1]=0;
    for(int i=1;i<=size;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<=j;k++){
                // the k means it flips k times at position i  (j times in total)
                // so the older state is j-k flips at position i-1
                if(s[i]=='T'){
                    if(k%2==1){
                        // T flips to F, direction not changed, distance +1
                        dp[i][j][0]=max(dp[i][j][0],dp[i-1][j-k][0]+1);
                        dp[i][j][1]=max(dp[i][j][1],dp[i-1][j-k][1]-1);
                    }
                    else{
                        // T flips to T, direction change, distance not changed
                        dp[i][j][0]=max(dp[i][j][0],dp[i-1][j-k][1]);
                        dp[i][j][1]=max(dp[i][j][1],dp[i-1][j-k][0]);
                    }
                }
                else{
                    if(k%2==1){
                        // F flips to T, direction change, distance not changed
                        dp[i][j][0]=max(dp[i][j][0],dp[i-1][j-k][1]);
                        dp[i][j][1]=max(dp[i][j][1],dp[i-1][j-k][0]);
                    }
                    else{
                        // F flips to F, direction not changed, distance +1
                        dp[i][j][0]=max(dp[i][j][0],dp[i-1][j-k][0]+1);
                        dp[i][j][1]=max(dp[i][j][1],dp[i-1][j-k][1]-1);
                    }
                }
            }
        }
    }
    cout<<max(dp[size][n][0],dp[size][n][1]);
    return 0;
}