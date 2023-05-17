//
// Created by 田佳业 on 2023/4/13.
//
//MT2115
//小码哥现在有一个字符集为 a|() 的字符串，他想要对这个字符串进行化简，具体规则如下：
//
//1。一个纯a串无法被化简：
//2。一个由|分隔的串，可以化简为!两侧较长的一个：如 a|aa 化简为 aa
//3。一个带有()的串，化简时先化简括号内的串。
#include<bits/stdc++.h>
using namespace std;
int handle(){
    int res=0;
    while(true) {
        char c = getchar();
        if (c == '\n' || c == EOF) {
            return res;
        }
        switch (c) {
            case 'a':
                res++;
                break;
            case '|':
                return max(res, handle());
            case '(':
                res += handle();
                break;
            case ')':
                return res;
            default:
                break;
        }
    }
}
int main(){
    cout<<handle();
}