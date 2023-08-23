//
// Created by LENOVO on 2023/7/11.
//
//洛谷P3375 【模板】KMP字符串匹配
//给出两个字符串 $s_1$ 和 $s_2$，若 $s_1$ 的区间 $[l, r]$ 子串与 $s_2$ 完全相同，则称 $s_2$ 在 $s_1$ 中出现了，其出现位置为 $l$。
//现在请你求出 $s_2$ 在 $s_1$ 中所有出现的位置。
//
//定义一个字符串 $s$ 的 border 为 $s$ 的一个**非 $s$ 本身**的子串 $t$，满足 $t$ 既是 $s$ 的前缀，又是 $s$ 的后缀。
//对于 $s_2$，你还需要求出对于其每个前缀 $s'$ 的最长 border $t'$ 的长度。
#include<bits/stdc++.h>
using namespace std;
const int M=1e6+5;
int pmt[M];
void get_pmt(const string & s){
    for(int i=1,j=0;i<s.length();++i){
        while(j&&s[i]!=s[j]) j=pmt[j-1];
        if(s[i]==s[j])++j;
        pmt[i]=j;

    }
}

void mp(const string & s,const string& p){
    for(int i=0,j=0;i<s.length();++i){
        while(j&&s[i]!=p[j]) j=pmt[j-1];
        if(s[i]==p[j]) j++;
        if(j==p.length()){
            // 加1是因为j多加到了p.length()，但是i没有多加,又因为题目要求从1开始，所以总共要加2
            cout<<i-j+2<<endl;
            j=pmt[j-1];
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s,p;
    cin>>s>>p;
    get_pmt(p);
    mp(s,p);
    for(int i=0;i<p.length();i++){
        cout<<pmt[i]<<' ';
    }
    return 0;
}