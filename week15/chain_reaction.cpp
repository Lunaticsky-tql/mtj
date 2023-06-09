//
// Created by LENOVO on 2023/6/7.
//
// MT2162 连锁反应
// 小码哥在玩一个5x5的棋盘游戏，棋盘上有25个棋子，棋子有黑白两面，初始棋子无规则的正反放置在棋盘上，白用1表示，黑用0表示；
//
//每一次玩家可以改变一个棋子的正反，但是由于有连锁反应，这个棋子的上下左右4个棋子会跟着转变其正反，即0变1，1变0；
//
//小码哥想要知道需要多少步才能使棋盘上的棋子全部变为1；
//
//但是如果需要的步数超过6步（小码哥没有那么多耐心等你算出来），或者，没有办法使棋子全部变为1，你需要告诉小码哥。

//翻金币状态压缩，这个“注意到”还是有巧处的。我们只需要枚举第一行的操作，然后就可以确定整个棋盘的操作了。

#include<bits/stdc++.h>
using namespace std;
int n,ans;
char a[7][7],b[7][7];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
void flip(int x,int y){
    b[x][y]^=1;
    for(int i=0;i<4;i++){
        if(x+dx[i]>0&&x+dx[i]<=5&&y+dy[i]>0&&y+dy[i]<=5){
            b[x+dx[i]][y+dy[i]]^=1;
        }
    }
}
int main(){
    cin>>n;
    while(n--){
        ans=0x3f3f3f3f;
        for(int i=1;i<=5;i++){
            for(int j=1;j<=5;j++){
                cin>>a[i][j];
            }
        }
        for(int op=0;op<32;op++){
            int cnt=0;
            for(int i=1;i<=5;i++){
                for(int j=1;j<=5;j++){
                    b[i][j]=a[i][j];
                }
            }
            for(int i=0;i<5;i++){
                if(op&(1<<i)){
                    flip(1,i+1);
                    cnt++;
                }
            }
            for(int i=2;i<=5;i++){
                for(int j=1;j<=5;j++){
                    if(b[i-1][j]=='0'){
                        flip(i,j);
                        cnt++;
                    }
                }
            }
            //check if this a valid op
            bool flag=true;
            for(int i=1;i<=5;i++){
                if(b[5][i]=='0')
                {
                    flag=false;
                    break;
                }
            }
            if(flag){
                ans=min(ans,cnt);
            }
        }
        if(ans>6){
            cout<<"-1"<<endl;
        }
        else{
            cout<<ans<<endl;
        }
    }
    return 0;
}