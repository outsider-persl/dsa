#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0, pre = 0;
        for (auto& x : nums) {
            pre += x;
            /**
             * nums[i] -k 的值，去mp里找，value就是0-i位置上所有关于nums[i]的子数组之和为k的结果
             */
            if (mp.find(pre - k) != mp.end()) {
                count += mp[pre - k];
            }
            mp[pre]++;
        }
        return count;
    }
};
int main(int argc, char const* argv[]) {
    Solution s;
    vector<int> nums = {-1, 0, 2, 1, 1, 0, 1, -3, 6, -2, 1};
    auto count = s.subarraySum(nums, 2);
    cout << count;
    return 0;
}
