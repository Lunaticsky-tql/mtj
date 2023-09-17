//
// Created by 田佳业 on 2023/8/31.
//
//
// Created by 田佳业 on 2023/8/31.
//
#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int a[N]={1},b[N]={1},c[N]={1},d[N],tmp[N],sum[N]={3},n;

void clear(int *a){
    for(int i=0;i<N;i++){
        a[i]=0;
    }
}
void read(int *a){
    char s[N];
    scanf("%s",s);
    clear(a);
    int len=strlen(s);
    for(int i=0;i<len;i++){
        a[i]=s[len-i-1]-'0';
    }
}
void print(int *a){
    int len=N-1;
    while(len>0&&a[len]==0){
        len--;
    }
    for(int i=len;i>=0;i--){
        putchar(a[i]+'0');
    }
    putchar('\n');
}
void add(int *a,int *b,int *c){
    clear(c);
    for(int i=0;i<N-1;i++){
        c[i]+=a[i]+b[i];
        if(c[i]>=10){
            c[i+1]++;
            c[i]-=10;
        }
    }
}

void add(int *a,int *b){
    for(int i=0;i<N-1;i++){
        a[i]+=b[i];
        if(a[i]>=10){
            a[i+1]++;
            a[i]-=10;
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=4;i<=n;i++){
        add(a,b,tmp);
        add(tmp,c,d);
        memcpy(a,b,sizeof(b));
        memcpy(b,c,sizeof(c));
        memcpy(c,d,sizeof(d));
        memcpy(tmp,sum, sizeof(sum));
        add(sum,d);
    }
    print(sum);
    return 0;
}
