//
// Created by 田佳业 on 2023/4/15.
//
//MT2115
//小码哥现在有一个字符集为 a|() 的字符串，他想要对这个字符串进行化简，具体规则如下：
//
//1。一个纯a串无法被化简：
//2。一个由|分隔的串，可以化简为!两侧较长的一个：如 a|aa 化简为 aa
//3。一个带有()的串，化简时先化简括号内的串。
#include<bits/stdc++.h>
using namespace std;
stack<char> s;
string str;
int tot,par;

int main(){
    cin>>str;
    int len=str.length();
    for(int i=0;i<len;i++){
        tot=par=0;
        if(str[i]!=')'){
            s.push(str[i]);
        }
        else{
            //we need to pop the stack until we meet '('
            while(s.top()!='('){
                if(s.top()=='a'){
                    par++;
                }
                else{
                    // we meet '|'
                    // compare the length of the two parts
                    tot=max(tot,par);
                    par=0;
                }
                //pop the 'a' or '|'
                s.pop();
            }
            // we meet '('
            //compare the last part
            tot=max(tot,par);
            //pop '('
            s.pop();
            //push the result
            while(tot--){
                s.push('a');
            }
        }
    }
    // now the str only have 'a' and '|'
    // got the max length of 'a' then finish the task
    tot=par=0;
    while(!s.empty()){
        if(s.top()=='a') {
            par++;
        }
        else{
            // we meet '|'
            tot=max(par,tot);
            par=0;
        }
        s.pop();
    }
    tot=max(tot,par);
    cout<<tot;
    return 0;
}