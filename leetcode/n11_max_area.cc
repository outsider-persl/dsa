#include <vector>
#include <iostream>

using namespace std;
class Solution {
   public:
    int maxArea(vector<int>& height) {
        auto max = 0;
        auto l = 0;
        auto r = height.size() - 1;
        while (l != r) {
            auto lor = height[l] < height[r];
            auto gap = r-l;
            auto curr = (lor ? height[l] : height[r]) * gap;
            if (lor) {
                l++;
            } else {
                r--;
            }
            if (curr > max) {
                max = curr;
            }
        }
        return max;
    }
};

int main(int argc, char const* argv[]) {
    Solution s;
    vector<int> nums = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    auto ans = s.maxArea(nums);
    cout << ans << "\n";
    return 0;
}
