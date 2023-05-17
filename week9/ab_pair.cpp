//
// Created by 田佳业 on 2023/4/30.
//
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int a[N];
map<int,int> mp;
int main(){
    int n,C;
    cin>>n>>C;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]++;
        a[i]-=C;
    }
    long long ans=0;
    for(int i=0;i<n;i++){
        ans+=mp[a[i]];
    }
    cout<<ans;
    return 0;
}
