//
// Created by 田佳业 on 2023/4/23.
//
//MT 2121 大约
#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 7;
int n, ans, a[N];
//max heap is default
priority_queue<int> maxH, maxDel;
priority_queue<int, vector<int>, greater<>> minH, minDel;

int main() {
    cin >> n;
    for (int i = 0, j = 0; i < n; i++) {
        cin >> a[i];
        maxH.push(a[i]);
        minH.push(a[i]);
        while (maxH.top() - minH.top() > 1) {
            // if the program reaches here, a[i] is whether the biggest or the smallest
            //in the priority queue
            // but we can not go back, so we try to use a[j] to balance
            //the substr
            // it should happen once or more, such as 1 1 2 3
            maxDel.push(a[j]);
            minDel.push(a[j]);
            j++;
            while (!maxDel.empty() && maxH.top() == maxDel.top()) {
                maxH.pop();
                maxDel.pop();
            }
            while (!minDel.empty() && minH.top() == minDel.top()) {
                minH.pop();
                minDel.pop();
            }
        }
        ans = max(ans, i - j + 1);
    }
    cout << ans;
    return 0;
}
