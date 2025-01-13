#include <vector>
#include <string>
#include <iostream>

class Solution {
public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        if (p.size() > s.size()) {
            return {};
        }

        std::vector<int> ans;
        std::vector<int> countP(26, 0);
        std::vector<int> countS(26, 0);

        // 初始化 p 的字符计数
        for (char c : p) {
            countP[c - 'a']++;
        }

        // 初始化 s 的前 p.size() 个字符的计数
        for (int i = 0; i < p.size(); i++) {
            countS[s[i] - 'a']++;
        }

        // 检查第一个窗口
        if (countS == countP) {
            ans.push_back(0);
        }

        // 滑动窗口
        for (int i = p.size(); i < s.size(); i++) {
            // 移除窗口最左边的字符
            countS[s[i - p.size()] - 'a']--;
            // 添加新字符到窗口
            countS[s[i] - 'a']++;

            // 检查当前窗口
            if (countS == countP) {
                ans.push_back(i - p.size() + 1);
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    std::string s = "cbaebabacd";
    std::string p = "abc";
    std::vector<int> result = solution.findAnagrams(s, p);

    std::cout << "异位词的起始索引: ";
    for (int index : result) {
        std::cout << index << " ";
    }
    std::cout << std::endl;

    return 0;
}