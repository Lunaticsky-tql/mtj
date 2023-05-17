//
// Created by 田佳业 on 2023/4/5.
//
#include<bits/stdc++.h>

using namespace std;
deque<int> odd, even;
vector<bool> check;

int main() {
    int n;
    cin >> n;
    int x;
    while (n--) {
        cin >> x;
        if(x%2==0){
            even.push_back(x);
            check.push_back(true);
        }
        else{
            odd.push_back(x);
            check.push_back(false);
        }
    }
    sort(even.begin(),even.end());
    sort(odd.begin(),odd.end());
    for(auto && i : check){
        if(i){
            cout<<*even.begin()<<' ';
            even.pop_front();
        }
        else{
            cout<<*odd.begin()<<' ';
            odd.pop_front();
        }
    }
    return 0;
}