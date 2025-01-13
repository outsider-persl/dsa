#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> charIndex;
        int maxLength = 0;
        int l = 0;

        for (int r = 0; r < s.size(); ++r) {
            if (charIndex.find(s[r]) != charIndex.end()) {
                // 如果字符 s[r] 已经在字典中，移动左指针到重复字符的下一个位置
                l = std::max(l, charIndex[s[r]] + 1);
            }
            // 更新字符 s[r] 的索引
            charIndex[s[r]] = r;
            // 更新最长不包含重复字符的子串的长度
            maxLength = std::max(maxLength, r - l + 1);
        }

        return maxLength;
    }
};
int main(int argc, char const *argv[]) {
    Solution s;
    int n = s.lengthOfLongestSubstring("tmmzuxt");
    std::cout << n;
    return 0;
}
