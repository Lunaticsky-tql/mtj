//
// Created by 田佳业 on 2023/4/5.
//
#include <iostream>
#include <algorithm>

using namespace std;

string newDict;

bool compare(char a, char b) {
    return newDict.find(a) < newDict.find(b); // 比较函数，按照新字典序进行排序
}

int main() {
    cin >> newDict;
    string str;
    cin>> str;
    sort(str.begin(), str.end(), compare);
    cout << str << endl;
    return 0;
}