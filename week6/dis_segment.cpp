//
// Created by 田佳业 on 2023/4/5.
//
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N= 1e5;
ll n, a[N],ans;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++){
        ans+=ans+abs(a[(n+1)>>1]-a[i]);
    }
    cout<<ans;
    return 0;
}