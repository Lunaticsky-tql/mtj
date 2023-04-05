//
// Created by 田佳业 on 2023/3/23.
//
#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int N = 5e5 + 7;
ll m, n, a[N], ans;

int main() {
    cin >> m >> n;
    ll sum = 0;
    for (int i = 0; i <n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sum-=m;
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        ll w=min(a[i],sum/(n-i));
        ans+=w*w;
        sum-=w;
    }
    cout<<ans;
    return 0;

}