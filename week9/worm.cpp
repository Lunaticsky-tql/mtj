//
// Created by 田佳业 on 2023/4/30.
//
#include<bits/stdc++.h>
using namespace std;
const int mod=1e5+3;
const int N=1e5+3;
struct NODE{
    int val[6],next;
}worm[N];
int n,h[N],idx;
int Hash(const int *a){
    long long sum=0,pro=1;
    for(int i=0;i<6;i++){
        sum=(sum+a[i])%mod;
        pro=pro*a[i]%mod;
    }
    return (sum+pro)%mod;
}
bool equal(const int *a,const int *b){
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            bool flag=true;
            for(int k=0;k<6;k++){
                if(a[(i+k)%6]!=b[(j+k)%6])
                {
                    flag=false;
                    break;
                }
            }
            if(flag){
                return true;
            }
            flag=true;
            for(int k=0;k<6;k++){
                if(a[(i+k)%6]!=b[(j-k+6)%6]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                return true;
            }
        }
    }
    return false;
}

bool find(int *a){
    int k=Hash(a);
    for(int i=h[k];i!=-1;i=worm[i].next){
        if(equal(worm[i].val,a)){
            return true;
        }
    }
    return false;
}
void insert(int *a){
    int k=Hash(a);
    memcpy(worm[idx].val,a,6*sizeof(int));
    worm[idx].next=h[k];
    h[k]=idx;
    idx++;
}
int main(){
    memset(h,-1,sizeof(h));
    cin>>n;
    int a[6];
    while(n--){
        for(int & i : a){
            cin>>i;
        }
        if(find(a)){
            cout<<"found.";
            return 0;
        }
        else{
            insert(a);
        }
    }
    cout<<"No";
    return 0;
}