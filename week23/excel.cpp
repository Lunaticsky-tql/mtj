//
// Created by 田佳业 on 2023/8/27.
//
#include<bits/stdc++.h>

using namespace std;
string str;

void trans(bool mode) {
    //mode==true:RxCy
    int col = 0, row = 0;
    if (mode) {
        int R = str.find('R');
        int C = str.find('C');
        for (int i = R + 1; i < C; i++) {
            row = row * 10 + str[i] - '0';
        }
        for (int i = C + 1; i < str.length(); i++) {
            col = col * 10 + str[i] - '0';
        }
        string ans;
        while (col) {
            col--;
            ans.push_back(col % 26 + 'A');
            col /= 26;
        }
        reverse(ans.begin(), ans.end());
        cout << ans << row << endl;
    } else {
        for (char i: str) {
            if (!isdigit(i)) {
                col = col * 26 + i - 'A' + 1;
            } else
                row = row * 10 + i - '0';
        }
        cout << "R" << row << "C" << col << endl;
    }
}


int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> str;
        bool flag = false, mode = false;
        for (char c: str) {
            if (isdigit(c)) {
                flag = true;
            }
            if (flag && c == 'C') {
                mode = true;
                break;
            }
        }
        trans(mode);
    }
    return 0;
}