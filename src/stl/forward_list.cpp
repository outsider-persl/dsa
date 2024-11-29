#include <forward_list>
#include <iostream>

int main() {
    std::forward_list<int> fl = {1, 2, 3, 4, 5};

    // 插入元素
    fl.push_front(0);  // 在前面插入
    // 遍历输出
    for (const auto& val : fl) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    return 0;
}
