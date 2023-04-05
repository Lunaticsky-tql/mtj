//
// Created by 田佳业 on 2023/4/1.
//
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[21]={0,0,1};
int main(){
    int n;
    cin>>n;
    for(int i=3;i<=n;i++)
    {
        a[i]=(i-1)*(a[i-2]+a[i-1]);
    }
    cout<<a[n];
    return 0;
}
