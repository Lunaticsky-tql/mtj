//
// Created by LENOVO on 2023/6/4.
//
//MT2154 异或和
//这个状态设计相对容易理解.观察数据范围,我们可以穷举异或和.每个异或和保存满足条件的序列中末尾数字最小的末尾数字,这样可以满足正确的找到所有满足条件的
//递增序列
#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 7;
const int A = 512;
int n, a[N], dp[A + 5];

int main() {
    memset(dp, 0x3f3f3f3f, sizeof(dp));
    dp[0] = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= A; j++) {
            if (dp[j] < a[i])
                dp[j ^ a[i]] = min(dp[j ^ a[i]], a[i]);
        }
    }
    vector<int> ans;
    for (int i = 0; i <=A; i++) {
        if (dp[i] != 0x3f3f3f3f) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for (int id: ans) {
        cout << id << " ";
    }
    return 0;
}