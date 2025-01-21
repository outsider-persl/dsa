#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {
   public:
    string minWindow(string s, string t) {
        vector<int> map(128, 0);
        int counter = t.length();
        int start = 0;
        int end = 0;
        int minStart = 0;
        int minLen = INT_MAX;
        for (char c : t) {
            map[c]++;
        }
        while (end < s.length()) {
            if (map[s[end]] > 0) {
                counter--;
            }
            map[s[end]]--;
            end++;
            while (counter == 0) {
                if (end - start < minLen) {
                    minStart = start;
                    minLen = end - start;
                }
                if (map[s[start]] == 0) {
                    counter++;
                }
                map[s[start]]++;
                start++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};
int main(int argc, char const *argv[]) {
    Solution s;
    auto res = s.minWindow("ADOBECODEBANC", "ABC");
    cout << res;

    return 0;
}
