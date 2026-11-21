#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums,int k)
{
    int n = nums.size();
    int count = 0 ;
    //第一层循环:枚举子数组的左端点(起始位置)
    for(int i = 0 ;i<n;++i)
    {
        int sum = 0 ; //记录以i为起点的子数组累加和
        //第二层循环:枚举子数组的右端点(结束位置)
        //从i开始向右延伸
        for(int j = i;j<n;++j)
        {
            sum+=nums[j]; //边走边累加 省去第三重循环
            //
            if(sum == k)
            {
                count++;
            }
        }
    }
    return count;
}