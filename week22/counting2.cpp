//
// Created by 田佳业 on 2023/8/13.
//
//小学奥数题，关于怎么数数的问题。分类讨论即可。
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll p[15]={1};
ll a[15],n;
ll ans;
char s[15];
const int mod=99999989;
int main(){
    cin>>n>>s;
    for(int i=1;i<=n;i++){
        p[i]=p[i-1]*16;
    }
    for(int i=0;i<n;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[i]=s[i]-'0';
        }else{
            a[i]=s[i]-'A'+10;
        }
    }
    for(int i=0;i<n;i++){
        ll pre=0,suf=0;
        for(int j=0;j<=i-1;j++){
            pre=pre*16+a[j];
        }
        for(int j=i+1;j<n;j++){
            suf=suf*16+a[j];
        }
        if(a[i]>2){
            ans+=(pre+1)*p[n-i-1]%mod;
        }else if(a[i]<2){
            ans+=pre*p[n-i-1]%mod;
        }else{
            ans+=pre*p[n-i-1]%mod+suf+1;
        }
        ans%=mod;
    }
    cout<<ans;
    return 0;

}