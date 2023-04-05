//
// Created by 田佳业 on 2023/3/23
#include<iostream>
using namespace std;
int main()
{
    double t1,t2,x1,x2,t0;
    double y1,y2,t;
    double tmin=0x7fffffff,ans1,ans2;
    cin>>t1>>t2>>x1>>x2>>t0;
    y1=x1,y2=x2;
    while(y1>=0&&y2>=0)
    {
        t=(t1*y1+t2*y2)/(y1+y2);
        if(t>=t0)
        {
            // it is enough hot , try to make it more close to t0
            if(t<tmin)
            {
                tmin=t;
                ans1=y1;
                ans2=y2;
            }
            y2--;
        }
        else{
            // it is not enough hot, turn off the cold water
            y1--;
        }
    }
    cout<<ans1<<" "<<ans2;
    return 0;
}