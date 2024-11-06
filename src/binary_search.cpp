#include <algorithm>
#include <iostream>

using namespace std;
// int* copy(int* source, int size, int start, int end) {
//     cout << "start :" << start << " end:" << end << endl;
//     int* target = new int[end - start];
//     int index = 0;
//     for (int i = start; i <= end; i++) {
//         cout << "copy :" << source[i] << endl;
//         target[index++] = source[i];
//     }
//     return target;
// }
bool binary_search(int* nums, int target, int left, int right) {
    if (left > right) {  // 边界条件
        cout << "notFound!" << endl;
        return false;
    }
    int mid = (left + right) / 2;
    if (nums[mid] == target) {
        cout << "find!" << endl;
        return true;
    }
    return nums[mid] < target ? binary_search(nums, target, mid + 1, right) : binary_search(nums, target, left, mid - 1);
}
bool search(int* nums, int size, int target) {
    return binary_search(nums, target, 0, size - 1);
}
void print(int* arrays, int len) {
    for (int i = 0; i < len; i++) {
        cout << arrays[i] << " ";
    }
}

int main(int argc, char const* argv[]) {
    int len = 13;
    int* nums = new int[13];
    // for range 0 to 10    {
    for (int i = 0; i < len; i++) {
        // random number between 0 and 100
        nums[i] = rand() % 100;
    }
    sort(nums, nums + len);

    print(nums, len);

    int target = rand() % 100;
    cout << endl;
    cout << target << endl;
    search(nums, len, target);

    return 0;
}
