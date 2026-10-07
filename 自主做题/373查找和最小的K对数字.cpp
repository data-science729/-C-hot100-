/*
 * 373. 查找和最小的 K 对数字
 * 难度：中等
 * 
 * 给定两个以非递减顺序排列的整数数组 nums1 和 nums2，以及一个整数 k。
 * 定义一对值 (u, v)，其中第一个元素来自 nums1，第二个元素来自 nums2。
 * 请找到和最小的 k 个数对 (u1, v1), (u2, v2) ... (uk, vk)。
 * 
 * 示例 1:
 * 输入: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
 * 输出: [[1,2],[1,4],[1,6]]
 * 解释: 返回序列中的前 3 对数：
 *      [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
 * 
 * 示例 2:
 * 输入: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
 * 输出: [[1,1],[1,1]]
 * 解释: 返回序列中的前 2 对数：
 *      [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
 * 
 * 提示:
 * - 1 <= nums1.length, nums2.length <= 10^5
 * - -10^9 <= nums1[i], nums2[i] <= 10^9
 * - nums1 和 nums2 均为升序排列
 * - 1 <= k <= 10^4
 * - k <= nums1.length * nums2.length
 */

 //思路
#include<bits/stdc++.h>
using namespace std;

//1.定义堆节点结构体
struct Node
{
    int sum; //数对之和 nums1[i]+nums2[j]
    int i;  //nums1下标 赛道编号
    int j; //nums2下标 
    bool operator<(const Node& other) const{
        return sum>other.sum;
    }
    
};

vector<vector<int>> solve(const vector<int>& nums1,const vector<int>& nums2,int k)
{
  vector<vector<int>> ans;
  int n1 = nums1.size();
  int n2 = nums2.size();
  priority_queue<Node> pq; //凡是含有状态的STL容器，必须定义在函数内作为局部变量！！！
  //第一步:初始化 最多只要入队min(n1,k)条赛道里的第一个元素(j=0)
  //原因:超过k的赛道，其排头都比前面k条赛道的排头大，绝对不可能成为前k小
  int init_limit = min(n1,k);
  for(int i = 0 ;i<init_limit;i++)
  {
    pq.push({nums1[i]+nums2[0],i,0}); //三个参数 sum i j
  }
  //第二步 循环提取前k小
  //每次循环弹出一个全局最小值 最多弹k次 若堆提前空了也结束
  while(k-- >0 && !pq.empty())
  {
    Node cur = pq.top();
    pq.pop();
    //收集答案数对[nums1[cur.i],nums2[cur.j]]
    ans.push_back({nums1[cur.i],nums2[cur.j]});
    //第三步：后继补位 如果当前赛道后面还有元素(j+1<n2),就把下一个候选人放进堆
    if(cur.j+1<n2)
    {
        pq.push({nums1[cur.i]+nums2[cur.j+1],cur.i,cur.j+1});
    }
  }
  return ans;
}
  

  

 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n1,n2,k;
    while(cin>>n1>>n2>>k)
    {
        vector<int> nums1(n1);
        for(int i = 0;i<n1;i++)
        {
            cin>>nums1[i];
        }
        vector<int> nums2(n2);
        for(int i = 0;i<n2;i++)
        {
            cin>>nums2[i];
        }
        vector<vector<int>> ans = solve(nums1,nums2,k);
        
        cout<<"[";
        int total = ans.size();
        for(int i = 0 ;i<total;i++)
        {
            //打印每一对[u,v]
            cout<<"["<<ans[i][0]<<","<<ans[i][1]<<"]";
            //如果不是最后一对 中间用逗号隔开
            if(i+1<total)
            {
                cout<<",";
            }
        }
        cout<<"]"<<endl;
    }
    return 0 ;
}
        
        
    
    


