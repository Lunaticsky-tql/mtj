//
// Created by 田佳业 on 2023/4/15.
//
//还得做pa，是真没时间写了。。。
#include<bits/stdc++.h>
using namespace std;
deque<int> q;
int n,op,x;
int main(){
    cin>>n;
    for(int i=0;i<n;i++) {
        cin >> op;
        switch (op) {
            case 1:
                cin >> x;
                q.push_front(x);
                break;
            case 2:
                cin >> x;
                q.push_back(x);
                break;
            case 3:
                cout << q.front()<<endl;
                break;
            case 4:
                cout << q.back()<<endl;
                break;
            case 5:
                q.pop_front();
                break;
            case 6:
                q.pop_back();
                break;
            default:
                break;
        }
    }
    return 0;
}