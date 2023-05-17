//
// Created by 田佳业 on 2023/4/13.
//
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
bool tag[N];
string str;
stack<int> stk;
int main(){
    cin>>str;
    int len=str.length();
    for(int i=0;i<len;i++){
        if(str[i]=='('){
            stk.push(i);
        }
        else{
            // ')' is found
            if(!stk.empty()){
                tag[stk.top()]=true;
                tag[i]=true;
                stk.pop();
            }
            // if stk is empty, then the ')' is not matched
            // nothing to do
        }
    }
    // find the max length of the matched substring
    int max_len=0;
    int cur_len=0;
    int max_len_count=0;
    for(int i=0;i<len;i++){
        if(tag[i]){
            cur_len++;
        }
        else {
          if(cur_len>max_len){
              max_len=cur_len;
              max_len_count=1;
          }
          else if(cur_len==max_len){
              max_len_count++;
          }
            cur_len = 0;
        }
    }
    if(cur_len>max_len){
        max_len=cur_len;
        max_len_count=1;
    }
    else if(cur_len==max_len){
        max_len_count++;
    }
    if(max_len){
        cout<<max_len<<" "<<max_len_count;
    }
    else{
        cout<<0<<" "<<1;
    }
    return 0;
}