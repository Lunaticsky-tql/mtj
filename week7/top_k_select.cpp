//
// Created by 田佳业 on 2023/4/13.
//
//从两个长度相等的数组中任选元素，求两个元素的和前k个最小的
#include<bits/stdc++.h>
using namespace std;
const int N=1e8+7;
int n,k,a[N],b[N];
struct node{
    int ia,ib;
    int num;
    bool operator>(const node& node) const{
        return num>node.num;
    }
};
priority_queue<node,vector<node>,greater<>> pq;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    for(int i=0;i<n;i++){
        pq.push({i,0,a[i]+b[0]});
    }
    node cur;
    while(k--){
       cur=pq.top(),pq.pop();
       cout<<cur.num<<" ";
       // push the next node
       // although the next node a[i]+b[i+1] may not be the
       // smallest than the other candidates, but it is the only
       // potentially be the smallest in the heap
       cur.num=a[cur.ia]+b[++cur.ib];
       pq.push(cur);
    }
    return 0;
}