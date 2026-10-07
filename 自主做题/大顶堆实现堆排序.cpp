//为何升序排序必须用大顶堆？ 堆排序:原地排序 不用借助任何辅助数组
//大顶堆的堆顶nums[0]必然是当前堆里的全局最大值 
//我们直接把这个最大值和当前堆的末尾元素nums[i] 对调位置
//此时 全场最大的数 稳稳落在了数组的最后一位
//原始无序数组 ──(第一步：原地建大顶堆)──► 大顶堆 ──(第二步：反复调头下沉)──► 完美升序数组


#include<bits/stdc++.h>
using namespace std;

//大顶堆的下沉操作:在nums的前n个元素中 让下标为i的节点下沉
void sift_down(vector<int>& nums,int n,int i)
{
   while(2*i+1<n)
   {
    int left = 2*i+1;
    int right = 2*i+2;
    int largest = i ;  //大顶堆挑最大的
    if(left<n && nums[left]>nums[largest])
    {
        largest = left;
    }
    if(right<n && nums[right]>nums[largest])
    {
        largest = right ;
    }
    if(largest == i )
    {
        break ; //自己已经是最大的，满足大顶堆的性质
    }
    swap(nums[i],nums[largest]);
    i = largest;  //继续往下走
   }
}

//原地堆排序:时间复杂度O(NlogN) 空间复杂度O(1)

void heap_sort(vector<int>& nums)
{
    int n = nums.size();
    if(n<=1)  return ;
    //阶段1:自底向上建大顶堆 耗时O(N) Floyd建堆法
    //方法:找最后一个非叶子节点 因为长度为N的完全二叉树中 所有单独的叶子节点天生就是合法的1节点堆
    //阶段1:现在nums还是vector 要先变成大顶堆的样子，自底向上建大顶堆 耗时O(N)
    for(int i = n/2 -1;i>=0;i--)
    {
      sift_down(nums,n,i);
    }
    //阶段2:反复取堆顶的最大值甩到末尾 耗时O(NlogN) 反复把最大值放入安全的已排序区 剩下的下沉修复
    //这样 锁定第一最大值(最后，索引i=n-1)-->锁定第二最大值(i=n-2)... 到最后最小值被放在i=0,成功排序
    for(int i = n-1 ; i>0 ;i--)
    {
        swap(nums[0],nums[i]); //每轮循环 把当前最大值分别放到 n-1,n-2.... 慢慢形成从小到大排的升序数组
        sift_down(nums,i,0) ; //在缩小的堆范围[0,i) 内修复堆顶
    }
}
int main()
{
    // 测试用例
    vector<int> nums = {4, 10, 3, 5, 1, 2};
    
    heap_sort(nums);

    // 打印排序后的结果
    for (int x : nums)
    {
        cout << x << " ";
    }
    cout << endl; // 正确输出: 1 2 3 4 5 10
    
    return 0;
}