//
// Created by 田佳业 on 2023/3/5.
//
//三合一
//https://matiji.net/exam/dohomework/2676/1
//vector 操作
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int i=1;
    int sum;
    while(true)
    {
        int j=0;
        while(j<a.size()-2)
        {
            sum=a[j]+a[j+1]+a[j+2];
            if(sum<=i*3)
            {
                a.erase(a.begin()+j,a.begin()+j+3);
                a.insert(a.begin()+j,sum);
                j++;
            }
            else
            {
                j++;
            }
            if(a.size()<=2)
            {
                cout<<i;
                return 0;
            }
        }
        i++;
    }

}
