//
// Created by LENOVO on 2023/6/7.
//
//MT2161 数位dp板子
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 11;
ll f[N][10];

//f[i][j] stands for single digit sum of i digits and the first digit is j
// for example f[3][5] stands for single digit sum of 1-599
// that is 1+2+3...+(1+0)+(1+1)+(1+2)+(1+3)+(1+4)+(1+5)+...+(5+9+9)
void init() {
    for (int i = 1; i < N; i++) {
        f[i][0] = f[i - 1][9];
        for (int j = 1; j <= 9; j++) {
            // eg: 1-7999=7*1000+1-6999+1-999
            f[i][j] = j * pow(10, i - 1) + f[i][j - 1] + f[i - 1][9];
        }
    }
}

ll dp(int x) {
    vector<int> num;
    int x1 = x;
    while (x1) {
        num.push_back(x1 % 10);
        x1 /= 10;
    }
    ll res = 0;
    for (int i = num.size() - 1; i >= 0; i--) {
        int t = num[i];
        if (!t) {
            continue;
        }
        res+=f[i+1][t-1]+(x%int(pow(10,i))+1)*t;
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    init();
    cout<<dp(n);
    return 0;
}