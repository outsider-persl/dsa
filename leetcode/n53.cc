#include <cstdio>
#include <vector>
using namespace std;
class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0;
        int ans = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            pre = max(pre + nums[i], nums[i]);
            ans = max(pre, ans);
        }
        return ans;
    }
};
int main(int argc, char const* argv[]) {
    Solution s;
    vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    auto res = s.maxSubArray(v);
    printf("%d", res);
    return 0;
}
