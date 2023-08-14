//
// Created by 田佳业 on 2023/8/13.
//
//有些无聊的一个题，练一下手速
#include<bits/stdc++.h>

using namespace std;
const int N=5e7+7;
int m, n;
char c,s[N];

int main() {
    cin >> n >> m >> s;
    while (m--) {
        cin >> c;
        switch (c) {
            case '+':
                for (int j = n - 1; j >= 0; j--) {
                    if (s[j] == '0') {
                        s[j] = '1';
                        break;
                    } else {
                        s[j] = '0';
                    }
                }
                break;
            case '-':
                for (int j = n - 1; j >= 0; j--) {
                    if (s[j] == '1') {
                        s[j] = '0';
                        break;
                    } else {
                        s[j] = '1';
                    }
                }
                break;
            case '*': {
                s[n] = '0';
                s[++n] = '\0';
                break;
            }
            case '/': {
                s[--n] = '\0';
                break;
            }
            default:
                break;
        }
    }
    cout<<s;
    return 0;
}