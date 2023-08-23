//
// Created by 田佳业 on 2023/6/15.
//
#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int v1[26],v2[26];
bool equal(const int *a,const int * b){
    for(int i=0;i<26;i++){
        if(a[i]!=b[i]){
            return false;
        }
    }
    return true;
}
int main(){
    cin>>s1>>s2;
    int l1=s1.length(),l2=s2.length();
    if(l1>l2){
        cout<<"false";
        return 0;
    }
    for(int i=0;i<l1;i++){
        v1[s1[i]-'a']++;
        v2[s2[i]-'a']++;
    }
    if(equal(v1,v2))
    {
        cout<<"true";
        return 0;
    }
    for(int i=l1;i<l2;i++){
        v2[s2[i-l1]-'a']--;
        v2[s2[i]-'a']++;
        if(equal(v1,v2)){
            cout<<"true";
            return 0;
        }
    }
    cout<<"false";
    return 0;


}