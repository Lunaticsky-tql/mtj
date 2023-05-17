//
// Created by 田佳业 on 2023/4/15.
//
// 在从多个长度相等的数组中任选元素，求这些元素的和前k个最小的
#include<bits/stdc++.h>
using namespace std;
const int N= 500;
int n,m,k,a[N],b[N],c[N];
struct node{
    int ia,ib,num;
    bool operator>(const node& node) const{
        return num>node.num;
    }
};
priority_queue<node,vector<node>,greater<node>> pq;
int main(){
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    sort(a,a+m);
    sort(b,b+m);
    for(int i=0;i<m;i++){
        pq.push({i,0,a[i]+b[0]});
    }
    for(int i=0;i<k;i++){
        node cur=pq.top();
        pq.pop();
       c[i]=cur.num;
        cur.num=a[cur.ia]+b[++cur.ib];
        pq.push(cur);
    }
    n-=2;
    while(n--){
        while(!pq.empty()) pq.pop();
        for(int i=0;i<k;i++) {
            a[i] = c[i];
        }
        for(int i=0;i<m;i++){
            cin>>b[i];
        }
        sort(b,b+m);
        for(int i=0;i<k;i++){
            pq.push({i,0,a[i]+b[0]});
        }
        for(int i=0;i<k;i++){
            node cur=pq.top();
            pq.pop();
            c[i]=cur.num;
            cur.num=a[cur.ia]+b[++cur.ib];
            pq.push(cur);
        }
    }
    for(int i=0;i<k;i++){
        cout<<c[i]<<" ";
    }
    return 0;

}