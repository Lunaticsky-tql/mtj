//
// Created by 田佳业 on 2023/3/24.
//
#include<iostream>
using namespace std;
#define ll long long
const int S=1e6+10;
ll N,M,l,r,mid,ans,a[S];
bool check(ll num)
{
    ll got=0;
    for(int i=0;i<N;i++)
    {
        if(a[i]>=num)
            got+=a[i]-num;

    }
    return got>=M;
}
int main()
{
    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        cin>>a[i];
        r=max(r,a[i]);
    }
   while(l<=r){
       mid=l+(r-l)/2;
       if(check(mid))
       {
           ans=mid;
           l=mid+1;
       }
       else
           r=mid-1;
   }
   cout<<ans;
   return 0;
}
