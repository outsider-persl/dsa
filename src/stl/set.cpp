#include <iostream>
#include <set>

int main() {
    std::set<int> s = {1, 2, 3, 4, 5};

    // 插入元素（重复元素会被自动去除）
    s.insert(3); // 插入重复元素不会有任何效果
    s.insert(6);

    // 遍历输出
    for (const auto& val : s) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
