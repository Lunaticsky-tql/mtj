//
// Created by 田佳业 on 2023/3/18.
//
#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
const int N=1e6+10;
# define ll long long
ll n,t,tt[N],sum[N],ans;
ll b[N];
void merge(ll *a, int l, int m, int r) {
    int i=l,j=m+1,k=0;
    while(i<=m&&j<=r)
    {
        if(a[i]<=a[j])
        {
            b[k++]=a[j++];
            ans+=m-i+1;
            ans%=MOD;
        }
        else
            b[k++]=a[i++];
    }
    while(i<=m)
        b[k++]=a[i++];
    while(j<=r)
        b[k++]=a[j++];
    for(int p=l;p<=r;p++)
        a[p]=b[p-l];
}


void merge_sort(ll *a, int l, int r) {
    if(l>=r)
        return;
    int m=(l+r)/2;
    merge_sort(a,l,m);
    merge_sort(a,m+1,r);
    merge(a,l,m,r);
}
int main()
{
    cin>>n>>t;
    for(int i=1;i<=n;i++)
    {
        cin>>tt[i];
        tt[i]-=t;
        sum[i]=sum[i-1]+tt[i];
    }
    merge_sort(sum,0,n);
    cout<<ans%MOD;
    return 0;
}