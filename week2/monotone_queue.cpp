//
// Created by 田佳业 on 2023/3/12.
//
#include<bits/stdc++.h>
#include <deque>

using namespace std;
const int N=1e5+10;
int n,m,a[N],s[N],ans;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    deque<int> Q;
    for (int i = 1; i <= n; i++) {
        if (!Q.empty() && Q.front() < i - m+1)
            Q.pop_front();
        while (!Q.empty() && s[i] <= s[Q.back()])
            Q.pop_back();
        Q.push_back(i );
        ans = max(ans, s[i] - s[Q.front()]);
    }
    cout << ans;
    return 0;
}