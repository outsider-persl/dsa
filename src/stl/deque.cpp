#include <iostream>
#include <deque>

int main() {
    std::deque<int> deq = {1, 2, 3, 4, 5};

    // 在两端插入元素
    deq.push_front(0); // 在前端插入
    deq.push_back(6);  // 在后端插入

    // 遍历输出
    for (const auto& val : deq) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
