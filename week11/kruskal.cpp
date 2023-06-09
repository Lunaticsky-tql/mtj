//
// Created by LENOVO on 2023/6/2.
//
//
// Created by LENOVO on 2023/5/14.
//
// MT2140, 最小生成树板子题
#include<bits/stdc++.h>
using namespace std;
const int N=1e2+7;
struct NODE{
    int x,y,c;
    bool operator<(const NODE& a) const{
        return c<a.c;
    }
}p[N];

int fa[N],n,k,ans;
void init(){
    for(int i=1;i<N;i++){
        fa[i]=i;
    }
}
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx!=fy){
        fa[fx]=fy;
    }
}

int main(){
    init();
    cin>>n>>k;
    for(int i=1;i<=k;i++){
        cin>>p[i].x>>p[i].y>>p[i].c;
    }
    sort(p+1,p+k+1);
    for(int i=1;i<=k;i++){
        if(find(p[i].x)!=find(p[i].y)){
            ans+=p[i].c;
            merge(p[i].x,p[i].y);
        }
    }
    cout<<ans;
    return 0;
}