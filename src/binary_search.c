#include <stdio.h>

int binary_search(int* nums, int target, int left, int right) {
    if (left > right) {  // 边界条件
        printf("NotFound\n");
        return -1;
    }
    int mid = (left + right) / 2;
    if (nums[mid] == target) {
        printf("Found %d\n", mid);
        return mid;
    }
    return nums[mid] < target ? binary_search(nums, target, mid + 1, right) : binary_search(nums, target, left, mid - 1);
}

int main(int argc, char const* argv[]) {
    int nums[] = {1, 3, 5, 9, 13, 25, 27};
    int size = sizeof(nums) / sizeof(nums[0]);
    printf("size: %d\n", size);
    int index = binary_search(nums, 9, 0, size - 1);
    return 0;
}
