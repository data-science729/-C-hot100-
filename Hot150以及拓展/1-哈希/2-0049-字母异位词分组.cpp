/**
 * 题目：字母异位词分组 (Group Anagrams)
 * 
 * 描述：
 * 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
 * 
 * 示例 1:
 * 输入: strs = ["eat", "tea", "tan", "ate", "eat", "bat"]
 * 输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
 * 解释:
 * - 在 strs 中没有字符串可以通过重新排列来形成 "bat"。
 * - 字符串 "nat" 和 "tan" 是字母异位词，因为它们可以重新排列以形成彼此。
 * - 字符串 "ate" ，"eat" 和 "tea" 是字母异位词，因为它们可以重新排列以形成彼此。
 * 
 * 示例 2:
 * 输入: strs = [""]
 * 输出: [[""]]
 * 
 * 示例 3:
 * 输入: strs = ["a"]
 * 输出: [["a"]]
 * 
 * 提示：
 * - 1 <= strs.length <= 10^4
 * - 0 <= strs[i].length <= 100
 * - strs[i] 仅包含小写字母
 */

 //观察发现：同类词 经过字母排序后 会变为完全一样的字符串
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

vector<vector<string>> groupanagrams(vector<string>& strs)
{
     unordered_map<string,vector<string>> mp;  //键是字符串标签，值是一个动态数组
     //遍历每一个单词
     for(string& s:strs)
     {
        string key = s;   //创建副本字符串叫key s留着备用 不在这折腾
        sort(key.begin(),key.end()); //排序，得到字母异位词的"特征暗号"
        mp[key].push_back(s); //将没有被动过的原单词s 放进key这个收纳组里
     }
    //把哈希表里的各个组装入数组
    vector<vector<string>> result;
    for(auto& pair: mp)
    {
        result.push_back(pair.second);
    }
    return result;
}

void printResult(const vector<vector<string>>& ans)
{
      cout << "[";
    for (int i = 0; i < ans.size(); i++) {
        cout << "[";
        for (int j = 0; j < ans[i].size(); j++) {
            cout << "\"" << ans[i][j] << "\"";
            if (j != ans[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "]";
        if (i != ans.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main()
{
    vector<string> strs1 = {"eat","ate","tea","tan","nat","bat"};
    vector<string> strs2 = {""};
    vector<string> strs3 = {"a"};
      // 分别测试并打印
    cout << "示例 1 输出: ";
    printResult(groupanagrams(strs1));
    cout << "示例 2 输出: ";
    printResult(groupanagrams(strs2));
    cout << "示例 3 输出: ";
    printResult(groupanagrams(strs3));
    return 0;
}
        
        
    
    


