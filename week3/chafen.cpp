//
// Created by 田佳业 on 2023/3/17.
//
#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int a[N],sub[N],n,ans;
int main(){
    int num;
    while(cin>>num){
        a[++n]=num;
        sub[n]=a[n]-a[n-1];
    }
    for(int i=2;i<n;i++){
        int temp=sub[i],k=i+1,t=0;
        while(sub[k]==temp)
        {
            t++;
            k++;
        }
        ans+=t;
    }
    cout<<ans;
    return 0;
}