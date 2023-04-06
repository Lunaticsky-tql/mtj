//
// Created by LENOVO on 2023/3/12.
//
#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;
int m, n, a[N], s[N], ans = INT32_MIN;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
//    for(int i=1;i<=n;i++)
//    {
//        cout<<s[i]<<" ";
//    }
//    cout<<endl;
    deque<int> q;
    for (int i = 1; i <= n; i++) {
        if (!q.empty() && q.front() < i - m + 1)
            q.pop_front();
        while (!q.empty() && s[q.back()] > s[i])
            q.pop_back();
        q.push_back(i);
        ans = max(ans, s[i] - s[q.front()]);
        //look for elements in the queue
//        cout<<"queue elements are: ";
//        for(int & it : q) {
//            cout << it << " ";
//        }
//        cout<<endl;
//        cout<<"ans"<<" "<<ans;
//        cout<<endl;

    }
    cout << ans;
    return 0;

}