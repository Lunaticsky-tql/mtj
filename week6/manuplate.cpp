//
// Created by 田佳业 on 2023/4/5.
//
#include<bits/stdc++.h>

using namespace std;
#define N 1007
int n, X, a[N], b[N];

int main() {
    cin >> n >> X;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    b[1] = a[1];
    for (int i = 2; i <= n; i++) {
        sort(a, a + i);
        b[i] = a[i];
        for (int j = 1; j < i; j++) {
            // optimized because when this condition is true
            // it means that the a[i] is already settled
            // a[j-2]+X<a[i]<a[j-1]-X
            // so we need not compare it to the farther elements
            // it can save 2ms on the OJ testcase
            if(a[i]<a[j-1])
            {
                break;
            }
            if (fabs(a[i] - a[j]) < X) {
                a[i] = a[j] + X;
                b[i] = a[i];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << b[i] << " ";
    }
    return 0;
}