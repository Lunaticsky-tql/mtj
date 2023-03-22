//
// Created by 田佳业 on 2023/3/5.
//
#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, a[100 + 10], b[100 + 10];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int sum;
        if (a[i] % 2 == 0)//偶数等分
            sum = a[i] * (a[i] + 2) * (2 * a[i] + 1) / 8;
        else
            sum = (a[i] + 1) * (2 * a[i] * a[i] + 3 * a[i] - 1) / 8;
        b[i] = sum;
    }
    for (int i = 0; i < n; i++)
        cout << b[i] << endl;

    return 0;
}
