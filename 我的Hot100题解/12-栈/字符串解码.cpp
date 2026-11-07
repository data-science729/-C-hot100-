// 394. 字符串解码
// 中等
//
// 相关标签
// 相关企业
//
// 给定一个经过编码的字符串，返回它解码后的字符串。
//
// 编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
//
// 你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
//
// 此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。
//
// 测试用例保证输出的长度不会超过 10^5。
//
// 示例 1：
//
// 输入：s = "3[a]2[bc]"
// 输出："aaabcbc"
//
// 示例 2：
//
// 输入：s = "3[a2[c]]"  -->必须先处理内层 再处理外层 面对嵌套结构 要存储暂时未知信息 适合用栈
// 输出："accaccacc"
//
// 示例 3：
//
// 输入：s = "2[abc]3[cd]ef"
// 输出："abcabccdcdcdef"
//
// 示例 4：
//
// 输入：s = "abc3[cd]xyz"
// 输出："abccdcdcdxyz"
//
// 提示：
//
// 1 <= s.length <= 30
// s 由小写英文字母、数字和方括号 '[]' 组成
// s 保证是一个 有效 的输入。
// s 中所有整数的取值范围为 [1, 300]
#include<bits/stdc++.h>
using namespace std;

//暂时保存:外层已经生成的字符串 外层对应的重复次数
//遇到右括号时 把内层计算结果取出 拼接到外层
//两个栈:每次遇到左括号 
//numstack:当前层需要重复多少次 strstack:当前层之前已经生成的字符串
//保存外层->处理内层->返回外层
string solve(string s)
{
    stack<int> numstack;
    stack<string> strstack;
    int num;  //当前解析的数字
    string cur = ""; //当前正在构造的字符串
    for(int i = 0;i<s.size();i++)
    {
        //1.遇到数字 可能是多位数
        if(isdigit(s[i]))  
        {
          //十进制数的逐位构造
          num = num*10 +(s[i] - '0');  //数字字符-'0' = 对应的整数
        }
        //2.遇到左括号 保存当前层的信息
        else if(s[i] == '[')
        {
            numstack.push(num);
            strstack.push(cur);
            //开始处理新的一层
            num = 0;
            cur = "";
        }
        //3.遇到右括号 完成当前层的解码
        else if(s[i] == ']')
        {
            int k  = numstack.top();
            numstack.pop();
            string prev = strstack.top();
            strstack.pop();
            //按题目规则:解码将字符串重复k次
            for(int j = 0 ;j<k ; j++)
            {
                prev += cur;
            }
            //返回上一层
            cur = prev;
        }
        //4.遇到普通字符 直接追加
        else 
        {
            cur += s[i];
        }
    }
    return cur;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    while(cin>>s)
    {
        cout<<solve(s)<<'\n';
    }
    return 0;
}