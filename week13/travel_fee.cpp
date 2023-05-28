//
// Created by 田佳业 on 2023/5/28.
//
//MT2150
#include<bits/stdc++.h>
using namespace std;
const int N=1e3+7;
int a[N][N],dp[N],n;
int main(){
    cin>>n;
    //for example n=1
    //   0 1 2
    // 0 0 6 18
    // 1 0 0 9
    // 2 0 0 0
    // the 0 is actually meaningless
    // include the start point and the end point
    for(int i=0;i<n+1;i++) {
        for (int j = i + 1; j <= n + 1; j++)
            cin >> a[i][j];
        dp[i]=INT32_MAX;
    }
    for(int i=n;i>=0;i--){
        for(int j=i+1;j<=n+1;j++){
            dp[i]=min(dp[i],dp[j]+a[i][j]);
            // for example the first loop is
            // dp[1]=min(dp[1],dp[2]+a[1][2])
            //dp[2] is initialized as 0 because it is the end point
            // others are initialized as INT32_MAX
            //so dp[1]=a[1][2]=9,which is the minimum dis to the end point
            // dp[0]=min(dp[0],dp[1]+a[0][1],dp[2]+a[0][2])=min(dp[0],9+6,0+18)=15
        }
    }
    cout<<dp[0];
    return 0;
}