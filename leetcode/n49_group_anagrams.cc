#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (auto&& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            mp[key].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto& v : mp) {
            ans.emplace_back(v.second);
        }
        return ans;
    }
};

int main(int argc, char const* argv[]) {
    Solution s;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto results = s.groupAnagrams(strs);
    for (auto&& i : results) {
        for (auto&& s : i) {
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}
