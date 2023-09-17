//
// Created by 田佳业 on 2023/8/31.
//
#include<bits/stdc++.h>
using namespace std;
const int N=100;
int a[N]={1},b[N]={2},c[N];
int n;
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

void mul(int *a,int *b,int *c){
    clear(c);
    for(int i=0;i<N-1;i++){
        for(int j=0;j<=i;j++){
            c[i]+=a[j]*b[i-j];
        }
        if(c[i]>=10){
            c[i+1]+=c[i]/10;
            c[i]%=10;
        }
    }
}
int main(){
    scanf("%d",&n);
    while(n--){
        mul(a,b,c);
        memcpy(a,c,sizeof(c));
    }
    print(c);
    return 0;
}
