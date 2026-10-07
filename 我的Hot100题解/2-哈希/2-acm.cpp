#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    // ACM 风格核心：从标准输入 cin 读取数据，支持多组输入
    while (cin >> n) {
        vector<string> strs(n);
        for (int i = 0; i < n; i++) {
            cin >> strs[i];
        }

        // 核心处理逻辑（哈希表分组）
        unordered_map<string, vector<string>> mp;
        for (string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }

        // ACM 风格输出：直接 cout 打印，通常每组一行
        for (const auto& pair : mp) {
            for (int i = 0; i < pair.second.size(); i++) {
                cout << pair.second[i] << (i == pair.second.size() - 1 ? "" : " ");
            }
            cout << "\n";
        }
    }
}

int main() {
    // ACM 竞赛常用：加快 cin/cout 输入输出效率（防止大规模数据超时）
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}