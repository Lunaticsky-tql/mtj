//
// Created by 田佳业 on 2023/4/23.
//
//MT2122 事务处理
//很有CSP风格的一道实际场景的题目。这道题也比较好的阐释
//了"优先级队列"中"优先"的含义，在这道题中体现在我们需要将当前未完成的
//事务按优先级进行排列，每次去取优先级最大的(堆顶)
//而且我们实际上可以流水式的处理数据
#include<bits/stdc++.h>
using namespace std;
struct TASK{
    int ai,ti,fi,vi;
    bool operator<(const TASK &b) const{
        if(vi==b.vi){
            return ti>b.ti;
            // bigger task is prior
        }
        return vi<b.vi;
    }
}cur,tmp;
priority_queue<TASK> q;
int now;
int main(){
    while(cin>>cur.ai>>cur.ti>>cur.fi>>cur.vi){
        // handle the task on hand
        // >= is because ti task starts at ti+1
        while(!q.empty()&&cur.ti>=now+q.top().fi){
            // have time finishing the task on hand
            now+=q.top().fi;
            cout<<q.top().ai<<" "<<now<<endl;
            q.pop();
        }
       if(!q.empty()){
           // new task interrupts a task on hand
           tmp=q.top();
           q.pop();
           // because we make decision at ti
           tmp.fi-=cur.ti-now;
           q.push(tmp);
       }
       q.push(cur);
       now=cur.ti;
       //if the tmp task is prior, it will start again at ti
    }
    //now all tasks are on the to-do list, finish them one by one
    while(!q.empty()){
        tmp=q.top();
        q.pop();
        cout<<tmp.ai<<" "<<now+tmp.fi<<endl;
        now+=tmp.fi;
    }
    return 0;
}