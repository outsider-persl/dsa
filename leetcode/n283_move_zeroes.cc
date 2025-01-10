#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        int lastNonZeroFoundAt = 0;
        // 将所有非零元素移动到前面
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[lastNonZeroFoundAt++] = nums[i];
            }
        }
        // 将剩余的位置填充为0
        for (int i = lastNonZeroFoundAt; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};

int main(int argc, char const* argv[]) {
    Solution s;
    vector<int> nums = {1, 0, 1};
    s.moveZeroes(nums);
    for (auto&& i : nums) {
        cout << i << " ";
    }

    return 0;
}
