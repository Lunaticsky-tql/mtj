// Created by LENOVO on 2023/5/14.
//
//MT2137和洛谷的亲戚是一道题
#include<bits/stdc++.h>
using namespace std;
const int N=2e4+7;
int fa[N],rk[N],q,a,b,k;
void init(int n){
    for(int i=0;i<n;i++){
        fa[i]=i;
        rk[i]=1;
    }
}

int find(int x){
    return x==fa[x]?x:(fa[x]=find(fa[x]));
}

void merge(int x,int y) {
    int fx = find(x), fy = find(y);
    if (rk[fx] <= rk[fy]) {
        fa[fx] = fy;
    } else {
        fa[fy] = fx;
    }
    if (rk[fx] == rk[fy] && fx != fy) {
        rk[fy]++;
    }
}

int main(){
    cin>>k;
    init(2*k);
    while(k--){
        cin>>a>>b;
        merge(a,b);
    }
    cin>>q;
    while(q--){
        cin>>a>>b;
        if(find(a)==find(b)){
            cout<<"1"<<endl;
        }
        else{
            cout<<"0"<<endl;
        }
    }
    return 0;
}