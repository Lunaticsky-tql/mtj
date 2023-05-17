//
// Created by 田佳业 on 2023/4/5.
//
#include<bits/stdc++.h>
using namespace std;
const int N= 1e5+7;
int n,a[N];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int bi;
    for(int i=1;i<=n;i++)
    {
        cin>>bi;
        a[i]=a[i]-bi;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n>>1;i++){
        if(a[i]+a[n-i+1]!=0)
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}