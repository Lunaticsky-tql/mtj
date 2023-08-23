//
// Created by LENOVO on 2023/7/11.
//
//给一个字符串,求子串t,t是满足既是s前缀又是s后缀且在s中间出现过的最长的串
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int pi[N];
string s;

void pit(const string& s){
    for(int i=1,j=0;i<s.length();i++){
        while(j&&s[i]!=s[j]) j=pi[j-1];
        if(s[i]==s[j]) j++;
        pi[i]=j;
    }
}

int main(){
    cin>>s;
    pit(s);
    int len=pi[s.length()-1];
    while(len){
        string pre=s.substr(0,len);
        //检查是否在中间出现过
        string now=s.substr(1,s.length()-2);
        if(now.find(pre)!=string::npos){
            cout<<pre;
            return 0;
        }
        len=pi[len-1];
    }
    cout<<"Just a legend";
    return 0;
}