//
// Created by 田佳业 on 2023/3/24.
//
#include<bits/stdc++.h>
using namespace std;
int N,M,l,r,mid,ans,a[50005];
bool check(int dis){
    int now=a[0],cnt=1;
    for(int i=1;i<N;i++){
        if(a[i]-now>=dis){
            now=a[i];
            cnt++;
        }
        if(cnt>=M)
            return true;
    }
    return false;
}
int main(){
    cin>>N>>M;
    for(int i=0;i<N;++i){
        cin>>a[i];
    }
    sort(a,a+N);
    r=a[N-1];
    while(l<=r){
        mid=l+(r-l)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}