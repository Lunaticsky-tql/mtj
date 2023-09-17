//
// Created by 田佳业 on 2023/8/27.
//
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int p[107];
int ans;
char s[107];
signed main(){
    scanf("%lld",&n);
    p[0]=1;
    for(int i=1;i<=100;i++){
        p[i]=p[i-1]*3;
    }
    while(n--){
        scanf("%s",s);
        int len=strlen(s);
        ans=0;
        for(int i=len-1;i>=0;i--){
            if(s[i]=='-'){
                ans-=p[len-i-1];
            }else if(s[i]=='1'){
                ans+=p[len-i-1];
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}