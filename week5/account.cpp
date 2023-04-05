//
// Created by 田佳业 on 2023/4/1.
//
#include<bits/stdc++.h>

using namespace std;
int n, m;
struct ACT {
    double c, w;
} account[1005];
double ans;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> account[i].c;
        account[i].w = 0;
    }
    int x, y;
    double z;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> z;
        if (account[x].c < z) {
            break;
        }
        account[x].c -= z;
        account[y].c+=floor(z);
        double t=z-floor(z);
        ans+=t;
        account[y].w+=t;
        if(account[y].w>1){
            break;
        }
    }
    cout<<fixed<<setprecision(2)<<ans;
    return 0;
}