//
// Created by 田佳业 on 2023/4/30.
//
#include<bits/stdc++.h>
#define for_range(i, a, b) for(int i = a; i < b; i++)
using namespace std;
map<int,int> mp;
const int N=1e5+3;
int a[N];
int main(){
    int n;
    cin>>n;
    for_range(i,0,n){
        cin>>a[i];
        mp[a[i]]++;
    }
    int ans=0;
    for(auto& it:mp){
        if(it.second>=it.first){
            ans=max(ans,it.first);
        }
    }
    cout<<ans;
    return 0;
}
