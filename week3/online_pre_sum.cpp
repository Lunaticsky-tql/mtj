//
// Created by 田佳业 on 2023/3/17.
//
// 针对大数据的在线前缀和
#include<bits/stdc++.h>
using namespace std;
const int N=500000;
struct TIME{
    int qID; // -1 is for recording ,others are for query
    int edge; // 0 is for left ,1 is for right
    int time; // literally
}t[N];
int ans[N];
bool cmp(TIME a,TIME b){
    return a.time<b.time;
}
int main(){
    int n,q,cnt=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        t[cnt++]={-1,0,l};
        t[cnt++]={-1,1,r};
    }
    cin>>q;
    for(int i=0;i<q;i++){
        int r,m;
        cin>>r>>m;
        t[cnt++]={i,0,r-m};
        t[cnt++]={i,1,r};
    }
    sort(t,t+cnt,cmp);
    int cur_pre_sum=0,cur_time=0;
    bool is_working=false;
    for(int i=0;i<cnt;i++){
        int qID=t[i].qID;
        int edge=t[i].edge;
        int time=t[i].time;
        if(qID==-1){ // recording
            if(edge==0){
                is_working=true;
                cur_time=time;
            }
            else{
                is_working=false;
                cur_pre_sum+=time-cur_time;
            }
        }
        else{ // query
            if(is_working){
                // we need to update the time and pre_sum
                // ps: at the "rising edge" of the working time
                // the is_working is uncertain (depends on the order of the t[] at the same time)
                // but it won't affect the result because we only need
                // to update the pre_sum when we're actually working or at the "falling edge"
                cur_pre_sum+=time-cur_time; // cur_time here is the time we last updated it
                cur_time=time;
            }
            if(edge==0)
            {
                // at the start of query range
                // record the pre_sum now in the ans
                ans[qID]=cur_pre_sum;
            }
            else{
                // at the end of the query range
                // "ans=sum[end_time]-sum[start_time]"
                ans[qID]=cur_pre_sum-ans[qID];
            }
        }
    }
    for(int i=0;i<q;i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;


}