#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;

vector<int> twoSum(vector<int>& nums,int target)
{
    unordered_map<int,int> hash;
    for(int i=0;i<nums.size();i++)
    {
        int need = target - nums[i];  //想找的另一个数
        if(hash.find(need)!=hash.end())
        {
            return {hash[need],i} ; //找到了 返回  [之前的下标，当前的下标]
        }

        //没找到 把当前数和它的下标存进哈希表，方便后面的数字来查找
        hash[nums[i]] = i;
    }
    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> ans = twoSum(nums, target);

    cout << "哈希法找到的下标: [" << ans[0] << ", " << ans[1] << "]" << endl;
    return 0;
}
       
        
        
        
    


