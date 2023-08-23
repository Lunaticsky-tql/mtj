//
// Created by 田佳业 on 2023/6/15.
//
//MT2170 回文串
//小码妹是一个喜欢字符串的女孩子。
//小码妹有一个长度为 n 的字符串 ss 和一个大小为 m 的字符集。
//
//现在小码妹希望通过对字符串 s 增加或删去字符，使得 s 变为一个回文串。
//但是增加或删去不同字符需要花费的代价不同。
//小码妹希望花费最少的代价达成目标，于是她想寻求你的帮助。
//它没说只能在头尾增加删除，使用动态规划的理由是每一次子串"操作"都能使子串变成回文串，且由小的回文串可以经过迭代得到大的回文串
#include<bits/stdc++.h>
using namespace std;
const int N=2e3+7;
int n,m,cost[N],dp[N][N];
char c,s[N];
int x,y;
int main(){
    cin>>m>>n>>(s+1);
    while(m--){
        cin>>c>>x>>y;
        cost[c-'a']=min(x,y);
    }
    for(int r=1;r<=n;r++){
        for(int l=r-1;l>=1;l--){
            if(s[l]==s[r]){
                dp[l][r]=dp[l+1][r-1];
            }
            else{
                dp[l][r]=min(dp[l+1][r]+cost[s[l]-'a'],dp[l][r-1]+cost[s[r]-'a']);
            }
        }
    }
    cout<<dp[1][n]<<endl;
    return 0;
}