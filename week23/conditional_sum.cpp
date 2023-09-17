//
// Created by 田佳业 on 2023/8/27.
//
#include<bits/stdc++.h>
using namespace std;
int n;
unsigned ans,a;
int main(){
    scanf("%d",&n);
    scanf("%u",&ans);
    for(int i=1;i<n;i++){
        scanf("%u",&a);
        ans=~ans|a;
    }
    printf("%u\n",ans);
    return 0;
}