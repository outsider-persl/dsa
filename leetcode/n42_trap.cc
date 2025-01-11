#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3) return 0;
        int ans = 0;
        int n = height.size();
        vector<int> left_max(n, 0);
        vector<int> right_max(n, 0);

        // 计算每个位置的左边最大高度
        left_max[0] = height[0];
        for (int i = 1; i < n; ++i) {
            left_max[i] = max(left_max[i - 1], height[i]);
        }

        // 计算每个位置的右边最大高度
        right_max[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            right_max[i] = max(right_max[i + 1], height[i]);
        }

        // 计算每个位置能接的雨水量
        for (int i = 0; i < n; ++i) {
            ans += min(left_max[i], right_max[i]) - height[i];
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> height = {4, 2, 0, 3, 2, 5};
    int result = solution.trap(height);
    std::cout << "Total trapped water: " << result << std::endl;
    return 0;
}