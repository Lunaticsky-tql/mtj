//
// Created by 田佳业 on 2023/4/23.
//
//MT2116 栈间
// 用一种比较新的方式写栈的模版
#include<bits/stdc++.h>
using namespace std;
const int N=5e6+7;
int n,st[N],op,x;
int main(){
    cin>>n;
    while(n--){
        scanf("%d",&op);
        switch(op){
            case 1:
                scanf("%d",&x);
                st[++*st]=x;
                break;
            case 2:
                printf("%d\n",st[*st]);
                break;
            case 3:
                scanf("%d",&x);
                printf("%d\n",st[x+1]);
                break;
            case 4:
                *st?--*st:0;
                break;
        }
    }
    return 0;
}