//
// Created by LENOVO on 2023/6/7.
//
// MT2159 赶deadline 01背包记录路径
//小码哥有严重的拖延症，因此他经常赶deadline(即忙于要完成的任务)。有一天小码哥向你求助，因为要做的事太多了，只能舍弃一些相对不重要的。
//小码哥共有n项任务，每个任务有重要度$I_i$和需要消耗的时间$t_i$。小码哥现在还有时间$T_i$,他希望你帮忙写一个程序判断应该选择完成哪些任务使得完成的任务重要度之和最大。
#include<bits/stdc++.h>
using namespace std;
const int N=1e4+7;
const int T_max=2007;
int w[N],v[N],dp[N],path[N][T_max],n,T,ans[N];
int main(){
    cin>>n>>T;
    for(int i=1;i<=n;i++){
        cin>>v[i]>>w[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=T;j>=w[i];j--){
            if(dp[j-w[i]]+v[i]>dp[j]){
                dp[j]=dp[j-w[i]]+v[i];
                path[i][j]=1;
                // 当然这个题只需要记录i，而且可以用map省空间，不过这样写比较快,而且通用
            }
        }
    }
    cout<<dp[T]<<endl;
    int i=n,j=T,cnt=0;
    while(i>=1&&j){
        if(path[i][j]){
            ans[cnt++]=i;
            j-=w[i];
        }
        i--;
    }
    for(int k=cnt-1;k>=0;k--){
        cout<<ans[k]<<" ";
    }
    return 0;
}
