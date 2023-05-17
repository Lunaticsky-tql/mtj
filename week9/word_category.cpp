
//
// Created by 田佳业 on 2023/4/30.
//
#include<bits/stdc++.h>
using namespace std;
int n,ans;
string s;
unordered_map<string,int> mp;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        sort(s.begin(),s.end());
        if(!mp[s]){
            ans++;
            mp[s]=1;
        }
    }
    cout<<ans;
    return 0;
}