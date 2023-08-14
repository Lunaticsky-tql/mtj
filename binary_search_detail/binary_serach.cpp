//
// Created by 田佳业 on 2023/7/30.
//
#include<iostream>
#include<vector>
using namespace std;

int myLowerBound(vector<int> &data, int k)
{
    int start = 0;
    int last = data.size();
    while (start < last)
    {
        int mid = start + (last - start) / 2;
        if (data[mid] >= k)
        {
            last = mid;
        }
        else
        {
            start = mid + 1;
        }
    }
    return start;
}

int myUpperBound(vector<int> &data, int k)
{
    int start = 0;
    int last = data.size();
    while (start < last)
    {
        int mid = start + (last - start) / 2;
        if (data[mid] > k)
        {
            last = mid;
        }
        else
        {
            start = mid + 1;
        }
    }
    return start;
}
int binarySearch(vector<int> &nums, int target)
{
    // 二分查找，区间左闭右开
    int start = 0;
    int last = nums.size();
    while (start < last)
    {
        int mid =start+(last-start)/2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            last = mid;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}
int main(){
    vector<int> v={1,2,3,3,3,4,5,6,7,8,9};
    cout<<myLowerBound(v,3)<<endl;
    cout<<myUpperBound(v,3)<<endl;
    cout<<binarySearch(v,3)<<endl;
    vector<int> v2={1,2,3,4,5,6,7,8,9};
    cout<<binarySearch(v2,3)<<endl;
    return 0;
}