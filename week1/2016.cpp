//
// Created by 田佳业 on 2023/3/5.
// 数据流中的中位数，multiset
#include <iostream>
#include <set>
using namespace std;
int main()
{
    int n;
    cin>>n;
    multiset<int> a;
    multiset<int>::iterator left,right;
    for(int i=0;i<n;i++)
    {
        char type;
        cin>>type;
        if(type=='+')
        {
            int x;
            cin>>x;
            size_t size=a.size();
            a.insert(x);
            if(size==0)
            {
                left=a.begin();
                right=a.begin();
            }
            else if(size%2!=0)
            {
                if(x<*left)
                {
                    left--;
                }
                else
                {
                    right++;
                }
            }
            else
            {
                if(x>*left&&x<*right)
                {
                    left++;
                    right--;
                }
                else if(x>=*right)
                {
                    left++;
                }
                else
                {
                    right--;
                    left=right;
                }
            }
        }
        else if(type=='?')
        {
            double ans;
            ans=((double)*left+(double)*right)/2;
            cout<<ans<<endl;

        }
    }
    return 0;

}