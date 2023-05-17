#include <iostream>
#include <algorithm>
#include<cmath>
using namespace std;

const int MAXN = 1e5 + 10;
struct node{
    int v,c;
    bool operator < (const node &a) const{
        if(c<a.c) return true;
        else if(c==a.c) return v<a.v;
        else return false;
    }
}a[MAXN];

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].v;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i].c;
    }
    sort(a+1,a+n+1);
//    for(int i=1;i<=n;i++){
//        cout<<a[i].v<<" "<<a[i].c<<endl;
//    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=abs(a[i].v-i);
    }
    cout<<ans;
    return 0;
}

