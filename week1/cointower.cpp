//
// Created by 田佳业 on 2023/3/5.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define SIZE 40

map<pii, ll> ma;
ll coin[SIZE + 1] = {1};

ll get_gold(ll n, ll i) {
    ll qi = i;
    if (ma.count({n, i}))
        return ma[{n, i}];
    if (n == 0) {
        return ma[{n, i}] = 1;
    }
    ll ans = 0;
    i--;
    if (i > 0) {
        ll removeHeight = min(coin[n - 1], i);
        i -= removeHeight;
        ans += get_gold(n - 1, removeHeight);
    }
    if (i > 0) {
        ll removeHeight = min(n, i);
        i -= removeHeight;
        ans += removeHeight;
    }
    if (i > 0) {
        ll removeHeight = min(coin[n - 1], i);
        i -= removeHeight;
        ans += get_gold(n - 1, removeHeight);
    }
    i--;
    return ma[{n, qi}] = ans;
}


int main() {
    ll n, i;
    cin >> n >> i;
    for (ll j= 1; j <= n; j++) {
        coin[j] = 1 + coin[j - 1] + j + coin[j - 1] + 1;
    }
    if (i == 0) {
        cout<<0;
        return 0;
    }
    ll ans = get_gold(n, i);
    cout << ans;
    return 0;
}
