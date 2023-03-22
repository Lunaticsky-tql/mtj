//
// Created by 田佳业 on 2023/3/17.
//
// 二维前缀和的简单应用
#include<bits/stdc++.h>
using namespace std;
const int N=210;
int n,m,a[N][N],sum[N][N],ans;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int k=i;k<=n;k++)
            {
                for(int l=j;l<=m;l++)
                {
                    int area=(k-i+1)*(l-j+1);
                    int sum_area=sum[k][l]-sum[i-1][l]-sum[k][j-1]+sum[i-1][j-1];
                    if(area>ans&&sum_area>0)
                        ans=area;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}