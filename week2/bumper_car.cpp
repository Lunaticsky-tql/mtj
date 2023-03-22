//
// Created by 田佳业 on 2023/3/12.
//
#include<bits/stdc++.h>
using namespace std;
struct Car
{
    int id;
    int x;
    int f;
}car[1010];
bool compare_x(Car a,Car b)
{
    return a.x<=b.x;
}
bool compare_id(Car a,Car b)
{
    return a.id<b.id;
}
int main() {
    int n, t;
    int init_id[1010];
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> car[i].x >> car[i].f;
        car[i].id = i + 1;
    }
    sort(car, car + n, compare_x);
    for (int i = 0; i < n; i++)
    {
        init_id[i]=car[i].id;
        car[i].x=car[i].x+car[i].f*t;
    }
    sort(car,car+n,compare_x);
    for(int i=0;i<n;i++)
    {
        car[i].id=init_id[i];
        if(i>0&&car[i].x==car[i-1].x||i<n-1&&car[i].x==car[i+1].x)
        {
            car[i].f=0;
        }
    }
    sort(car,car+n,compare_id);
    for(int i=0;i<n;i++)
    {
        cout<<car[i].x<<" "<<car[i].f<<endl;
    }
    return 0;
}
