//
// Created by 田佳业 on 2023/8/13.
//暴搜
#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
char d[]="0123456789ABCDEF";
int cnt=1,flag=1;
string tmp,ss[N]={"0"};
//1,12,123,....,12..CDEF,12..CDF,12..CEF,...
void dfs(int num){
    if(tmp.size()){
    ss[cnt++]=tmp;
    }
    for(int i=num+1;i<=15;i++){
        //假设初始前导位是0.试图追加一个更大的数
        tmp.push_back(d[i]);
        dfs(i);
        tmp.pop_back();
    }
}
bool cmp(string a,string b){
    if(a.length()==b.length()){
        return a<b;
    }
    return a.length()<b.length();
}

int main(){
    dfs(0);
    string s;
    cin>>s;
    if(s[0]=='-'){
        flag=-1;
        s.erase(s.begin());
    }
    while(s[0]=='0'&&s.length()>1){
        s.erase(s.begin());
    }
    sort(ss,ss+cnt,cmp);
    //二分更快，顺序也能过
    for(int i=0;i<cnt;i++){
        if(ss[i]==s){
            cout<<i*flag;
            return 0;
        }
    }
    cout<<"error";
    return 0;
}
