//
// Created by 田佳业 on 2023/8/20.
//
#include<initializer_list>
#include<iostream>
using namespace std;
string func(initializer_list<string> li)
{
    string str;
    for(const auto & beg : li)
        str += beg;
    return str;
}

int main()
{
    cout << func({"This"," ","is"," ","C++"}) << endl;
    return 0;
}