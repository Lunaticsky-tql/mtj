//
// Created by 田佳业 on 2023/8/27.
//
#include<bits/stdc++.h>
using namespace std;
int n,x,num[107];
bool flag;
int len;
int main(){
    cin>>n;
    while(n--){
        memset(num,0,sizeof(num));
        flag=false;
        len=0;
        scanf("%d",&x);
        if(x==0){
            printf("0\n");
            continue;
        }
        if(x<0){
            flag=true;
            x=-x;
        }
        while(x){
            num[len++]=x%3;
            x/=3;
        }
        for(int i=0;i<len;i++){
            if(num[i]==2){
                num[i]=-1;
                num[i+1]++;
            }else if(num[i]==3){
                num[i]=0;
                num[i+1]++;
            }
        }
        if(num[len]){
            len++;
        }
        if(flag){
            for(int i=0;i<len;i++){
                num[i]=-num[i];
            }
        }
        for(int i=len-1;i>=0;i--){
            if(num[i]==-1) {
                printf("-");
            }else{
                printf("%d",num[i]);
            }
        }
        printf("\n");
    }
    return 0;
}