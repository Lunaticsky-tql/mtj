//
// Created by 田佳业 on 2023/8/27.
//
//二进制最小非负整数
//https://leetcode.cn/problems/first-missing-positive/
#include<bits/stdc++.h>
using namespace std;
string s;
unordered_set<int> st;
int cnt;
int len;
int main(){
    while(cin>>s){
        int dec=0;
        for(char i : s){
            dec=(dec<<1)+i-'0';
        }
        st.insert(dec);
        cnt++;
        len=s.length();
    }
    for(int i=0;i<=cnt+1;i++){
        if(!st.count(i)){
            // to binary
            int tmp=i,k=len;
            while(k--){
                cout<<((tmp>>k)&1);
            }
            return 0;
        }
    }
    return 0;
}