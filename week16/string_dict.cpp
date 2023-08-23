//
// Created by 田佳业 on 2023/6/14.
//
// MT2167 拼写检测
#include<bits/stdc++.h>

using namespace std;
int n;
const int N = 1e5 + 7;
string dict[N];
string t;

int diff(const string &s, const string &tt) {
    if (s == tt) {
        return 0;
    }
    int i = 0, j = 0;
    int sl = s.length(), tl = tt.length();
    if(sl!=tl+1){
        return 2;
    }
    int differ=0;
    while (i < sl && j < tl) {
        if (s[i] == tt[j]) {
            i++;
            j++;
        } else {
            i++;
            differ++;
        }
    }
    if(i!=sl){
        differ++;
    }
    return differ;

}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> dict[i];
    }
    vector<string> v;
    cin >> t;
    for (int i = 0; i < n; i++) {
        int res=diff(t, dict[i]);
        if (res== 0)
        {
            cout<<0;
            return 0;
        }
        else if(res==1){
            v.emplace_back(dict[i]);
        }
    }
    if(v.empty()){
        cout<<-1;
        return 0;
    }
    sort(v.begin(),v.end());
    cout<<v.size()<<endl;
    for(auto &s:v){
        cout<<s<<endl;
    }
    return 0;

}