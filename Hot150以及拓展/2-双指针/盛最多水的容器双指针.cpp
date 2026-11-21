/**
 * @file    solution.cpp
 * @brief   11. 盛最多水的容器 (Container With Most Water)
 * 
 * 给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
 * 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 * 返回容器可以储存的最大水量。
 * 说明：你不能倾斜容器。
 * 
 * 示例 1:
 *   输入: height = [1,8,6,2,5,4,8,3,7]
 *   输出: 49
 *   解释: 垂线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
 * 
 * 示例 2:
 *   输入: height = [1,1]
 *   输出: 1
 * 
 * 提示:
 *   - n == height.length
 *   - 2 <= n <= 10^5
 *   - 0 <= height[i] <= 10^4
 * 
 * @param   height  输入的高度数组
 * @return  int     容器可以储存的最大水量
 */
#include<bits/stdc++.h>
using namespace std;

int solve(const vector<int>& height)
{
    int n = height.size();
    //对撞指针
    int l = 0;
    int r = n-1;
    int max_water = 0;
    while(l<r)
    {
      int curr_water = min(height[l],height[r])*(r-l);
      max_water = max(curr_water,max_water);
      
     //数学推导:只移动短板 才有容积增大可能 else 则是进入了双板相等的情况 移动任意一边都行
      if(height[l]<height[r])
      {
        l++;
      }  
      else
      {
        r--;
      }
    }
    return max_water;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    
    while(cin>>n)
    {
     if(n==0)
     {
        cout<<0<<endl;
        continue;
     }
    vector<int> height(n);
    for(int i=0;i<n;i++)
    {
        cin>>height[i];
    }
    int res = solve(height);
    cout<<res<<endl;
    }
    return 0;
}