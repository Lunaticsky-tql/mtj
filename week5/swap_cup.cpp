//
// Created by 田佳业 on 2023/4/1.
//
#include<bits/stdc++.h>
using namespace std;
int n,m,t;
#define N 50005
string s[N];
map<string,int> mp;
int main(){
    cin>>n>>m>>t;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        mp[s[i]]=i;
    }
    while(t--){
        int p1,p2;
        cin>>p1>>p2;
        swap(s[p1],s[p2]);
        swap(mp[s[p1]],mp[s[p2]]);
    }
    string tmp;
    while(m--){
        cin>>tmp;
        cout<<mp[tmp]<<endl;
    }
    return 0;

}