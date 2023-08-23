//
// Created by LENOVO on 2023/7/11.
//
//码蹄集 五彩斑斓的串 题意:给定一组字符串,对于其中的一个字符串，如果存在某种字母表顺序，使得它在这nn个字符串中字典序最小，那这个字符串就是一个五彩斑斓的串。 找出所有五彩斑斓的串。
#include<bits/stdc++.h>
using namespace std;
const int N=3e5+7;
string s[N];
int n,ans[N],cnt;
struct Trie{
    int son[N][26],cnt;
    int m[26][26];
    vector<int> a,b;
    bool ed[N];
    void insert(string s){
        int p=0;
        for(char c:s){
            int ch=c-'a';
            if(!son[p][ch]) son[p][ch]=++cnt;
            p=son[p][ch];
        }
        ed[p]=true;
    }
    bool check(string s){
        //检查是否是五彩斑斓的串
        memset(m,0,sizeof(m));
        int p=0;
        for(char ch:s){
            int c=ch-'a';
            if(ed[p]) return false;
            for(int i=0;i<26;++i){
                if(son[p][i]&&m[c][i]>0&&i!=c){
                    return false;
                    //偏序关系矛盾
                }
            }
            //更新偏序关系a<c<i<b
            a.clear();
            b.clear();
            for(int i=0;i<26;i++){
                if(son[p][i]&&i!=c){
                    m[c][i]=-1;
                    m[i][c]=1;
                    //只有有兄弟节点才需要更新偏序关系
                    for(int j=0;j<26;j++){
                        //处理传递关系a<c, c<i => a<i
                        if(m[c][j]==1){
                            a.push_back(j);
                            m[i][j]=1;
                            m[j][i]=-1;
                        }
                        //处理传递关系c<i, i<b => c<b
                        if(m[i][j]==-1){
                            b.push_back(j);
                            m[c][j]=-1;
                            m[j][c]=1;
                        }

                    }
                }


            }
            //在更新完上面的偏序关系后,还需要更新a<b的传递关系,因为a<c, c<b => a<b
            for(int x:a){
                for(int y:b){
                    m[x][y]=-1;
                    m[y][x]=1;
                }
            }
            p=son[p][c];
        }
        //对于每个字符偏序关系都可以满足,则是五彩斑斓的串
        return true;
    }
}trie;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i];
        trie.insert(s[i]);
    }
    for(int i=0;i<n;i++){
        if(trie.check(s[i])){
            ans[cnt++]=i;
        }
    }
    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++){
        cout<<s[ans[i]]<<endl;
    }
    return 0;
}