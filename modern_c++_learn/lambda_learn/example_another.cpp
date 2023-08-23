//
// Created by 田佳业 on 2023/8/16.
//
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int arr[4] = {4, 2, 3, 1};
    //对 a 数组中的元素进行升序排序
    sort(arr, arr + 4, [=](int x, int y) -> bool{ return x > y; } );
    for(int n : arr){
        cout << n << " ";
    }
    return 0;
}
