//
// Created by LENOVO on 2023/7/11.
//
//trie树板子
#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 7;
int n;
string s;

struct Trie {
    int son[N][26], cnt, exist[N];

    void insert(const string &s) {
        int p = 0;
        for (char c: s) {
            int ch = c - 'a';
            if (!son[p][ch]) son[p][ch] = ++cnt;
            p = son[p][ch];
        }
        exist[p]++;
    }

    int find(const string &s) {
        int p = 0;
        for (char c: s) {
            int ch= c-'a';
            if(!son[p][ch]) return 0;
            p=son[p][ch];
        }
        return exist[p];
    }
}trie;
int main(){
    cin>>n;
    while(n--){
        cin>>s;
        int t=trie.find(s);
        if(t){
            cout<<s<<t<<endl;
        }
        else{
            cout<<"OK"<<endl;
        }
        //即便存在也要插入,更新计数器exist
        trie.insert(s);
    }
    return 0;
}

