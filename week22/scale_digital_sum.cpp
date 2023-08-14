//
// Created by 田佳业 on 2023/8/13.
//
#include<bits/stdc++.h>
using namespace std;
int n,sum=0;
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
void addUp(int x,int o){
    while(n) {
        sum += x % o;
        x /= o;
    }
}
int main(){
    cin>>n;
    for(int i=2;i<n;i++){
        addUp(n,i);
    }
    int g=gcd(sum,n-2);
    cout<<sum/g<<'/'<<(n-2)/g;
    return 0;
}