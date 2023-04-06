#include <bits/stdc++.h>
using namespace std;
#define MAX 2000010
#define ll long long
ll n,m,mid,l,r;
ll a[MAX],b[MAX],sum[MAX];
ll check(ll x){
    for(ll i=1;i<=n;i++){
        b[i] = a[i]-x;
        sum[i] = sum[i-1]+b[i];
    }
    ll y=MAX;
    for(ll i=m;i<=n;i++){
        y=min(y,sum[i-m]);
        if(sum[i]-y>=0) return 1;
    }
    return 0;
}

int main(){
    scanf("%lld %lld",&n,&m);
    l=MAX,r=0;
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        a[i]*=1000;
        l=min(l,a[i]);
        r=max(r,a[i]);
    }

    while(l!=r){
        mid=(l+r+1)/2;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    printf("%lld\n",l);
    return 0;
}
