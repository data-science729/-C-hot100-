/*
 * =====================================================================================
 * 题目：实现前缀树 Trie (LeetCode 208 与 1804 终极合并版)
 * 
 * 【背景描述】
 * 前缀树（Trie，读音类似 "try"）是一种高效存储与检索字符串集合中键的树形数据结构。
 * 本题将「基础版（208题）」与「进阶计数/删除版（1804题）」融为一体，要求实现一个功能
 * 完备的高性能前缀树类，同时支持布尔判断、精确词频统计、前缀词频统计及单词删除操作。
 * 
 * 【需要实现的方法】
 * 
 * 1. Trie():
 *    - 初始化前缀树根节点。
 * 
 * 2. void insert(string word):
 *    - 向前缀树中插入一个字符串 word（允许重复插入）。
 * 
 * 3. bool search(string word): 【来自 208 题】
 *    - 如果字符串 word 存在于前缀树中，返回 true；否则返回 false。
 * 
 * 4. bool startsWith(string prefix): 【来自 208 题】
 *    - 如果此前已经插入的字符串中，至少有一个以 prefix 为前缀，返回 true；否则返回 false。
 * 
 * 5. int countWordsEqualTo(string word): 【来自 1804 题】
 *    - 返回前缀树中字符串精确等于 word 的实例个数。如果不存在，返回 0。
 * 
 * 6. int countWordsStartingWith(string prefix): 【来自 1804 题】
 *    - 返回前缀树中以前缀 prefix 开头的字符串总个数。如果不存在，返回 0。
 * 
 * 7. void erase(string word): 【来自 1804 题】
 *    - 从前缀树中移除一个字符串 word。
 *    - 注意：调用本方法时，保证 word 之前一定已被插入且当前存在于树中。
 * 
 * 【示例流程】
 * 1. trie = new Trie()
 * 2. trie.insert("apple")
 * 3. trie.insert("apple")
 * 4. trie.countWordsEqualTo("apple")      -> 返回 2
 * 5. trie.countWordsStartingWith("app")   -> 返回 2
 * 6. trie.search("apple")                -> 返回 true
 * 7. trie.startsWith("app")              -> 返回 true
 * 8. trie.erase("apple")                 -> 移除一个 "apple"
 * 9. trie.countWordsEqualTo("apple")      -> 返回 1
 * 10. trie.countWordsStartingWith("app")  -> 返回 1
 * 11. trie.erase("apple")                -> 再次移除一个 "apple"
 * 12. trie.countWordsStartingWith("app")  -> 返回 0
 * 13. trie.search("apple")               -> 返回 false
 * 14. trie.startsWith("app")             -> 返回 false
 * 
 * 【数据规模与约定】
 * - 1 <= word.length, prefix.length <= 2000
 * - word 和 prefix 均仅由小写英文字母 ('a' ~ 'z') 组成
 * - 各操作方法总调用次数累计不超过 3 * 10^4 次
 * =====================================================================================
 */

 #include<bits/stdc++.h>
 using namespace std;

//第一层:底层树节点
struct TrieNode
{
    TrieNode* children[26] ; //对应'a'-'z'的26条分支
    int pass; //经过该节点的单词数量
    int end; //以该节点为结尾的单词数量

    //构造函数初始化列表
    TrieNode() : pass(0), end(0)
    {
        for(int i = 0;i<26;++i)
        {
            children[i] = nullptr ;
        }
    }
};

//第二层:前缀树类封装
class Trie
{
private:
    TrieNode* root ;  //根节点指针(私有成员 保护数据安全)
    //辅助私有函数:递归自底向上释放内存 防止多组测试时内存泄露
    void clear(TrieNode* node)
    {
        if(!node)  return ;
        for(int i = 0 ;i<26;++i)
        {
            clear(node->children[i]);
        }
        delete node;
    }

public:
    Trie()  //1.构造函数 诞生整棵树的根节点
    {
    root = new TrieNode();
    }
    //2.析构函数 对象销毁时自动触发内存清理
    ~Trie()
    {
        clear(root);
    }
    // 3. 插入字符串（允许重复插入）
    void insert(const string& word)
    {
      TrieNode* cur = root ; //巡警指针 代替root去探路
      cur->pass++ ; //经过根节点的单词数+1
      for(char c:word)
      {
        int idx = c - 'a' ; //将小写字母索引映射到0-25
        if(cur->children[idx] == nullptr)
        {
            cur->children[idx] = new TrieNode(); //如果这条树枝还没有被建过，就开辟一个新节点
        }
        cur = cur->children[idx] ; //有路，直接借用公共前缀让指针指向下一个子节点
        cur->pass++;  //经过该节点的单词数+1
      }
      cur->end++; //单词的终点站 插入之后 end>0是区分这是一个完整单词 还是这只是别人单词的前缀的唯一凭据
    }

    // 4. 【208题】判断完整单词是否存在
    //方法:要判断一个单词word是否存在于树中 要满足两个条件
    //1.沿途所有字母的树枝都存在
    //2.走完最后一个字母后 该节点必须是某个单词的终点 
    bool search(const string& word)
    {
        TrieNode* cur = root;
        for(char c : word)
        {
            int idx = c - 'a' ;  //计算要走哪条树枝
            //碰壁 没有这个字母的树枝 说明单词绝对不存在
            if(cur->children[idx] == nullptr)
            {
                return false;
            }
            cur = cur->children[idx] ;
        }
        return cur->end > 0 ;
    }
            
        

    

    
     // 5. 【208题】判断是否存在以 prefix 为前缀的单词
    bool startsWith(const string& prefix)
    {
     TrieNode* cur = root ; 
     for(char c : prefix)
     {
        int idx = c - 'a' ;
        if(cur->children[idx] == nullptr)
        {
            return false;
        }
        cur = cur->children[idx] ;
     }
     return true ;  //和search 唯一的区别 "只要走到最后，不用判断end>0,而是直接返回true"
    }

    // 6. 【1804题】查询精确等于 word 的单词总数
    int countWordsEqualTo(const string& word)
    {
     TrieNode* cur = root ; 
     
      for(char c : word)
      {
        int idx = c - 'a' ;
        if(cur->children[idx] == nullptr)
        {
            return 0;
        }
        cur = cur ->children[idx] ;
    
      }
      return cur->end ; //直接把终点站记录的答案报上去
      
    }

    // 7. 【1804题】查询以前缀 prefix 开头的单词总数
    int countWordsStartingWith(const string& prefix)
    {
      TrieNode* cur = root ;
      for(char c : prefix)
      {
        int idx = c - 'a' ;
        if(cur->children[idx] ==nullptr)
        {
            return 0 ;
        }
        cur = cur->children[idx];
      }
      return cur->pass ;
    }
    // 8. 【1804题】移除一个单词（保证 word 存在）
    
    void erase(const string& word)
    {
      TrieNode* cur = root ; 
      //第一个鲁棒性检查(防误删)，如果这个单词在树中不存在 直接安全退出 不修改pass和end
      if(countWordsEqualTo(word) == 0)
      {
        return ; 
      }
      
      cur->pass--;  //确定删除 根节点的总次数确定先-1
      for(char c : word)
      {
        int idx = c - 'a';
        //探照灯机制:观察下一个节点的pass,如果下一个节点的pass已经是1，扣除后会变0、
        //此时意味着后面整根树枝全部是为这个单词开的废枝，必须物理铲除
        if(cur->children[idx]->pass ==1)
        {
            clear(cur->children[idx]); //释放整根子树内存
            cur->children[idx] = nullptr ; //指针打回nullptr
            return ;
        }
        cur = cur->children[idx] ;
        cur->pass -- ;
      }
      cur->end -- ;
    }
};

//第三层:ACM模式的main函数
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q ; // 操作指令的总条数
    while(cin>>q)
    {
        Trie trie ; 
        while(q--)
        {
            string op,arg;
            cin>>op>>arg;  //读入的指令名称和参数
            if(op == "insert")
            {
                trie.insert(arg);
            }
            else if (op == "search")
            {
                cout<<boolalpha<<trie.search(arg)<<'\n';
            }
            else if (op == "startsWith")
            {
                cout<<boolalpha<<trie.startsWith(arg)<<'\n';
            }
            else if (op == "countWordsEqualTo") {
                cout << trie.countWordsEqualTo(arg) << '\n';
            }
            else if (op == "countWordsStartingWith") {
                cout << trie.countWordsStartingWith(arg) << '\n';
            }
            else if (op == "erase") {
                trie.erase(arg);
            }
        }
    }
    return 0;
}
           
            
            








