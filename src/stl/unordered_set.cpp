#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<int> uset = {1, 2, 3, 4, 5};

    // 插入元素
    uset.insert(6);
    uset.insert(3);  // 重复元素不会插入

    // 遍历输出
    for (const auto& val : uset) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
