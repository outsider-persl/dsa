#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); i++) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                return {it->second, i};
            }
            // hashtable[nums[i]] = i;
            hashtable.insert({nums[i],i});
        }
        return {};
    }
};

int main(int argc, char const* argv[]) {
    Solution s;
    vector<int> nums = {-1, -2, -3, -4, -5};
    auto res = s.twoSum(nums, -8);
    cout << res.at(0) << " " << res.at(1) << endl;
    return 0;
}
