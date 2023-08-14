//
// Created by 田佳业 on 2023/6/14.
//
//小码哥和小码妹是好朋友，他们有时会用一种方式检测双方的默契程度：两人分别给出一个字符串 ss 和 tt，并进行若干次操作使 ss 串变得和 tt 串一样。操作分为两种：
//1.删除 ss 串的第一个字符；
//2.将一个新字符插在 ss 串的第一个字符之前。
//
//如果可以用正好 nn 次操作使 ss 串变为 tt 串，就意味着他们两人很有默契，输出 YES，否则输出 NO。
#include<bits/stdc++.h>
using namespace std;
int n,cl,op;
string s,t;
int main(){
    cin>>n>>s>>t;
    reverse(s.begin(),s.end());
    reverse(t.begin(),t.end());
    for(cl=0;cl<min(s.length(),t.length());cl++){
        if(s[cl]!=t[cl]){
            break;
        }
    }
    op=s.length()+t.length()-2*cl;
    if(n>=op&&(n-op)%2==0){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}