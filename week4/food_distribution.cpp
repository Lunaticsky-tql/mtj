//
// Created by 田佳业 on 2023/3/23.
//
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int n,ans,wt[N],fd[N];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>wt[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(wt[i]<wt[i+1])
        {
            fd[i+1]=fd[i]+1;
        }
        else if(wt[i]==wt[i+1])
        {
            fd[i+1]=fd[i];
        }
    }
    for(int i=n;i>=1;i--)
    {
        if(wt[i-1]>wt[i])
        {
            fd[i-1]=max(fd[i-1],fd[i]+1);
        }
    }
    for(int i=1;i<=n;i++)
    {
        ans+=fd[i];
    }
    cout<<ans+n;
    return 0;
}