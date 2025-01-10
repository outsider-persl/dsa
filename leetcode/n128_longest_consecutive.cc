#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        
        sort(nums.begin(), nums.end());
        int ans, current = 1; // ans: longestConsecutive current: current longestConsecutive
        int index = 0;

        while (index != nums.size() - 1) {
            auto equals = nums[index] == nums[index + 1];
            auto cons = nums[index] + 1 == nums[index + 1];   

            if (cons) {
                current++;
            }
            if ((!cons & !equals) || index == nums.size() - 2) {
                ans = current > ans ? current : ans;
                current = 1;
            }

            index++;
        }
        return ans;
    }
};
int main(int argc, char const* argv[]) {
    Solution s;
    vector<int> v = {1, 2, 0, 1};
    auto longest = s.longestConsecutive(v);
    cout << longest << "\n";
    return 0;
}
