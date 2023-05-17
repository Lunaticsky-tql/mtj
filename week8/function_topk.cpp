//
// Created by 田佳业 on 2023/4/23.
//
//MT2120 第k小函数值
// 和上周的topk思路完全一样
#include<bits/stdc++.h>
using namespace std;
struct FUNC{
    int ans,a,b,c,x;
    bool operator>(const FUNC& func) const{
        return ans>func.ans;
    }
};
priority_queue<FUNC,vector<FUNC>,greater<FUNC>> pq;
int n,k;
int f(int a,int b,int c,int x){
    return a*x*x+b*x+c;
}
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        pq.push({f(a,b,c,1),a,b,c,1});
    }
    while(--k) {
        FUNC cur = pq.top();
        pq.pop();
        pq.push({f(cur.a, cur.b, cur.c, ++cur.x), cur.a, cur.b, cur.c, cur.x});
    }
    cout<<pq.top().ans;
    return 0;
}