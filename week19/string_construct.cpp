//
// Created by LENOVO on 2023/7/11.
//MT2176
//你有一个字符串t，它由n个字母组成。定义一个字符串s的子串为s[l…r]，表示从位置l到r构成的一个新的串。
//
//你的目标是构造一个字符串s，使得它的可能长度最小，要求s中存在k个位置i,可以找到k个以i为出发点的子串t。

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int n,k,pi[N];
string s;
void pmt(const string& s,int n){
    for(int i=1,j=0;i<n;i++){
        while(j&&s[i]!=s[j]) j=pi[j-1];
        if(s[i]==s[j]) j++;
        pi[i]=j;
    }
}

int main(){
    cin>>n>>k>>s;
    pmt(s,n);
    for(int i=0;i<k;i++){
        for(int j=0;j<n-pi[n-1];j++){
            cout<<s[j];
        }
    }
    for(int i=n-pi[n-1];i<n;i++){
        cout<<s[i];
    }
    return 0;
}